/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 01:52:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/06 08:59:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

static void	ft_check_and_exec(char **com_arg, char **paths, t_env *envir)
{
	int i;
	char *str;

	i = 0;
	if (access(com_arg[0], X_OK) == 0)
	{
		if (fork() == 0)
			execve(com_arg[0], com_arg, envir->env);
		else
			wait(NULL);
	}
	while (paths[i])
	{
		str = ft_strnew(PATH_MAX);
		ft_strcpy(str, paths[i]);
		ft_strcat(str, "/");
		ft_strcat(str, com_arg[0]);
		if (access(str, X_OK) == 0)
		{
			if (fork() == 0)
				execve(str, com_arg, envir->env);
			else
				wait(NULL);
		}
		free(str);
		i++;
	}
}

void		ft_command_parsing(t_env *envir, char **tab)
{
	int i;
	char *paths_str;
	char *paths_tmp;
	char **paths;

	i = 0;
	while (envir->env[i]
			&& !(envir->env[i][0] == 'P' && envir->env[i][1] == 'A'
				&& envir->env[i][2] == 'T' && envir->env[i][3] == 'H'
				&& envir->env[i][4] == '='))
		i++;
	if (envir->env[i])
	{
		paths_tmp = ft_strdup(envir->env[i]);
		paths_str = &ft_strchr(paths_tmp, '=')[1];
		paths = ft_strsplit(paths_str, ':');
		ft_check_and_exec(tab, paths, envir);
		ft_tabdel(ft_count_tab(paths), &paths);
		free(paths_tmp);
	}
}
