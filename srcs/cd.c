/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 12:08:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 10:10:31 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/stat.h>

static int	ft_move_dir(char *str)
{
	char *tmp;

	if (!access(str, X_OK))
	{
		if (!(tmp = ft_strdup(str)))
			return (1);
		ft_strclr(g_env->old_pwd);
		g_env->old_pwd = getcwd(g_env->old_pwd, PATH_MAX);
		chdir(tmp);
		ft_strdel(&tmp);
	}
	else
		return (1);
	return (0);
}

static void	ft_replace(char *str, char *to_r, char *r_by)
{
	char	*copy;
	int		j;
	int		i;
	int		k;

	if (!(copy = ft_strnew(PATH_MAX)))
		return ;
	j = -1;
	k = 0;
	i = ft_stristr(str, to_r);
	while (++j < i)
		copy[j] = str[j];
	i = i + ft_strlen(to_r);
	while (r_by[k])
	{
		copy[j] = r_by[k];
		j++;
		k++;
	}
	while (str[i])
		copy[j++] = str[i++];
	if (ft_move_dir(copy) == -1)
		ft_puterror(2, copy);
	ft_strdel(&copy);
}

void		ft_cd_2_arg(char **tab)
{
	int		i;
	char	*tmp;
	char	*str;

	i = 0;
	while (g_env->v_env[i]
			&& !(g_env->v_env[i][0] == 'P' && g_env->v_env[i][1] == 'W'
				&& g_env->v_env[i][2] == 'D' && g_env->v_env[i][3] == '='))
		i++;
	if (g_env->v_env[i])
	{
		if (ft_strstr(g_env->v_env[i], tab[1]))
		{
			tmp = ft_strdup(g_env->v_env[i]);
			str = &ft_strchr(tmp, '=')[1];
			ft_replace(str, tab[1], tab[2]);
			ft_strdel(&tmp);
		}
		else
			ft_puterror(3, tab[1]);
	}
}

void		ft_cd_builtin(char **tab)
{
	int		i;
	char	*buff;
	char	*tmp;

	tmp = NULL;
	if (!(buff = ft_strnew(PATH_MAX)))
		return ;
	i = ft_count_tab(tab);
	if (i > 3)
		ft_puterror(1, NULL);
	else if (tab[0] && tab[1] && tab[2])
		ft_cd_2_arg(tab);
	else if (!tab[1])
		ft_move_dir((tmp = ft_get_v_env("HOME")));
	else if (ft_strequ(tab[1], "-"))
		ft_move_dir(g_env->old_pwd);
	else if (ft_move_dir(tab[1]))
		ft_puterror(2, tab[1]);
	if (getenv("PWD"))
		ft_unsetenv_builtin("PWD");
	ft_setenv_builtin("PWD", getcwd(buff, PATH_MAX), 0);
	ft_strdel(&buff);
	ft_strdel(&tmp);
}
