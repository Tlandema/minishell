/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:17:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/11 20:54:28 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"

void		ft_free(char **tab_f, char **tab, t_env *envir, char *str)
{
	free(envir->old_pwd);
	free(envir->tmp_pwd);
	ft_tabdel(ft_count_tab(envir->env), &envir->env);
	free(envir);
	ft_strdel(&str);
	ft_tabdel(ft_count_tab(tab), &tab);
	ft_tabdel(ft_count_tab(tab_f), &tab_f);
}

int			ft_smallest_free(char *str, int check)
{
	free(str);
	return (check);
}

void		ft_small_free(char *to_match, char **paths, char *tmp)
{
	free(to_match);
	ft_tabdel(ft_count_tab(paths), &paths);
	free(tmp);
}

static void	ft_puterror_2(int i, char *name)
{
	if (i == 4)
	{
		ft_putstr("TomTomshell: command not found: ");
		ft_putendl(name);
	}
	else if (i == 5)
	{
		ft_putstr("Usage: \'setenv [VAR] [foo]\' will create a environmental ");
		ft_putstr("variable named VAR=foo. You can't put the sign \'=\' in ");
		ft_putendl("either the name or the value of the variable.");
	}
	else if (i == 6)
	{
		ft_putstr("Usage: \'unsetenv [VAR]\' will delete an environmental var");
		ft_putendl("iable called VAR if it exists.");
	}
	else if (i == 10)
	{
		ft_putstr("TomTomshell: permission denied: ");
		ft_putendl(name);
	}
}

void		ft_puterror(int i, char *name, t_env *envir)
{
	envir->r_o_g = 1;
	if (i == 1)
		ft_putstr("cd: too many arguments\n");
	else if (i == 2)
	{
		if (!access(name, F_OK) && access(name, X_OK) == -1)
			ft_putstr("cd: permission denied: ");
		else
			ft_putstr("cd: no such file or directory: ");
		ft_putstr(name);
		ft_putchar('\n');
	}
	else if (i == 3)
	{
		ft_putstr("cd: string not in pwd: ");
		ft_putstr(name);
		ft_putchar('\n');
	}
	else
		ft_puterror_2(i, name);
}
