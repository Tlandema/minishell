/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_minishell.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/04 16:33:26 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/05 17:49:15 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

typedef struct	s_env
{
	char **env;
}				t_env;

void	ft_cd_builtin(char **tab);
void	ft_puterror(int i, char *name);
char	**ft_create_environ(char **envp);
void	ft_setenv_builtin(t_env *env, char *left, char *right, int i);
char	**copy_tab(t_env *envir);
void	ft_env_builtin(char **env);
void	ft_unsetenv_builtin(t_env *envir, char *del);

#endif
