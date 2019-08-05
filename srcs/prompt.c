/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   prompt.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:35:04 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 10:23:00 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <fcntl.h>

static char	*ft_git_helper(char *tmpath)
{
	int		fd;
	char	*str;

	ft_strcat(tmpath, "/HEAD");
	if (access(tmpath, R_OK) != 0)
		return (NULL);
	fd = open(tmpath, O_RDONLY);
	if (get_next_line(fd, &str) == -1)
		return (NULL);
	close(fd);
	ft_putstr("git:(\033[31;49m");
	ft_putstr(&ft_strchr(&ft_strchr(str, '/')[1], '/')[1]);
	if (ft_strstr(str, "ref : refs/heads/"))
		ft_putstr(ft_strchr(ft_strchr(str, '/'), '/'));
	ft_putstr("\033[39;49m) ");
	return (str);
}

static void	ft_dat_free(char *str, char *str1)
{
	ft_strdel(&str);
	ft_strdel(&str1);
}

static void	ft_print_git(char *path)
{
	char	*tmpath;
	char	*str;

	if (!path || !path[0])
		return ;
	if (!(tmpath = ft_strnew(PATH_MAX)))
		return ;
	ft_strcpy(tmpath, path);
	ft_strcat(tmpath, "/.git");
	if (access(tmpath, X_OK) == 0)
	{
		if (!(str = ft_git_helper(tmpath)))
			return (ft_strdel(&tmpath));
		return (ft_dat_free(str, tmpath));
	}
	else
	{
		ft_strdel(&tmpath);
		tmpath = ft_strdup(ft_strrev(&ft_strchr(ft_strrev(path), '/')[1]));
		ft_print_git(tmpath);
		ft_strdel(&tmpath);
	}
}

static void	ft_rog(int rog)
{
	if (rog)
		ft_putstr("\033[91m");
	else
		ft_putstr("\033[92m");
	ft_putstr("Tsh \033[39m(\033[96m");
}

int			ft_print_prompt(void)
{
	char	*path;
	char	*tmp;

	if (g_env->cat == -1)
	{
		g_env->cat = 0;
		return (0);
	}
	if (!(path = ft_strnew(PATH_MAX)))
		return (1);
	ft_rog(g_env->rog);
	if (!getcwd(path, PATH_MAX))
	{
		ft_putstr("I'm in the depth of shell\033[39;49m)");
		return (ft_smallest_free(path, 0));
	}
	if (ft_strequ(path, tmp = ft_get_v_env("HOME")))
		ft_putstr("~");
	else
		ft_putstr(&ft_strrchr(path, '/')[1]);
	ft_putstr("\033[39;49m) ");
	if (!ft_strequ(path, "/"))
		ft_print_git(path);
	ft_small_free(path, NULL, tmp);
	return (0);
}
