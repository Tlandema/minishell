/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:01:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/18 10:39:30 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

static char	**ft_fill_environ(char **environ)
{
	char *buff;
	char *tmp;

	buff = ft_strnew(PATH_MAX);
	buff = getcwd(buff, PATH_MAX);
	environ = (char **)ft_memalloc(sizeof(char *) * 10);
	environ[0] = ft_strjoin("PWD=", buff);
	ft_strclr(buff);
	ft_strcpy(buff, ":/usr/sbin:/sbin:/usr/local/bin:/usr/local/munki");
	environ[1] = ft_strdup("HOME=/Users/tlandema");
	tmp = ft_strdup("PATH=/Users/tlandema/.brew/bin:/usr/bin:/bin");
	environ[2] = ft_strjoin(tmp, buff);
	free(tmp);
	free(buff);
	return (environ);
}

void		ft_create_environ(char **envp, t_env *envir)
{
	int		i;
	int		tab_size;

	i = 0;
	if (envp[0])
	{
		tab_size = ft_count_tab(envp);
		envir->env = (char **)ft_memalloc(sizeof(char *) * ((tab_size + 1)));
		while (envp[i])
		{
			envir->env[i] = ft_strdup(envp[i]);
			i++;
		}
	}
	else
		envir->env = ft_fill_environ(envir->env);
	envir->old_pwd = ft_strnew(PATH_MAX);
	envir->old_pwd = getcwd(envir->old_pwd, PATH_MAX);
	envir->tmp_pwd = ft_strnew(PATH_MAX);
}

int			ft_check_env(t_env *envir, char *check)
{
	int		i;
	int		j;
	int 	k;
	char	*copy;

	i = 0;
	j = 0;
	k = 0;
	while (envir->env[i])
	{
		copy = ft_strdup(envir->env[i]);
		if (ft_strequ(ft_strrev(&ft_strchr(ft_strrev(copy), '=')[1]), check))
			k = 1;
		ft_strclr(copy);
		free(copy);
		copy = NULL;
		i++;
	}
	return (k);
}

char		**copy_tab(t_env *envir)
{
	int		i;
	char	**copy;

	i = ft_count_tab(envir->env);
	copy = (char **)ft_memalloc(sizeof(char *) * (i + 1));
	i = 0;
	while (envir->env[i])
	{
		copy[i] = ft_strdup(envir->env[i]);
		i++;
	}
	copy[i] = NULL;
	return (copy);
}
