/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:18:17 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/18 09:10:34 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

static void	ft_replace(char *str, char *to_r, char *r_by)
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
	if (chdir(copy) == -1)
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
			ft_replace(str, tab[1], tab[2]);
			free(tmp);
		}
		else
			ft_puterror(3, tab[1]);
	}
}
