/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:01:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/04 23:37:22 by tlandema         ###   ########.fr       */
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

char		**ft_create_environ(char **envp)
{
	char	**environ;
	int		i;

	i = 0;
	environ = NULL;
	if (envp[0])
	{
		environ = (char **)ft_memalloc(sizeof(char *) * ft_count_tab(envp));
		while (envp[i])
		{
			environ[i] = ft_strdup(envp[i]);
			i++;
		}
	}
	else
		environ = ft_fill_environ(environ);
	return (environ);
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

void		ft_add_env(t_env *envir, char *left, char *right, int i)
{
	char **tmp;
	char *str_tmp;

	if (!left || !right)
		return ;
	str_tmp = ft_strnew(ft_strlen(left) + ft_strlen(right));
	tmp = copy_tab(envir);
	ft_tabdel(ft_count_tab(envir->env), &envir->env);
	envir->env = (char **)ft_memalloc(sizeof(char *) * (ft_count_tab(tmp) + 2));
	while (tmp[i])
	{
		envir->env[i] = ft_strdup(tmp[i]);
		i++;
	}
	ft_strcpy(str_tmp, left);
	ft_strcat(str_tmp, "=");
	ft_strcat(str_tmp, right);
	envir->env[i] = ft_strdup(str_tmp);
	i++;
	free(str_tmp);
	ft_tabdel(ft_count_tab(tmp), &tmp);
}
