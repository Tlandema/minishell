/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:17:59 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/03 17:44:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_path_former(char *path, char *arg)
{
	char	*buff;

	if (!(buff = ft_strnew(PATH_MAX)))
		return (NULL);
	ft_strcpy(buff, path);
	ft_strcat(buff, "/");
	ft_strcat(buff, arg);
	return (buff);
}

static int	ft_exec_helper(char **com_arg, char **paths, int i)
{
	char	*str;
	int		check;

	check = 0;
	while (paths[++i])
	{
		str = ft_path_former(paths[i], com_arg[0]);
		if (!access(str, F_OK) && access(str, X_OK) == -1)
			return (ft_smallest_free(str, 10));
		if (!(check = access(str, X_OK)))
		{
			if (fork() == 0)
				execve(str, com_arg, g_env->v_env);
			else
			{
				wait(0);
				if (g_env->cat == 1)
					ft_print_prompt();
			}
			return (ft_smallest_free(str, check));
		}
		ft_strdel(&str);
	}
	return (check);
}

static int	ft_check_and_exec(char **com_arg, char **paths)
{
	int		check;
	int		ok;

	ok = 0;
	if (!access(com_arg[0], F_OK) && access(com_arg[0], X_OK) == -1)
		return (10);
	if ((check = access(com_arg[0], X_OK)) == 0)
	{
		ok = 1;
		if (fork() == 0)
			execve(com_arg[0], com_arg, g_env->v_env);
		else
			wait(0);
	}
	if (paths && !ok)
		check = ft_exec_helper(com_arg, paths, -1);
	if (check == -1)
		check = 4;
	return (check);
}

static int	env_num(char *var)
{
	char	*var_t;
	char	**tmp_tab;
	int		i;

	tmp_tab = copy_tab();
	i = 0;
	while (tmp_tab[i])
	{
		var_t = ft_strdup(ft_strrev(&ft_strchr(ft_strrev(tmp_tab[i]), '=')[1]));
		if (ft_strequ(var, var_t))
		{
			ft_strdel(&var_t);
			ft_tabdel(ft_count_tab(tmp_tab), &tmp_tab);
			return (i);
		}
		ft_strdel(&var_t);
		i++;
	}
	ft_tabdel(ft_count_tab(tmp_tab), &tmp_tab);
	return (i);
}

void		ft_command_parsing(char **tab)
{
	char	*paths_str;
	char	*paths_tmp;
	char	**paths;
	int		check;

	paths = NULL;
	if (ft_strequ("cat", tab[0]) && tab[1] == NULL)
		g_env->cat = 1;
	if (g_env->v_env[env_num("PATH")])
	{
		paths_tmp = ft_strdup(g_env->v_env[env_num("PATH")]);
		paths_str = &ft_strchr(paths_tmp, '=')[1];
		paths = ft_strsplit(paths_str, ':');
		ft_strdel(&paths_tmp);
	}
	if ((check = ft_check_and_exec(tab, paths)) != 0)
		ft_puterror(check, tab[0]);
	if (g_env->v_env[env_num("PATH")])
		ft_tabdel(ft_count_tab(paths), &paths);
}
