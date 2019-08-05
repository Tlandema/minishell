/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tabdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/19 19:34:17 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/03 11:12:05 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_tabdel(int i, char ***tab)
{
	if (tab == NULL)
		return ;
	while (i >= 0)
	{
		ft_strclr((*tab)[i]);
		ft_strdel(&(*tab)[i]);
		i--;
	}
	ft_memdel((void **)tab);
}
