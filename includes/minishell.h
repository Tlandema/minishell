/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:33:26 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/06 02:04:27 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_env
{
	char **env;
}				t_env;

int		ft_check_env(t_env *envir, char *check);
void	ft_puterror(int i, char *name);
void	ft_create_environ(char **envp, t_env *envir);
char	**copy_tab(t_env *envir);

void    ft_echo_builtin(t_env *envir, char **tab);
void	ft_cd_builtin(char **tab);
void	ft_setenv_builtin(t_env *env, char *left, char *right, int i);
void	ft_env_builtin(char **environ);
void	ft_unsetenv_builtin(t_env *envir, char *del);

void	ft_command_parsing(t_env *envir, char **tab);

#endif
