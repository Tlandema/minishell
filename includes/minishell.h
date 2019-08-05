/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:33:26 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 11:40:17 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <libft.h>
# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>

typedef struct		s_env
{
	char			**v_env;
	char			*old_pwd;
	int				cat;
	int				rog;
	int				*pos;
	char			*str;
}					t_env;

typedef struct		s_cur
{
	int				start_row;
	int				start_col;
	int				pos;
	int				length;
}					t_cur;

t_env				*g_env;

/*
 **************************LOOP_FUNCTIONS***************************************
*/

int					ft_loop(void);

/*
 **************************PROMPT_FUNCTIONS*************************************
*/

int					ft_print_prompt(void);

/*
 **************************BUILTIN_FUNCTIONS************************************
*/

void				ft_cd_builtin(char **tab);
void				ft_env_builtin(char **tab);
void				ft_setenv_builtin(char *left, char *right, int i);
void				ft_unsetenv_builtin(char *del);
void				ft_echo_builtin(char **tab);

/*
 **************************EXEC_FUNCTION****************************************
*/

void				ft_command_parsing(char **tab);

/*
 **************************FREE_FUNCTIONS***************************************
*/

int					ft_free_v_env(char **tab);
void				ft_small_free(char *to_match, char **paths, char *tmp);
int					ft_smallest_free(char *str, int check);

/*
 **************************TERM_FUNCTIONS***************************************
*/

void				ft_init_term(void);
void				ft_reset_term(void);

/*
 **************************CURS_FUNCTIONS***************************************
*/

void				ft_cur_start_pos(t_cur *cur);
void				ft_cur_left(t_cur *cur);
void				ft_cur_right(t_cur *cur);

/*
 **************************UTILITY_FUNCTIONS************************************
*/

char				**copy_tab(void);
int					ft_printest(int yes);
int					ft_col_number(void);
char				*ft_get_v_env(char *match);

/*
 **************************SIGNALS_FUNCTION*************************************
*/

void				ft_init_signals(void);

/*
 **************************LINE_FUNCTIONS***************************************
*/

char				*ft_dols_tild(char *str);
char				**ft_tab_builder(char *str);
void				ft_line_editor(char **str);
void				ft_ins_char(t_cur *cur, char *str, char key);
void				ft_del_char(t_cur *cur, char *str);
void				ft_autocomplete(char *str, t_cur *cur);

/*
 *************************ERORR_FUNCTIONS**************************************
*/

void				ft_puterror(int i, char *name);

#endif
