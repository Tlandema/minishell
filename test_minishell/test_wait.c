/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wait.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:57:01 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/03 14:06:50 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h> 
#include <stdlib.h> 
#include <sys/wait.h> 
#include "includes/libft.h"
#include <unistd.h> 

int main() 
{ 
	pid_t cpid; 
	char truc;
	if (fork() == 0) 
		exit(0);           /* terminate child */
	else
		cpid = wait(NULL); /* reaping parent */
	printf("Parent pid = %d\n", getpid()); 
	printf("Child pid = %d\n", cpid); 
	while (1) 
	{
		read(0, &truc, 1);
		ft_putstr("ok");
	}
	return (0); 
}
