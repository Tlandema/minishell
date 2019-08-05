/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cursor.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 09:33:24 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/01 09:37:47 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_cur_start_pos(t_cur *cur)
{
	char	answer[20];
	int		i;

	ft_putstr_fd("\e[6n", 0);
	ft_bzero(answer, 20);
	i = read(0, answer, 20);
	answer[i] = 0;
	i = 2;
	cur->start_row = ft_atoi(answer + i);
	while (ft_isdigit(answer[i]))
		i++;
	cur->start_col = ft_atoi(answer + i + 1);
	cur->pos = 0;
	cur->length = 0;
}

void	ft_cur_left(t_cur *cur)
{
	tputs(tgetstr("le", NULL), 1, ft_printest);
	cur->pos--;
}

void	ft_cur_right(t_cur *cur)
{
	tputs(tgetstr("nd", NULL), 1, ft_printest);
	cur->pos++;
}
