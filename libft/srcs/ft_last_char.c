/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_last_char.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 13:43:56 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 16:19:55 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	ft_last_char(char *str)
{
	int i;

	i = -1;
	if (!str)
		return (-1);
	while (str[++i])
		if (str[i + 1] == '\0')
			return (str[i]);
	return ('\0');
}
