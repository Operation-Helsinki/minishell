/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:24 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/03 23:38:04 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	pipas_handler(void)
{
	int	i;
	int	status;
	int	is_builtin;
	int	pid;

	i = 0;
	if (g_c.pipas == 0)
	{
		is_builtin = builtins(g_c.tokens[i]);
		if (is_builtin == NONE)
		{
			pid = fork();
			if (pid == 0)
				ft_exec(g_c.tokens[i]);
			waitpid(-1, &status, 0);
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
		i = 0;
		while (i < g_c.pipas + 1)
		{
			waitpid(-1, &status, 0);
			i++;
		}
	}
}

void piperrak(int i)
{
	pid_t pid;

	if (pipe(g_c.fd) == -1)
		exit(-1);
	pid = fork();
	if (pid == 0)
	{
		if (i != g_c.pipas * 2)
			dup2(g_c.fd[WRITE_END], STDOUT_FILENO);
		if (builtins(g_c.tokens[i]) != NONE)
			exit(0);
		ft_exec(g_c.tokens[i]);
	}
	else
	{
		dup2(g_c.fd[READ_END], STDIN_FILENO);
		if (g_c.fd[WRITE_END] != STDIN_FILENO)
			close(g_c.fd[WRITE_END]);
		if (g_c.fd[READ_END] != STDOUT_FILENO)
			close(g_c.fd[READ_END]);
	}
}
