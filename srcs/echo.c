/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:39:10 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/19 08:30:24 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	ft_echo_helper(t_env *envir, char **tab)
{
	int		i;
	int		size;
	char	*tr;
	char	*tmp;

	i = 0;
	size = 0;
	while (tab[i])
		size += ft_strlen(tab[i++]) + 1;
	i = 0;
	tr = ft_strnew(size);
	ft_strcpy(tr, tab[i]);
	while (tab[++i])
	{
		ft_strcat(tr, " ");
		ft_strcat(tr, tab[i]);
	}
	i = -1;
	while (tr[++i])
	{
		if (tr[i] == '$')
		{
			tmp = ft_strsub(&tr[i], 0, ft_stristr(&tr[i], " "));
			ft_echo_dolss(envir, tmp);
			free(tmp);
			i += ft_stristr(&tr[i], " ");
		}
		if (tr[i] != '"')
			ft_putchar(tr[i]);
	}
}

void	ft_echo_dolss(t_env *envir, char *str)
{
	int		i;
	char	*str_tmp;
	char	*str_tmp2;
	char	**tmp;

	i = 0;
	tmp = copy_tab(envir);
	while (tmp[i])
	{
		str_tmp = ft_strdup(tmp[i]);
		str_tmp = ft_strrev(str_tmp);
		str_tmp2 = ft_strdup(str_tmp);
		str_tmp2 = ft_strrev(&ft_strchr(str_tmp, '=')[1]);
		if (ft_strequ(&str[1], str_tmp2))
			ft_putstr(&ft_strchr(ft_strrev(str_tmp), '=')[1]);
		i++;
	}
}
