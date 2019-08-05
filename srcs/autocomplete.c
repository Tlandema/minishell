/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   autocomplete.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 11:13:39 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 09:37:33 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
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
				break ;
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
	ft_strdel(&free_me);
	if (tmp == NULL)
		return ;
	while (tmp[i])
	{
		ft_ins_char(cur, str, tmp[i]);
		i++;
	}
	ft_strdel(&tmp);
}

static char	**ft_paths_filler(char **tmp)
{
	char	**tmp_paths;

	*tmp = getenv("PATH");
	if (!(tmp_paths = ft_strsplit(*tmp, ':')))
		return (NULL);
	*tmp = NULL;
	return (tmp_paths);
}

static void	ft_more_than_one_com(char *to_match, char *str, char **tmp)
{
	char *buf;

	to_match = ft_strdup(&ft_strrchr(str, ' ')[1]);
	if (!(buf = ft_strnew(PATH_MAX)))
		return ;
	ft_open_dir(to_match, getcwd(buf, PATH_MAX), tmp);
	ft_strdel(&to_match);
	ft_strdel(&buf);
}

void		ft_autocomplete(char *str, t_cur *cur)
{
	char	*tmp;
	char	**paths;
	char	*to_match;
	int		i;

	to_match = NULL;
	if (cur->pos != cur->length || ft_last_char(str) == ' ')
		return ;
	i = -1;
	if (!(paths = ft_paths_filler(&tmp)))
		return ;
	if (ft_strrchr(str, ' '))
		ft_more_than_one_com(to_match, str, &tmp);
	else
	{
		if (!(to_match = ft_strdup(str)))
			return ;
		while (paths[++i])
			if (!ft_open_dir(to_match, paths[i], &tmp))
				return (ft_small_free(to_match, paths, tmp));
	}
	ft_auto_helper(cur, str, tmp, to_match);
	ft_tabdel(ft_count_tab(paths), &paths);
}
