/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   launcher.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 14:08:04 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/03 18:13:14 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "test_minishell/includes/libft.h"
#include "test_minishell/includes/get_next_line.h"
#include <unistd.h>
#include <limits.h>

int		main(void)
{
	int i;
	int j;
	char *path;
	char *str;
	extern char **environ;
	char **tab;

	i = 0;
	j = 0;
	path = ft_strnew(PATH_MAX);
	while (i != 1)
	{
		ft_putstr("mynishell (");
		ft_putstr(&ft_strrchr(getcwd(path, PATH_MAX), '/')[1]);
		ft_putstr(") ");
		get_next_instruction(&str); //ca malloc cette merde donc free stp;
		tab = ft_strsplit(str, ' ');
		if (tab)
		{
			if (ft_strequ(tab[0], "cd"))
				chdir(tab[1]);
			else if (ft_strequ(tab[0],"exit"))
				i = 1;
			else if (ft_strequ(tab[0], "clear"))
				ft_putstr("\e[1;1H\e[2J");
		}
	}
}
