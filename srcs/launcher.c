/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:08:04 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/22 10:57:51 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <signal.h>
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

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
	if (ft_strequ(&ft_strrchr(getcwd(path, PATH_MAX), '/')[1], "tlandema"))
		ft_putstr("~");
	else
		ft_putstr(&ft_strrchr(getcwd(path, PATH_MAX), '/')[1]);
	ft_putstr("\033[39;49m) ");
	if (ft_strstr(path, "/") && !ft_strequ(path, "/"))
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
		ft_print_prompt(1);
	}
	return ;
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
		if (envir->cat == 0)
			ft_print_prompt(envir->r_o_g);
		envir->r_o_g = 0;
		envir->cat = 0;
		get_next_instruction(&str);
		if ((tab_f = ft_strsplit(str, ';')))
		{
			while (tab_f[argc])
			{
				tab = ft_split_white(tab_f[argc]);
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
