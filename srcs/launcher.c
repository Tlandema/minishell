/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:08:04 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/18 13:39:04 by tlandema         ###   ########.fr       */
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
	free(path);
}

static void	ft_parsing(char **tab, t_env *envir)
{
	if (tab)
	{
		if (ft_strequ(tab[0], "cd"))
			ft_cd_builtin(tab, envir);
		else if (ft_strequ(tab[0], "exit"))
			exit(0);//dans le builtin de exit tu freera tout avant de exit;
		else if (ft_strequ(tab[0], "env"))//tu dois gérer tout les parametres possible
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

void		signalhandler(int sig_num)
{
	ft_putnbr(sig_num);
	ft_putstr("ca marche");
}

int			main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**tab;
	t_env	*envir;

	argc = 0;
	argv = NULL;
	envir = (t_env *)ft_memalloc(sizeof(t_env));
	ft_create_environ(envp, envir);
	while (1)
	{
		ft_print_prompt();
		get_next_instruction(&str);//ca malloc cette merde donc free STR stp;
		tab = ft_strsplit(str, ' ');//ca aussi ca malloc alors free TAB stp;
		if (tab)
			ft_parsing(tab, envir);
		free(str);
		str = NULL;
		if (tab)
		ft_tabdel(ft_count_tab(tab), &tab);
	}
}
