/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   envs.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 13:50:09 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/03 17:06:16 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void		ft_env_builtin(char **tab)
{
	if (!ft_strequ(tab[1], "-i"))
		ft_print_tab(g_env->v_env);
}

static void	ft_unset_helper(char *str, char *str_tmp)
{
	ft_strdel(&str_tmp);
	ft_strclr(str);
	str = NULL;
}

static int	ft_check_env(char *check)
{
	int		i;
	int		j;
	int		k;
	char	*copy;

	i = 0;
	j = 0;
	k = 0;
	while (g_env->v_env[i])
	{
		copy = ft_strdup(g_env->v_env[i]);
		if (ft_strequ(ft_strrev(&ft_strchr(ft_strrev(copy), '=')[1]), check))
			k = 1;
		ft_strdel(&copy);
		copy = NULL;
		i++;
	}
	return (k);
}

void		ft_setenv_builtin(char *left, char *right, int i)
{
	char	**t;
	char	*str_tmp;

	if (!left || !right || ft_strchr(left, '=') || ft_strchr(right, '='))
	{
		ft_puterror(5, NULL);
		return ;
	}
	str_tmp = ft_strnew(ft_strlen(left) + ft_strlen(right) + 1);
	t = copy_tab();
	ft_tabdel(ft_count_tab(g_env->v_env), &g_env->v_env);
	g_env->v_env = (char **)ft_memalloc(sizeof(char *) * (ft_count_tab(t) + 2));
	while (t[i])
	{
		g_env->v_env[i] = ft_strdup(t[i]);
		i++;
	}
	ft_strcpy(str_tmp, left);
	ft_strcat(str_tmp, "=");
	ft_strcat(str_tmp, right);
	g_env->v_env[i] = ft_strdup(str_tmp);
	i++;
	ft_strdel(&str_tmp);
	ft_tabdel(ft_count_tab(t), &t);
}

void		ft_unsetenv_builtin(char *del)
{
	int		i;
	int		j;
	char	**t;
	char	*str;
	char	*str_tmp;

	i = -1;
	j = 0;
	if (ft_check_env(del) == 1)
	{
		t = copy_tab();
		ft_tabdel(ft_count_tab(g_env->v_env), &g_env->v_env);
		g_env->v_env = (char **)ft_memalloc(sizeof(char *) * (ft_count_tab(t)));
		while (t[++i])
		{
			str_tmp = ft_strdup(t[i]);
			str = ft_strrev(&ft_strchr(ft_strrev(t[i]), '=')[1]);
			if (!ft_strequ(del, str))
				g_env->v_env[j++] = ft_strdup(str_tmp);
			ft_unset_helper(str, str_tmp);
		}
		ft_tabdel(ft_count_tab(t), &t);
	}
	else
		ft_puterror(6, NULL);
}
