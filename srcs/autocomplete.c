/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 16:44:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/03 13:35:21 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <dirent.h>

static int	ft_open_dir(char *to_match, char *dir_name, char **to_give)
{
	struct dirent	*dp;
	DIR				*dirp;
	int				len;

	len = ft_strlen(to_match);
	if (len == 0)
		return (0);
	if (!(dirp = opendir(dir_name)))
		return (0);
	while ((dp = readdir(dirp)) != NULL)
	{
		if (!ft_strncmp(dp->d_name, to_match, len))
		{
			if (*to_give != NULL)
				return (0);
			*to_give = ft_strdup(&dp->d_name[len]);
		}
	}
	if (closedir(dirp) == -1)
		return (0);
	return (1);
}

static void	ft_auto_helper(t_cur *cur, char *str, char *tmp, char *free_me)
{
	int	i;

	i = 0;
	if (tmp == NULL)
		return ;
	while (tmp[i])
	{
		ft_ins_char(cur, str, tmp[i]);
		i++;
	}
	free(tmp);
	free(free_me);
}

static char	**ft_paths_filler(char **tmp)
{
	char **tmp_paths;

	*tmp = getenv("PATH");
	tmp_paths = ft_strsplit(*tmp, ':');
	*tmp = NULL;
	return (tmp_paths);
}

static void	ft_more_than_one_com(char *to_match, char **tmp)
{
	char	*buf;

	buf = ft_strnew(PATH_MAX);
	ft_open_dir(to_match, getcwd(buf, PATH_MAX), tmp);
	free(buf);
}

void		ft_autocomplete(char *str, t_cur *cur)
{
	char	*tmp;
	char	**paths;
	char	*to_match;
	int		i;

	i = -1;
	paths = ft_paths_filler(&tmp);
	if (ft_strrchr(str, ' '))
	{
		to_match = ft_strdup(&ft_strrchr(str, ' ')[1]);
		ft_more_than_one_com(to_match, &tmp);
	}
	else
	{
		to_match = ft_strdup(str);
		while (paths[++i])
		{
			if (!ft_open_dir(to_match, paths[i], &tmp))
				break ;
		}
	}
	ft_auto_helper(cur, str, tmp, to_match);
	ft_tabdel(ft_count_tab(paths), &paths);
}
