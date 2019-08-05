/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   loop.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/07/31 15:28:21 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 10:20:40 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	ft_line_parser(char **tab)
{
	if (ft_strequ(tab[0], "cd"))
		ft_cd_builtin(tab);
	else if (ft_strequ(tab[0], "exit"))
	{
		ft_tabdel(ft_count_tab(tab), &tab);
		return (1);
	}
	else if (ft_strequ(tab[0], "env"))
		ft_env_builtin(tab);
	else if (ft_strequ(tab[0], "setenv"))
		ft_setenv_builtin(tab[1], tab[2], 0);
	else if (ft_strequ(tab[0], "unsetenv"))
		ft_unsetenv_builtin(tab[1]);
	else if (ft_strequ(tab[0], "echo"))
		ft_echo_builtin(tab);
	else
		ft_command_parsing(tab);
	ft_tabdel(ft_count_tab(tab), &tab);
	return (0);
}

static int	ft_loop_reset(char **str)
{
	if (!(*str = ft_strnew(PATH_MAX)))
		return (1);
	if (!g_env->cat)
		if (ft_print_prompt())
			return (ft_smallest_free(*str, 1));
	g_env->rog = 0;
	g_env->cat = 0;
	ft_init_term();
	ft_line_editor(str);
	ft_reset_term();
	return (0);
}

static int	ft_free_loop_var(char *str, char **tab)
{
	ft_strdel(&str);
	ft_tabdel(ft_count_tab(tab), &tab);
	return (1);
}

int			ft_loop(void)
{
	char	*str;
	char	**tab_f;
	char	**tab;
	int		i;

	if ((i = ft_loop_reset(&str) != 0))
		return (1);
	if (!(str = ft_dols_tild(str)))
		return (1);
	if ((tab_f = ft_strsplit(str, ';')))
	{
		while (tab_f[i])
		{
			g_env->rog = 0;
			if (!(tab = ft_tab_builder(tab_f[i])))
				break ;
			if (tab)
				if (ft_line_parser(tab))
					return (ft_free_loop_var(str, tab_f));
			i++;
		}
		ft_tabdel(ft_count_tab(tab_f), &tab_f);
	}
	ft_strdel(&str);
	return (0);
}
