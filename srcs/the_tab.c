/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   the_tab.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/08 14:10:25 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/12 04:55:50 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"

static int	ft_count_words(char *s)
{
	int		tab_size;
	int		i;
	int		bol;

	i = 0;
	bol = 1;
	tab_size = 0;
	if (s)
	{
		while (s[i])
		{
			if (s[i] == ' ')
				bol = 1;
			else if (bol == 1)
			{
				bol = 0;
				tab_size++;
			}
			i++;
		}
	}
	return (tab_size);
}

static int	ft_count_args(char **tab, int bole)
{
	int	count;
	int i;

	count = 0;
	i = 0;
	if (bole == 1)
	{
		count++;
		i = 1;
	}
	while (tab[i])
	{
		count += ft_count_words(tab[i]);
		i++;
		if (tab[i])
		{
			count++;
			i++;
		}
	}
	return (count);
}

static int	ft_how_many_quote(char *str)
{
	int i;
	int j;

	i = 0;
	j = 0;
	while (str[i])
	{
		if (str[i] == '"')
			j++;
		i++;
	}
	return (j);
}

static void	ft_fill_the_tab(char **fin_tab, char **tp_tab, int bole)
{
	int		i;
	int		j;
	char	**tmp_tab2;

	i = 0;
	j = 0;
	if (bole == 1)
	{
		fin_tab[0] = ft_strdup(tp_tab[0]);
		j = 1;
		i = 1;
	}
	while (tp_tab[i])
	{
		tmp_tab2 = ft_split_white(tp_tab[i]);
		j = ft_join_tab(fin_tab, tmp_tab2, j);
		ft_tabdel(ft_count_tab(tmp_tab2), &tmp_tab2);
		if (tp_tab[++i])
		{
			fin_tab[j] = ft_strdup(tp_tab[i]);
			j++;
			i++;
		}
	}
}

char		**ft_the_tab(char *str)
{
	char	**first_tab;
	int		arg_num;
	int		bole;
	char	**last_tab;

	last_tab = NULL;
	if (ft_how_many_quote(str) % 2 == 1 && ft_how_many_quote(str) != 0)
		return (NULL);
	arg_num = 0;
	while (str[arg_num] == ' ')
		arg_num++;
	if (str[arg_num] == '\0')
		return (NULL);
	bole = (str[arg_num] == '"') ? 1 : 0;
	first_tab = ft_strsplit(str, '"');
	arg_num = ft_count_args(first_tab, bole);
	if (!(last_tab = (char **)ft_memalloc(sizeof(char *) * (arg_num + 1))))
		return (NULL);
	ft_fill_the_tab(last_tab, first_tab, bole);
	last_tab[arg_num] = NULL;
	ft_tabdel(ft_count_tab(first_tab), &first_tab);
	return (last_tab);
}
