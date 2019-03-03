/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_chdir.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 13:54:48 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/02 14:06:22 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/libft.h"
#include "includes/ft_printf.h"
#include <unistd.h>


int		main(int argc, char **argv)
{
	int i;

	if (argc == 2)
	{
		i = chdir(argv[1]);
		ft_printf("%d", i);	
	}
	else
		ft_putstr("met UN argument connard");
	return (0);
}
