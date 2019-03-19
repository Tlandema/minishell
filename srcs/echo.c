/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/18 11:39:10 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/19 16:39:12 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

static int	ft_echo_helper_2(t_env *envir, char *str, int i)
{
	char	*tmp;
	char	*to_f;

	tmp = ft_strsub(&str[i], 0, ft_stristr(&str[i], " "));
	to_f = NULL;
	if (tmp[ft_strlen(tmp) - 1] == '"')
		ft_echo_dolss(envir, (to_f = ft_strsub(tmp, 0, ft_strlen(tmp) - 1)));
	else
		ft_echo_dolss(envir, tmp);
	free(tmp);
	free(to_f);
	i += ft_stristr(&str[i], " ");
	return (i);
}

void	ft_echo_helper(t_env *envir, char **tab)
{
	int		i;
	int		size;
	char	*str;

	i = 0;
	size = 0;
	while (tab[i])
		size += ft_strlen(tab[i++]) + 1;
	i = 0;
	str = ft_strnew(size);
	ft_strcpy(str, tab[i]);
	while (tab[++i])
	{
		ft_strcat(str, " ");
		ft_strcat(str, tab[i]);
	}
	i = -1;
	while (str[++i])
	{
		if (str[i] == '$')
			i = ft_echo_helper_2(envir, str, i);
		else if (str[i] != '"')
			ft_putchar(str[i]);
	}
	free(str);
}

void	ft_echo_dolss(t_env *envir, char *str)
{
	int		i;
	char	*str_tmp;
	char	*str_tmp2;
	char	*str_tmp3;
	char	**tmp;

	i = 0;
	tmp = copy_tab(envir);
	while (tmp[i])
	{
		str_tmp = ft_strdup(tmp[i]);
		str_tmp = ft_strrev(str_tmp);
		str_tmp2 = ft_strdup(str_tmp);
		str_tmp3 = ft_strrev(&ft_strchr(str_tmp, '=')[1]);
		if (ft_strequ(&str[1], str_tmp3))
			ft_putstr(&ft_strchr(ft_strrev(str_tmp), '=')[1]);
		i++;
		free(str_tmp);
		free(str_tmp2);
	}
	ft_tabdel(ft_count_tab(tmp), &tmp);
}
