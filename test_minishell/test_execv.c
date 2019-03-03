/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_execv.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 14:43:34 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/02 16:41:30 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <unistd.h>

int		main(int argc, char **argv)
{
	if (argc >= 2)
		execv(argv[1], &argv[1]);
	else
		ft_putstr("shit");
	return (0);
}
