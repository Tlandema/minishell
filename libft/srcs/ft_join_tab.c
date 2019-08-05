/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_join_tab.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 18:54:31 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 16:19:11 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

int		ft_join_tab(char **final_tab, char **tmp_tab, int j)
{
	int i;

	i = -1;
	while (tmp_tab[++i])
	{
		final_tab[j] = ft_strdup(tmp_tab[i]);
		j++;
	}
	return (j);
}
