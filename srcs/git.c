/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   git.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/20 17:40:21 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/20 19:40:45 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "../libft/includes/libft.h"
#include <limits.h>

void	ft_print_git(char *path)
{
	char *tmp_path;

	if (ft_strequ(path, ""))
		return ;
	tmp_path = ft_strnew(PATH_MAX);
	ft_strcpy(tmp_path, path);
	ft_strcat(tmp_path, "/.git");
	if (access(tmp_path, X_OK) == 0)
	{
		ft_putstr("(GIT) ");
		free(tmp_path);
		return ;
	}
	else
	{
		ft_putstr(ft_strrev(ft_strchr(ft_strrev(path), '/')));
		ft_print_git(ft_strrev(ft_strchr(ft_strrev(tmp_path), '/')));
		free(tmp_path);
		return ;
	}
}
