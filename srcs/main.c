/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 13:46:43 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/03 12:57:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_free_env(t_env *env, int i)
{
	ft_tabdel(ft_count_tab(env->v_env), &env->v_env);
	ft_strdel(&env->old_pwd);
	ft_memdel((void **)&env);
	return (i);
}

static int	ft_create_environ(char **envp)
{
	int		i;

	i = 0;
	if (envp[0])
	{
		i = ft_count_tab(envp);
		if (!(g_env->v_env = (char **)ft_memalloc(sizeof(char *) * ((i + 1)))))
			return (1);
		i = -1;
		while (envp[++i])
			if (!(g_env->v_env[i] = ft_strdup(envp[i])))
				return (ft_free_v_env(g_env->v_env));
	}
	return (0);
}

int			main(int argc, char **argv, char **envp)
{
	argv = NULL;
	argc = 0;
	if (!(g_env = (t_env *)ft_memalloc(sizeof(t_env))))
		return (1);
	if (ft_create_environ(envp))
		return (1);
	ft_init_signals();
	while (1)
	{
		if (ft_loop())
			return (ft_free_env(g_env, 0));
	}
	return (0);
}
