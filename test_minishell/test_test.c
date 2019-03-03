/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_test.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tlandema <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2019/03/03 11:45:53 by tlandema          #+#    #+#             */
/*   Updated: 2019/03/03 13:58:47 by tlandema         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdio.h>
#include <sys/wait.h>

int main(void)
{
	extern char **environ;
	environ[0] = "test";
	char *argv[] = { "/bin/sh", "-c", "env", 0 };
	execve(argv[0], argv, environ);
	wait(NULL);
	wait(NULL);
	wait(NULL);
	wait(NULL);
	while(1) { };
	return -1;
}
