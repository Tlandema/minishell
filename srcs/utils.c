/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 15:33:19 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/05 14:52:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char		*ft_get_v_env(char *match)
{
	int		i;
	char	**var;
	char	*cpy;

	i = 0;
	var = copy_tab();
	while (var[i])
	{
		cpy = var[i];
		if (ft_strequ(ft_strrev(&ft_strchr(ft_strrev(var[i]), '=')[1]), match))
		{
			ft_strrev(cpy);
			cpy = ft_strdup(&ft_strchr(cpy, '=')[1]);
			ft_tabdel(ft_count_tab(var), &var);
			return (cpy);
		}
		i++;
	}
	ft_tabdel(ft_count_tab(var), &var);
	return (NULL);
}

static char	**ft_free_copy(char **copy)
{
	ft_tabdel(ft_count_tab(copy), &copy);
	return (NULL);
}

char		**copy_tab(void)
{
	int		i;
	char	**copy;

	i = ft_count_tab(g_env->v_env);
	if (!(copy = (char **)ft_memalloc(sizeof(char *) * (i + 1))))
		return (NULL);
	i = -1;
	while (g_env->v_env[++i])
		if (!(copy[i] = ft_strdup(g_env->v_env[i])))
			return (ft_free_copy(copy));
	copy[i] = NULL;
	return (copy);
}
