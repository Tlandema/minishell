/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/05/02 02:02:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/11 16:43:04 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../libft/includes/libft.h"
#include "../libft/includes/get_next_line.h"
#include "../includes/minishell.h"
#include <sys/ioctl.h>

int			col_number(void)
{
	struct winsize	w;

	ioctl(STDOUT_FILENO, TIOCGWINSZ, &w);
	return (w.ws_col);
}

int			ft_printest(int yes)
{
	ft_putchar_fd((char)yes, STDERR_FILENO);
	return (0);
}

static int	ft_key_press(long key, char **str, t_cur *cur)
{
	signal(SIGINT, signalhandler);
	if (key > 31 && key < 127)
		ft_ins_char(cur, *str, (char)key);
	else if (key == 4414235 && cur->pos < cur->length)
		ft_cur_right(cur);
	else if (key == 4479771 && cur->pos != 0)
		ft_cur_left(cur);
	else if (key == 127 && cur->length != 0)
		ft_del_char(cur, str);
	else if (key == 9)
		ft_autocomplete(*str, cur);
	else if (key == 10)
		return (1);
	return (0);
}

void		ft_loop(char **str)
{
	long	key;
	t_cur	*cur;
	int		i;

	i = 0;
	cur = (t_cur *)ft_memalloc(sizeof(t_cur));
	ft_cur_start_pos(cur);
	while (1)
	{
		key = 0;
		read(0, &key, 8);
		if (ft_key_press(key, str, cur))
		{
			ft_putchar('\n');
			while (i++ < col_number())
				tputs(tgetstr("le", NULL), 0, ft_printest);
			free(cur);
			return ;
		}
	}
}
