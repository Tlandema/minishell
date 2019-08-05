/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dollars.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/08/02 10:09:43 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/04 14:56:03 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static char	*ft_free_two_str(char *str, char *str1)
{
	ft_strdel(&str);
	ft_strdel(&str1);
	return (NULL);
}

static char	*ft_replace_a_dolls(char *str, int i)
{
	char	*new;
	char	*tmp;
	char	*word;
	int		j;
	int		k;

	j = i + 1;
	k = 0;
	while (str[++i] && (str[i] != ' ' && str[i] != '\'' && str[i] != '\"'))
		k++;
	if (!(word = ft_strndup(&str[j], k)))
		return (NULL);
	tmp = ft_get_v_env(word);
	if (!(new = ft_strnew(PATH_MAX)))
		return (ft_free_two_str(word, tmp));
	k = -1;
	while (++k < j - 1)
		new[k] = str[k];
	if (tmp)
		ft_strcat(new, tmp);
	ft_strcat(new, &str[i]);
	ft_strdel(&tmp);
	ft_strdel(&word);
	ft_strdel(&str);
	return (new);
}

static char	*ft_replace_a_tild(char *str, int i)
{
	char	*tmp;
	char	*new;
	int		j;

	if (!(new = ft_strnew(PATH_MAX)))
		return (NULL);
	if (!(tmp = ft_get_v_env("HOME")))
		return (str);
	j = -1;
	while (++j < i)
		new[j] = str[j];
	i++;
	ft_strcat(new, tmp);
	ft_strcat(new, &str[i]);
	ft_strdel(&str);
	ft_strdel(&tmp);
	return (new);
}

char		*ft_dols_tild(char *str)
{
	int		i;

	i = -1;
	while (str[++i])
	{
		if (i > PATH_MAX - 100)
			return (str);
		if (str[i] == '$' && (str[i + 1] != ' ' && str[i + 1] != '\0'))
		{
			if (!(str = ft_replace_a_dolls(str, i)))
				return (NULL);
		}
		else if (str[i] == '~')
			if (!(str = ft_replace_a_tild(str, i)))
				return (NULL);
	}
	return (str);
}
