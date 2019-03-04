/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:03:12 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/04 17:29:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	ft_cd_builtin(char **tab)
{
	int i;

	i = ft_count_tab(tab);
	if (i > 3)
	{
		ft_puterror(1, NULL);
		if (tab[3])
			ft_putstr(tab[3]);
	}
	else if (chdir(tab[1]) == -1)
		ft_puterror(2, tab[1]);
}
