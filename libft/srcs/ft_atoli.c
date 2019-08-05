/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoli.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/01/05 08:14:00 by tlandema          #+#    #+#             */
/*   Updated: 2019/06/12 04:03:29 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

long int	ft_atoli(const char *str)
{
	int			i;
	long long	neg;
	long long	num;

	i = 0;
	neg = 1;
	num = 0;
	while ((str[i] >= 9 && str[i] <= 13) || str[i] == ' ')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			neg *= -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		num = num * 10 + (str[i] - '0') * neg;
		i++;
	}
	return ((long int)num);
}
