/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 10:18:17 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/06 10:30:37 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	ft_cd_2_arg(char **tab, t_env *envir)
{
	int i;
	char *str;

	i = 0;
	while (envir->env[i]
			&& !(envir->env[i][0] == 'P' && envir->env[i][1] == 'W'
				&& envir->env[i][2] == 'D' && envir->env[i][3] == '='))
		i++;
	str = ft_strdup(envir->env[i]);
	if (ft_strstr(str, tab[1]))
}
