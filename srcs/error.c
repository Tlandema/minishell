/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:17:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/22 14:57:17 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

static void	ft_puterror_2(int i, char *name)
{
	if (i == 4)
	{
		if (!access(name, F_OK) && access(name, X_OK) == -1)
		{
			ft_putstr("TomTomshell: permission denied: ");
			ft_putendl(name);
		}
		else
		{
			ft_putstr("TomTomshell: command not found: ");
			ft_putendl(name);
		}
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
