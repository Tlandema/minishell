/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:08:04 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/04 23:35:37 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

static void	ft_print_prompt(void)
{
	char *path;

	path = ft_strnew(PATH_MAX);
	ft_putstr("mynishell (\033[96m");
	ft_putstr(&ft_strrchr(getcwd(path, PATH_MAX), '/')[1]);
	ft_putstr("\033[39;49m) ");
	free(path);
}

static void		ft_parsing(char **tab, t_env *envir)
{
	int i;

	i = 0;
	if (tab)
	{
		if (ft_strequ(tab[0], "cd"))
			ft_cd_builtin(tab);
		else if (ft_strequ(tab[0], "exit"))
			exit(0);//dans le builtin de exit tu freera tout avant de exit;
		else if (ft_strequ(tab[0], "clear"))//le clear tu doit allez le chercher dan le bin donc enleve le un jour.
			ft_putstr("\e[1;1H\e[2J");
		else if (ft_strequ(tab[0], "env"))//tu dois gérer tout les parametres possible
			while (envir->env[i])
			{
				ft_putstr(envir->env[i++]);
				ft_putchar('\n');
			}
		else if (ft_strequ(tab[0], "setenv"))
			ft_add_env(envir, tab[1], tab[2], 0);
	}
}

int			main(int argc, char **argv, char **envp)
{
	char	*str;
	char	**tab;
	t_env	*envir;

	argc = 0;
	argv = NULL;
	envir = (t_env *)ft_memalloc(sizeof(t_env));
	envir->env = ft_create_environ(envp);
	while (1)
	{
		ft_print_prompt();
		get_next_instruction(&str);//ca malloc cette merde donc free STR stp;
		tab = ft_strsplit(str, ' ');//ca aussi ca malloc alors free TAB stp;
		ft_parsing(tab, envir);
		free(str);
		str = NULL;
		ft_tabdel(ft_count_tab(tab), &tab);
	}
}
