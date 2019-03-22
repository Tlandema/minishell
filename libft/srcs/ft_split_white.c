/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split_white.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/09/12 14:48:25 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/22 14:55:12 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "libft.h"

static int	tab_size(char *s)
{
	int		tab_size;
	int		i;
	int		bol;

	i = 0;
	bol = 1;
	tab_size = 0;
	while (s[i])
	{
		if (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
			bol = 1;
		else if (bol == 1)
		{
			bol = 0;
			tab_size++;
		}
		i++;
	}
	return (tab_size);
}

static int	*ft_letters(char *s)
{
	int	*tab_i;
	int i;
	int	j;
	int	l;

	if (!(tab_i = (int *)ft_memalloc(sizeof(int) * tab_size(s))))
		return (NULL);
	i = 0;
	j = 0;
	while (s[i] && j < tab_size(s))
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		l = 0;
		while (s[i] && (s[i] != ' ' || s[i] != '\t' || s[i] != '\n'))
		{
			i++;
			l++;
		}
		tab_i[j] = l;
		j++;
	}
	return (tab_i);
}

static char	**ft_fill_tab(char *s, char **tab)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	j = 0;
	while (s[i] && j < tab_size(s))
	{
		while (s[i] && (s[i] == ' ' || s[i] == '\t' || s[i] == '\n'))
			i++;
		k = 0;
		while (s[i] && (s[i] != ' ' && s[i] != '\t' && s[i] != '\n'))
		{
			tab[j][k] = s[i];
			i++;
			k++;
		}
		tab[j][k] = '\0';
		j++;
	}
	return (tab);
}

static void	let_it_go(int i, char ***tab)
{
	while (i >= 0)
	{
		ft_strclr(*tab[i]);
		ft_strdel(tab[i]);
		i--;
	}
	free(*tab);
	*tab = NULL;
}

char		**ft_split_white(char *str)
{
	char	**tab;
	int		i;
	int		*tab_i;

	if (str == NULL || !(tab_i = ft_letters(str)))
		return (NULL);
	if (!(tab = (char **)ft_memalloc(sizeof(char *) * (tab_size(str) + 1))))
		return (NULL);
	tab[tab_size(str)] = NULL;
	i = 0;
	while (i < tab_size(str))
	{
		if (!(tab[i] = (char*)ft_memalloc(sizeof(char) * (tab_i[i] + 1))))
		{
			let_it_go(i - 1, &tab);
			ft_memdel((void**)&tab_i);
			return (NULL);
		}
		i++;
	}
	ft_memdel((void**)&tab_i);
	ft_putstr(tab[0]);
	return (ft_fill_tab(str, tab));
}
