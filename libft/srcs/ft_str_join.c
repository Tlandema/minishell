/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_str_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/06/17 14:29:29 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/18 10:48:38 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_str_join(char *str1, char *str2)
{
	char	*str3;

	if (str2 == NULL || !*str2)
		return (NULL);
	if (str1 == NULL || !*str1)
		return (ft_strdup(str2));
	if (!(str3 = ft_strnew(ft_strlen(str1) + ft_strlen(str2) + 1)))
		return (NULL);
	ft_strcat(str3, str1);
	ft_strcat(str3, "\n");
	ft_strcat(str3, str2);
	free(str1);
	return (str3);
}
