/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_white.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:48:25 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/09 17:34:03 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

#include "libft.h"

static char	*count_dup(char **s_ptr)
{
	size_t	nb_l;
	size_t	i;
	char	*dup;

	while (**s_ptr && **s_ptr == ' ')
		*s_ptr = *s_ptr + 1;
	nb_l = 0;
	while (*(*s_ptr + nb_l) && *(*s_ptr + nb_l) != ' ')
		nb_l++;
	if (!(dup = (char *)malloc(sizeof(char) * (nb_l + 1))))
		return (NULL);
	i = 0;
	while (i < nb_l)
	{
		dup[i] = *(*s_ptr + i);
		i++;
	}
	dup[i] = '\0';
	*s_ptr += nb_l;
	return (dup);
}

char		**ft_split_white(char *s)
{
	size_t	i;
	size_t	word_n;
	char	**s_tab;
	char	**s_ptr;

	if (!s)
		return (NULL);
	i = 0;
	word_n = 0;
	while (s[i])
	{
		if ((s[i] != ' ') && (s[i + 1] == ' ' || s[i + 1] == '\0'))
			word_n++;
		i++;
	}
	if (!(s_tab = (char **)malloc(sizeof(char *) * (word_n + 1))))
		return (NULL);
	s_ptr = (char **)&s;
	i = -1;
	while (++i < word_n)
		s_tab[i] = count_dup(s_ptr);
	s_tab[i] = NULL;
	return (s_tab);
}
