/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:24 by davgarci          #+#    #+#             */
/*   Updated: 2023/01/30 00:25:36 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void piperrak(void)
{
	int i;
	pid_t pid;
	
	i = 0;
	if (pipe(g_c.fd) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (g_c.count_pipes == 0)
				dup2(g_c.fd[WRITE_END], STDOUT_FILENO);
			builtins(g_c.tokens); 
			exit(0);
			g_c.count_pipes--;
		}
		else if (pid > 0)
		{
			//waitpid(pid, &status, 0);
			//t->status = (status / 256);
			close(g_c.fd[WRITE_END]);
			dup2(g_c.fd[READ_END], STDIN_FILENO);
			close(g_c.fd[READ_END]);
		}
	}
	else
		exit(-1);
	
	
}