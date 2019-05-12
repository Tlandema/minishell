/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:08:04 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/12 21:13:56 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"

static void	ft_print_prompt(int r_o_g)
{
	char *path;

	path = ft_strnew(PATH_MAX);
	if (r_o_g)
		ft_putstr("\033[91m");
	else
		ft_putstr("\033[92m");
	ft_putstr("Tsh ");
	ft_putstr("\033[39m(\033[96m");
	if (ft_strequ(getcwd(path, PATH_MAX), "/Users/tlandema"))
		ft_putstr("~");
	else
		ft_putstr(&ft_strrchr(getcwd(path, PATH_MAX), '/')[1]);
	ft_putstr("\033[39;49m) ");
	if (ft_strstr(path, "/") && !ft_strequ(path, "/"))
		ft_print_git(path);
	free(path);
}

static void	ft_parsing(char **tab_f, char **tab, t_env *envir, char *str)
{
	if (tab)
	{
		if (ft_strequ(tab[0], "cd"))
			ft_cd_builtin(tab, envir);
		else if (ft_strequ(tab[0], "exit"))
		{
			ft_free(tab_f, tab, envir, str);
			exit(0);
		}
		else if (ft_strequ(tab[0], "env"))
			ft_env_builtin(envir, tab);
		else if (ft_strequ(tab[0], "setenv"))
			ft_setenv_builtin(envir, tab[1], tab[2], 0);
		else if (ft_strequ(tab[0], "unsetenv"))
			ft_unsetenv_builtin(envir, tab[1]);
		else if (ft_strequ(tab[0], "echo"))
			ft_echo_builtin(envir, tab);
		else
			ft_command_parsing(envir, tab);
		ft_tabdel(ft_count_tab(tab), &tab);
		return ;
	}
}

void		signalhandler(int sig_num)
{
	int i;

	i = 0;
	if (sig_num == 2)
	{
		ft_putchar('\n');
		while (i++ < col_number())
			tputs(tgetstr("le", NULL), 0, ft_printest);
		ft_print_prompt(1);
	}
	return ;
}

static int	main_helper(t_env *envir, int argc, char **str)
{
	*str = ft_strnew(PATH_MAX);
	argc = 0;
	if (envir->cat == 0)
		ft_print_prompt(envir->r_o_g);
	envir->r_o_g = 0;
	envir->cat = 0;
	ft_init_term();
	ft_loop(str);
	ft_reset_term();
	return (argc);
}

int			main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**tab;
	char	**tab_f;
	t_env	*envir;

	envir = ft_create_environ(envp, argv);
	signal(SIGINT, signalhandler);
	while (1)
	{
		argc = main_helper(envir, argc, &str);
		if ((tab_f = ft_strsplit(str, ';')))
		{
			while (tab_f[argc])
			{
				envir->r_o_g = 0;
				tab = ft_the_tab(tab_f[argc]);
				if (tab)
					ft_parsing(tab_f, tab, envir, str);
				argc++;
			}
			ft_tabdel(ft_count_tab(tab_f), &tab_f);
		}
		ft_strdel(&str);
	}
}
