/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:24 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/22 18:54:41 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	which_type(int i)
{
	int	type;

	type = what_cmd(g_c.tokens[i]);
	printf("type: %i\n", type);
	if (type == BUILTIN)
	{
		g_c.dolar_q = builtins(g_c.tokens[i]);
		exit(0);
	}
	else if (type == STDLIB)
		ft_exec(g_c.tokens[i]);
	else
		cmd_not_found(g_c.tokens[i]);
	exit(EXIT_SUCCESS);
}

int	ft_ijump(int i)
{
	i++;
	if (g_c.tokens[i])
	{
		while (ft_strcmp(g_c.tokens[i], "|") != 0)
			i++;
		return(i);
	}
	return (197);
}

void	pipas_handler(void)
{
	int	i;
	int	pid2 = 2;
	int	fd_read;

	int	status;
	int	pid;
	i = 0;
	printf("Numero de tokens: %d\n", g_c.tok_count);
	pid = fork();
	if (pid == 0)
	{
	//printf("hello: %s %s %s\n", g_c.tokens[0], g_c.tokens[1], g_c.tokens[2]);
	while (i < g_c.tok_count)
	{
		pipe(g_c.fd);
		pid2 = fork();
		if (pid2 == 0)
		{
			//write(2, "hola1", 5);
			if (i == 0 && g_c.pipas > 0)
			{
				//write(2, "hola2", 5);
				//printf("%d %d\n", g_c.fd[0], g_c.fd[1]);
				dup2(g_c.fd[WRITE_END], 1);
				fd_read = g_c.fd[READ_END];
			}
			else if (i == g_c.tok_count - 1)
			{
				//write(2, &g_c.fd[0], 1);
				//printf("%d %d\n", g_c.fd[0], g_c.fd[1]);
				//write(2, "hola3", 5);
				dup2(g_c.fd[READ_END], 0);
				dup2(0, g_c.fd[WRITE_END]);
			}
			else if (g_c.pipas > 0)
			{
				//write(2, "hola4", 5);
				dup2(g_c.fd[READ_END], 0);
				dup2(g_c.fd[WRITE_END], g_c.fd[READ_END]);
			}
			which_type(i);
			fd_read = g_c.fd[READ_END];
		}
		i = ft_ijump(i);
		i++;
	}
	}
	i = 0;
		waitpid(-1, &status, 0);
	g_c.dolar_q = status;
}

//void	piperrak(int i)
//{
//	pid_t	pid;
//
//	if (pipe(g_c.fd) == -1)
//		exit(-1);
//	pid = fork();
//	if (pid == 0)
//	{
//		if (i != g_c.pipas * 2)
//			dup2(g_c.fd[WRITE_END], STDOUT_FILENO);
//		if (builtins(g_c.tokens[i]) != NONE)
//			exit(0);
//		ft_exec(g_c.tokens[i]);
//	}
//	else
//	{
//		dup2(g_c.fd[READ_END], STDIN_FILENO);
//		if (g_c.fd[WRITE_END] != STDIN_FILENO)
//			close(g_c.fd[WRITE_END]);
//		if (g_c.fd[READ_END] != STDOUT_FILENO)
//			close(g_c.fd[READ_END]);
//	}
//}

	//  ls | wc

	// else
	// {
	// 	dup2(g_c.fd[READ_END], STDIN_FILENO);
	// 	if (g_c.fd[WRITE_END] != STDIN_FILENO)
	// 		close(g_c.fd[WRITE_END]);
	// 	if (g_c.fd[READ_END] != STDOUT_FILENO)
	// 		close(g_c.fd[READ_END]);
	// }

	//FOR LATER -> IMPleMENT PIPES

	//ELSE IF THERE IS PIPES
	// {
	// 	while (i <= g_c.pipas * 2)
	// 	{
	// 		if (!token_is_symbol(g_c.tokens[i]))
	// 			piperrak(i);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	while (i < g_c.pipas + 1)
	// 	{
	// 		waitpid(-1, &status, 0);
	// 		i++;
	// 	}
	// }