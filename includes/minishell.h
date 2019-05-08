/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:33:26 by tlandema          #+#    #+#             */
/*   Updated: 2019/05/08 16:30:46 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include <signal.h>
# include <unistd.h>
# include <limits.h>
# include <stdlib.h>
# include <termios.h>
# include <termcap.h>

typedef struct	s_env
{
	char	**env;
	char	*old_pwd;
	char	*tmp_pwd;
	int		cat;
	int		r_o_g;
}				t_env;

typedef struct	s_cur
{
	int		start_row;
	int		start_col;
	int		pos;
	int		length;
}				t_cur;

char			**ft_the_tab(char *str);

int				ft_printest(int yes);
void			ft_init_term(void);
void			ft_reset_term(void);
void			ft_loop(char **str);

void			ft_ins_char(t_cur *cur, char *str, char key);
void			ft_del_char(t_cur *cur, char **str);

void			ft_autocomplete(char *str, t_cur *cur);

void			ft_cur_start_pos(t_cur *cur);
void			ft_cur_left(t_cur *cur);
void			ft_cur_right(t_cur *cur);

int				ft_check_env(t_env *envir, char *check);
void			ft_print_git(char *path);
void			ft_puterror(int i, char *name, t_env *envir);
t_env			*ft_create_environ(char **envp, char **argv);
char			**copy_tab(t_env *envir);

void			ft_cd_builtin(char **tab, t_env *envir);
void			ft_cd_2_arg(char **tab, t_env *envir);
void			ft_cd_tild(t_env *envir, char *tab);

void			ft_echo_helper(t_env *envir, char **tab);
void			ft_echo_builtin(t_env *envir, char **tab);
void			ft_echo_dolss(t_env *envir, char *str);

void			ft_setenv_builtin(t_env *env, char *left, char *right, int i);
void			ft_env_builtin(t_env *envir, char **tab);
void			ft_unsetenv_builtin(t_env *envir, char *del);
void			ft_unset_helper(char *str, char *str_tmp);
int				ft_move_dir(t_env *envir, char *str);
int				col_number(void);

void			ft_command_parsing(t_env *envir, char **tab);

void			ft_free(char **tab_f, char **tab, t_env *env, char *str);

#endif
