/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:17:38 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/04 18:20:08 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <unistd.h>
#include <limits.h>
#include <stdlib.h>

void	ft_puterror(int i, char *name)
{
	if (i == 1)
		ft_putstr("cd: too many arguments\n");
	else if (i == 2)
	{
		if (!access(name, F_OK) && access(name, X_OK) == -1)
		{
			ft_putstr("cd: permission denied :");
			ft_putstr(name);
			ft_putchar('\n');
		}
		else
		{
			ft_putstr("cd: no such file or directory: ");
			ft_putstr(name);
			ft_putchar('\n');
		}
	}
}
