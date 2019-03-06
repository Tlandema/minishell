/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   command.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/06 01:52:49 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/06 02:12:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	ft_command_parsing(t_env *envir, char **tab)
{
	int i;
	//char **paths;

	i = 0;
	tab[0] = NULL;
	while (envir->env[i]
			&& !(envir->env[i][0] == 'P' && envir->env[i][1] == 'A'
				&& envir->env[i][2] == 'T' && envir->env[i][3] == 'H'
				&& envir->env[i][4] == '='))
		i++;
	if (ft_strequ(envir->env[i], "PATH=/Users/tlandema/.brew/bin:/usr/bin:/bin:/usr/sbin:/sbin:/usr/local/bin:/Applications/VMwareFusion.app/Contents/Public:/usr/local/munki"))
	ft_putstr("cucu\n");
}
