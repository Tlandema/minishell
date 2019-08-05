/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_functions.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 14:27:13 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/03 17:41:32 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_small_free(char *to_match, char **tab, char *tmp)
{
	int i;

	i = -1;
	ft_strdel(&to_match);
	ft_strdel(&tmp);
	if (tab)
		while (tab[++i])
			ft_strdel(&tab[i]);
	ft_memdel((void **)&tab);
}

int		ft_smallest_free(char *str, int check)
{
	ft_strdel(&str);
	return (check);
}

int		ft_free_v_env(char **tab)
{
	int i;

	i = 0;
	while (tab[i])
		ft_strdel(&tab[i++]);
	ft_memdel((void **)&tab);
	return (1);
}
