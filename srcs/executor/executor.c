/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:24 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/03 03:52:08 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipas_handler(void)
{
	int	i;
	int	pid;
	int	status;
	
	i = 0;
	// printf("N_pipas: [%d]\n", g_c.pipas);
	if (g_c.pipas == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (builtins(g_c.tokens[i]) != 42)
				exit(0);
			else
			{
				// ft_putstr_fd("ft_exec 1 cmd\n", 2);
				ft_exec(g_c.tokens[i]);
			}
		}
		else
		{
			// ft_putstr_fd("father 1 cmd\n", 2);
			waitpid(pid, &status, 0);
			dup2(g_c.fd[READ_END], STDIN_FILENO);
			close(g_c.fd[WRITE_END]);
			close(g_c.fd[READ_END]);
		}
	}
	else
	{
		while (i <= g_c.pipas * 2)
		{
			if (!token_is_symbol(g_c.tokens[i]))
				piperrak(i);
			i++;
		}
	}
}

void piperrak(int i)
{
	pid_t pid;
	int status;

	if (pipe(g_c.fd) == 0)
	{
		pid = fork();
		if (pid == 0)
		{
			if (i != g_c.pipas * 2)
				dup2(g_c.fd[WRITE_END], STDOUT_FILENO);
			if (builtins(g_c.tokens[i]) != 42)
				exit(0);
			else
			{
				// ft_putstr_fd("\nft_exec +1 cmd\n", 2);
				ft_exec(g_c.tokens[i]);
			}
		}
		else
		{
			waitpid(pid, &status, 0);
			// ft_putstr_fd("\npadre +1 cmd\n", 2);
			dup2(g_c.fd[READ_END], STDIN_FILENO);
			close(g_c.fd[WRITE_END]);
			close(g_c.fd[READ_END]);
		}
	}
	else
		exit(-1);
}
