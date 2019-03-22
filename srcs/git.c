/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:40:21 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/22 15:09:40 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include <limits.h>

static char	*ft_git_helper(char *tmp_path)
{
	int		fd;
	char	*str;

	ft_putstr("git:(");
	ft_strcat(tmp_path, "/HEAD");
	fd = open(tmp_path, O_RDONLY);
	get_next_line(fd, &str);
	close(fd);
	ft_putstr("\033[31;49m");
	ft_putstr(&ft_strchr(&ft_strchr(str, '/')[1], '/')[1]);
	return (str);
}

void		ft_print_git(char *path)
{
	char	*tmp_path;
	char	*str;

	if (ft_strequ(path, "/Users"))
		return ;
	tmp_path = ft_strnew(PATH_MAX);
	ft_strcpy(tmp_path, path);
	ft_strcat(tmp_path, "/.git");
	if (access(tmp_path, X_OK) == 0)
	{
		str = ft_git_helper(tmp_path);
		if (ft_strstr(str, "ref : refs/heads/"))
			ft_putstr(ft_strchr(ft_strchr(str, '/'), '/'));
		ft_putstr("\033[39;49m) ");
		free(tmp_path);
		return ;
	}
	else
	{
		ft_strdel(&tmp_path);
		tmp_path = ft_strdup(ft_strrev(&ft_strchr(ft_strrev(path), '/')[1]));
		ft_print_git(tmp_path);
		free(tmp_path);
		return ;
	}
}
