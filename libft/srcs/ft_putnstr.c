/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/12 17:01:40 by tlandema          #+#    #+#             */
/*   Updated: 2019/01/05 08:37:44 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_putnstr(char const *s, int n)
{
	int i;

	if (s == NULL)
		return ((void)0);
	i = 0;
	while (s[i] && i < n)
	{
		ft_putchar(s[i]);
		i++;
	}
}
