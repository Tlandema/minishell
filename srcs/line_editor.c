/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   line_editor.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/01 09:26:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/03 15:58:18 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/ioctl.h>

int			ft_col_number(void)
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
	if ((key > 31 && key < 127))
		ft_ins_char(cur, *str, (char)key);
	else if (key == 4414235 && cur->pos < cur->length)
		ft_cur_right(cur);
	else if (key == 4479771 && cur->pos != 0)
		ft_cur_left(cur);
	else if (key == 127 && cur->length != 0)
		ft_del_char(cur, *str);
	else if (key == 9)
		ft_autocomplete(*str, cur);
	else if (key == 10)
		return (1);
	return (0);
}

void		ft_line_editor(char **str)
{
	long	key;
	t_cur	cur;
	int		i;

	i = 0;
	ft_bzero(&cur, sizeof(t_cur));
	g_env->str = *str;
	ft_cur_start_pos(&cur);
	g_env->pos = &cur.pos;
	while (1)
	{
		key = 0;
		read(0, &key, 8);
		if (ft_key_press(key, str, &cur))
		{
			ft_putchar('\n');
			while (i++ < ft_col_number())
				tputs(tgetstr("le", NULL), 0, ft_printest);
			return ;
		}
	}
}
