/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdel.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/09 10:36:00 by tlandema          #+#    #+#             */
/*   Updated: 2019/02/22 02:14:01 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

void	ft_strdel(char **as)
{
	if (!as || !*as)
		return ;
	free(*as);
	*as = NULL;
}
