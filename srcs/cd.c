/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:18:17 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/18 14:17:54 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

int			ft_move_dir(t_env *envir, char *str)
{
	if (access(str, X_OK) == 0)
	{
		ft_strcpy(envir->tmp_pwd, str);
		ft_strclr(envir->old_pwd);
		envir->old_pwd = getcwd(envir->old_pwd, PATH_MAX);
		chdir(envir->tmp_pwd);
		ft_strclr(envir->tmp_pwd);
	}
	else
		return (-1);
	return (0);
}

void		ft_cd_tild(t_env *envir, char *tab)
{
	char *str;

	str = ft_strnew(PATH_MAX);
	ft_strcpy(str, "/Users/tlandema");
	ft_strcat(str, &tab[1]);
	if (ft_move_dir(envir, str) == -1)
		ft_puterror(2, str);
}

static void	ft_replace(t_env *envir, char *str, char *to_r, char *r_by)
{
	char	*copy;
	int		j;
	int		i;
	int		k;

	copy = ft_strnew(PATH_MAX);
	j = -1;
	k = 0;
	i = ft_stristr(str, to_r);
	while (++j < i)
		copy[j] = str[j];
	i = i + ft_strlen(to_r);
	if (!(r_by[0] == 34 && r_by[1] == 34))
		while (r_by[k])
		{
			copy[j] = r_by[k];
			j++;
			k++;
		}
	while (str[i])
		copy[j++] = str[i++];
	if (ft_move_dir(envir, copy) == -1)
		ft_puterror(2, copy);
	free(copy);
}

void		ft_cd_2_arg(char **tab, t_env *envir)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	while (envir->env[i]
			&& !(envir->env[i][0] == 'P' && envir->env[i][1] == 'W'
				&& envir->env[i][2] == 'D' && envir->env[i][3] == '='))
		i++;
	if (envir->env[i])
	{
		if (ft_strstr(envir->env[i], tab[1]))
		{
			tmp = ft_strdup(envir->env[i]);
			str = &ft_strchr(tmp, '=')[1];
			ft_replace(envir, str, tab[1], tab[2]);
			free(tmp);
		}
		else
			ft_puterror(3, tab[1]);
	}
}
