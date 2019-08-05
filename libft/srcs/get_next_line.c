/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 09:37:36 by tlandema          #+#    #+#             */
/*   Updated: 2019/08/05 15:04:59 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <stdlib.h>
#include <unistd.h>
#include "libft.h"

static char	*reading(char **str, char *buff, int fd)
{
	char	*tmp;
	int		ret;

	ret = 1;
	while (!(ft_strchr(*str, '\n')) && ret)
	{
		ret = read(fd, buff, BUFF_SIZE);
		if (ret)
		{
			buff[ret] = '\0';
			tmp = *str;
			if (!(*str = ft_strjoin(*str, buff)))
				return (NULL);
			ft_strdel(&tmp);
		}
	}
	return (*str);
}

static char	*a_line(char **str)
{
	char	*buff;
	char	*line;
	char	*tmp;

	buff = ft_strchr(*str, '\n');
	tmp = NULL;
	if (buff)
	{
		if (!(line = ft_strndup(*str, buff - *str)))
			return (NULL);
		tmp = *str;
		if (!(*str = ft_strdup(buff + 1)))
			return (NULL);
		ft_strdel(&tmp);
	}
	else if (!(line = ft_strdup(*str)))
		return (NULL);
	return (line);
}

static int	clean(char *to_f)
{
	ft_strdel(&to_f);
	return (-1);
}

int			get_next_line(const int fd, char **line)
{
	static char	*str[4864];
	char		*buff[BUFF_SIZE + 1];

	if (fd < 0 || !line || BUFF_SIZE <= 0
			|| read(fd, buff, 0) == -1 || \
			(str[fd] == NULL && !(str[fd] = ft_strnew(0))))
		return (-1);
	if (!(reading(&str[fd], (char *)buff, fd)))
		return (clean(str[fd]));
	if (*str[fd])
	{
		if (!(*line = a_line(&str[fd])))
			return (clean(str[fd]));
		return (1);
	}
	ft_strdel(&str[fd]);
	return (0);
}
