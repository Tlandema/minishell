/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/08 13:55:02 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/03 07:31:23 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	int		len;
	char	*pos;

	i = 0;
	len = ft_strlen(s);
	pos = NULL;
	while (i <= len)
	{
		if (s[i] == (char)c)
		{
			pos = NULL;
			pos = (char*)&s[i];
		}
		i++;
	}
	return (pos);
}
