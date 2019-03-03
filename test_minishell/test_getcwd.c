/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_getcwd.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:34:54 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/02 13:40:07 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <unistd.h>
#include <stdlib.h>
#include <limits.h>

int		main(void)
{
	char *buff;

	buff = ft_strnew(PATH_MAX);
	buff = getcwd(buff, PATH_MAX);
	ft_printf("%s", buff);
	free(buff);
	return (0);
}
