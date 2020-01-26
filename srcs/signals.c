/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 15:17:40 by tlandema          #+#    #+#             */
/*   Updated: 2020/01/07 09:27:00 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <sys/ioctl.h>

static void	ft_stop_signal_handler(void)
{
	ft_reset_term();
	exit(1);
}

static void	ft_sig_int_handler(void)
{
	int i;

	i = 0;
	g_env->rog = 1;
	ft_putchar('\n');
	while (i++ < ft_col_number())
		tputs(tgetstr("le", NULL), 0, ft_printest);
	ft_print_prompt();
	if (g_env->cat == 1)
		g_env->cat = -1;
	g_env->rog = 0;
	*g_env->pos = 0;
	ft_strclr(g_env->str);
}

static void	ft_suspend_signal_handler(void)
{
	ft_reset_term();
	signal(SIGTSTP, SIG_DFL);
	ioctl(STDERR_FILENO, TIOCSTI, "\x1A");
}

static void	signal_handler(int signal)
{
	char *str;

	if (signal == SIGCONT)
	{
		ft_init_term();
		ft_init_signals();
		ft_print_prompt();
		str = g_env->str;
		if (str)
			ft_putstr(str);
	}
	else if (signal == SIGABRT || signal == SIGSTOP || signal == SIGKILL
			|| signal == SIGQUIT || signal == SIGTERM)
		ft_stop_signal_handler();
	else if (signal == SIGINT)
		ft_sig_int_handler();
	else if (signal == SIGTSTP)
		ft_suspend_signal_handler();
}

void		ft_init_signals(void)
{
	signal(SIGABRT, signal_handler);
	signal(SIGINT, signal_handler);
	signal(SIGSTOP, signal_handler);
	signal(SIGTERM, signal_handler);
	signal(SIGCONT, signal_handler);
	signal(SIGTSTP, signal_handler);
	signal(SIGKILL, signal_handler);
	signal(SIGQUIT, signal_handler);
}
