/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_wait2.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/02 17:59:04 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/03 11:24:19 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include<stdio.h> 
#include<sys/wait.h> 
#include<unistd.h> 

int main(int argc, char **argv) 
{ 
	if (argc >= 2)
	{
		if (fork() == 0) 
			printf("HC: hello from child\n"); 
		else
		{ 
			printf("HP: hello from parent\n"); 
			wait(NULL); 
			printf("CT: child has terminated\n"); 
		} 
		printf("Bye\n");
	}
	return (0); 
} 

/* fork return the pid of the child in the parent process, so it goes in else,
 * it prints out hello then has to wait for the child process, 
 * fork has returned 0 in the child process so it prints hello from child
 * then it prints out bye and as the child process returns 0
 * the wait for the parent process stops, so it prints out child has terminated 
 * and then it prints bye and the parent process returns 0.*/
