/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 16:29:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 16:16:57 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(long l)
{
	int		i;

	i = 1;
	if (l < 0)
	{
		i++;
		l = -l;
	}
	while (l > 9)
	{
		l /= 10;
		i++;
	}
	return (i);
}

char		*ft_itoa(int n)
{
	int		i;
	int		size;
	char	*s;

	i = 0;
	size = get_size(n);
	if (!(s = ft_strnew(size)))
		return (NULL);
	if (n < 0)
	{
		i++;
		n *= -1;
		s[0] = '-';
	}
	while (size > i)
	{
		s[size - 1] = n % 10 + 48;
		n /= 10;
		size--;
	}
	return (s);
}
