/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:33:26 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/22 16:00:14 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_env
{
	char	**env;
	char	*old_pwd;
	char	*tmp_pwd;
	int		cat;
	int		r_o_g;
}				t_env;

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

void			ft_command_parsing(t_env *envir, char **tab);

#endif
