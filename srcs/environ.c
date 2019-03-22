/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environ.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 18:01:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/22 15:59:53 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void		ft_unset_helper(char *str, char *str_tmp)
{
	ft_strclr(str_tmp);
	free(str_tmp);
	str_tmp = NULL;
	ft_strclr(str);
	str = NULL;
}

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

t_env		*ft_create_environ(char **envp, char **argv)
{
	int		i;
	int		tab_size;
	t_env	*envir;

	i = 0;
	argv = NULL;
	envir = (t_env *)ft_memalloc(sizeof(t_env));
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
	envir->cat = 0;
	envir->old_pwd = ft_strnew(PATH_MAX);
	envir->old_pwd = getcwd(envir->old_pwd, PATH_MAX);
	envir->tmp_pwd = ft_strnew(PATH_MAX);
	return (envir);
}

int			ft_check_env(t_env *envir, char *check)
{
	int		i;
	int		j;
	int		k;
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
