/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtin.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 15:03:12 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/06 01:43:27 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	ft_cd_builtin(char **tab)
{
	int i;

	i = ft_count_tab(tab);
	if (i > 3)
	{
		ft_puterror(1, NULL);
		if (tab[3])
			ft_putstr(tab[3]);
	}
	else if (chdir(tab[1]) == -1)
		ft_puterror(2, tab[1]);
}

void	ft_setenv_builtin(t_env *envir, char *left, char *right, int i)
{
	char **tmp;
	char *str_tmp;

	if (!left || !right)
		return ;
	str_tmp = ft_strnew(ft_strlen(left) + ft_strlen(right));
	tmp = copy_tab(envir);
	ft_tabdel(ft_count_tab(envir->env), &envir->env);
	envir->env = (char **)ft_memalloc(sizeof(char *) * (ft_count_tab(tmp) + 2));
	while (tmp[i])
	{
		envir->env[i] = ft_strdup(tmp[i]);
		i++;
	}
	ft_strcpy(str_tmp, left);
	ft_strcat(str_tmp, "=");
	ft_strcat(str_tmp, right);
	envir->env[i] = ft_strdup(str_tmp);
	i++;
	free(str_tmp);
	ft_tabdel(ft_count_tab(tmp), &tmp);
}

void	ft_unsetenv_builtin(t_env *envir, char *del)
{
	int i;
	int j;
	char **tmp;
	char *str;
	char *str_tmp;

	i = 0;
	j = 0;
	ft_putnbr(ft_check_env(envir, del));
	if (ft_check_env(envir, del) == 1)
	{
		tmp = copy_tab(envir);
		ft_tabdel(ft_count_tab(envir->env), &envir->env);
		envir->env = (char **)ft_memalloc(sizeof(char *) * (ft_count_tab(tmp)));
		while (tmp[i])
		{
			str_tmp = ft_strdup(tmp[i]);
			str = ft_strrev(&ft_strchr(ft_strrev(tmp[i]), '=')[1]);
			if (!ft_strequ(del, str))
			{
				envir->env[j] = ft_strdup(str_tmp);
				j++;
			}
			ft_strclr(str_tmp);
			free(str_tmp);
			str_tmp = NULL;
			ft_strclr(str);
			str = NULL;
			i++;
		}
		ft_tabdel(ft_count_tab(tmp), &tmp);
	}
}

void	ft_echo_builtin(t_env *envir, char **tab)
{
	int i;
	char *str;//deletecasertarien

	i = 1;
	if (ft_strequ(tab[1], "-n"))
		i = 2;
	str = envir->env[i];
	while (tab[i])
	{
		ft_putstr(tab[i]);
		ft_putchar(' ');
		i++;
	}
	ft_putchar('\n');
}
