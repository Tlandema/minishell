/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:08:04 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/20 18:28:44 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <signal.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

static void	ft_print_prompt(void)
{
	char *path;

	path = ft_strnew(PATH_MAX);
	ft_putstr("TomTomshell (\033[96m");
	if (ft_strequ(&ft_strrchr(getcwd(path, PATH_MAX), '/')[1], "tlandema"))
		ft_putstr("~");
	else
		ft_putstr(&ft_strrchr(getcwd(path, PATH_MAX), '/')[1]);
	ft_putstr("\033[39;49m) ");
	ft_print_git(path);
	free(path);
}

static void	ft_parsing(char **tab, t_env *envir)
{
	if (tab)
	{
		if (ft_strequ(tab[0], "cd"))
			ft_cd_builtin(tab, envir);
		else if (ft_strequ(tab[0], "exit"))
			exit(0);
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
		return ;
	}
}

static void	signalhandler(int sig_num)
{
	if (sig_num == 2)
	{
		ft_putchar('\n');
		ft_print_prompt();
	}
}

int			main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**tab;
	char	**tab_f;
	t_env	*envir;

	argc = 0;
	argv = NULL;
	envir = (t_env *)ft_memalloc(sizeof(t_env));
	ft_create_environ(envp, envir);
	signal(SIGINT, signalhandler);
	while (1)
	{
		if (envir->test == 0)
			ft_print_prompt();
		get_next_instruction(&str);
		if ((tab_f = ft_strsplit(str, ';')))
		{
			while (tab_f[argc])
			{
				tab = ft_split_white(tab_f[argc]);
				envir->test = 0;
				if (tab)
					ft_parsing(tab, envir);
				if (tab)
					ft_tabdel(ft_count_tab(tab), &tab);
				argc++;
			}
			argc = 0;
			ft_tabdel(ft_count_tab(tab_f), &tab_f);
		}
			ft_strdel(&str);
	}
}
