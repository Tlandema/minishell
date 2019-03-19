/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_stristr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 00:46:03 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/19 08:03:06 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int		ft_stristr(const char *haystack, const char *needle)
{
	int i;
	int j;

	if (ft_strcmp(haystack, "") == 0 && ft_strcmp("", needle) == 0)
		return (0);
	i = 0;
	while (haystack[i])
	{
		j = 0;
		while (haystack[i + j] == needle[j] && needle[j])
			j++;
		if (needle[j] == '\0')
			return (i);
		i++;
	}
	return (i);
}
