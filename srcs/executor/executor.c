/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:24 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/01 22:23:01 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void piperrak(int i)
{
	printf("i: %d\n", i);
	builtins(g_c.tokens[i/2]);
	
	// pid = fork();
	// if (pid < 0)
	// 	return (exit_fatal());
	// else if (pid == 0)
	// {
	// 	if (cmd->type == TYPE_PIPE
	// 		&& dup2(cmd->pipes[SIDE_IN], STDOUT) < 0)
	// 		return (exit_fatal());
	// 	if (cmd->previous && cmd->previous->type == TYPE_PIPE
	// 		&& dup2(cmd->previous->pipes[SIDE_OUT], STDIN) < 0)
	// 		return (exit_fatal());
	// 	if ((ret = execve(cmd->args[0], cmd->args, env)) < 0)
	// 	{
	// 		show_error("error: cannot execute ");
	// 		show_error(cmd->args[0]);
	// 		show_error("\n");
	// 	}
	// 	exit(ret);
	// }



	
	// int i;
	// pid_t pid;
	
	// i = 0;
	// if (pipe(g_c.fd) == 0)
	// {
	// 	pid = fork();
	// 	if (pid == 0)
	// 	{
	// 		printf("ESTO ES EL HIJO\n");
	// 		if (g_c.count_pipes != 0)
	// 			dup2(g_c.fd[WRITE_END], STDOUT_FILENO);
	// 		builtins(g_c.tokens[0]); 
	// 		// exit(0);
	// 		g_c.count_pipes--;
	// 	}
	// 	else if (pid > 0)
	// 	{
	// 		//waitpid(pid, &status, 0);
	// 		//t->status = (status / 256);
	// 		close(g_c.fd[WRITE_END]);
	// 		dup2(g_c.fd[READ_END], STDIN_FILENO);
	// 		//close(g_c.fd[READ_END]);
	// 	}
	// }
	// else
	// 	exit(-1);
}
