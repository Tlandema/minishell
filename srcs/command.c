/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 01:52:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/12 04:56:19 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"

static char	*ft_path_former(char *path, char *arg)
{
	char	*buff;

	buff = ft_strnew(PATH_MAX);
	ft_strcpy(buff, path);
	ft_strcat(buff, "/");
	ft_strcat(buff, arg);
	return (buff);
}

static int	ft_exec_helper(char **com_arg, char **paths, t_env *envir)
{
	int		check;
	char	*str;
	int		i;

	i = 0;
	while (paths[i])
	{
		str = ft_path_former(paths[i], com_arg[0]);
		if (!access(str, F_OK) && access(str, X_OK) == -1)
		{
			free(str);
			return (10);
		}
		if ((check = access(str, X_OK)) == 0)
		{
			if (fork() == 0)
				execve(str, com_arg, envir->env);
			else
				wait(0);
			return (ft_smallest_free(str, check));
		}
		free(str);
		i++;
	}
	return (check);
}

static int	ft_check_and_exec(char **com_arg, char **paths, t_env *envir)
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
			execve(com_arg[0], com_arg, envir->env);
		else
			wait(0);
	}
	if (paths != NULL && ok == 0)
		check = ft_exec_helper(com_arg, paths, envir);
	if (check == -1)
		check = 4;
	return (check);
}

static int	env_num(t_env *envir, char *var)
{
	char	*var_t;
	char	**tmp_tab;
	int		i;

	tmp_tab = copy_tab(envir);
	i = 0;
	while (tmp_tab[i])
	{
		var_t = ft_strdup(ft_strrev(&ft_strchr(ft_strrev(tmp_tab[i]), '=')[1]));
		if (ft_strequ(var, var_t))
		{
			free(var_t);
			ft_tabdel(ft_count_tab(tmp_tab), &tmp_tab);
			return (i);
		}
		free(var_t);
		i++;
	}
	ft_tabdel(ft_count_tab(tmp_tab), &tmp_tab);
	return (i);
}

void		ft_command_parsing(t_env *envir, char **tab)
{
	char	*paths_str;
	char	*paths_tmp;
	char	**paths;
	int		check;

	paths = NULL;
	if (ft_strequ("cat", tab[0]) && tab[1] == NULL)
		envir->cat = 1;
	if (envir->env[env_num(envir, "PATH")])
	{
		paths_tmp = ft_strdup(envir->env[env_num(envir, "PATH")]);
		paths_str = &ft_strchr(paths_tmp, '=')[1];
		paths = ft_strsplit(paths_str, ':');
		free(paths_tmp);
	}
	if ((check = ft_check_and_exec(tab, paths, envir)) != 0)
		ft_puterror(check, tab[0], envir);
	if (envir->env[env_num(envir, "PATH")])
		ft_tabdel(ft_count_tab(paths), &paths);
}
