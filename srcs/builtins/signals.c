/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signals.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 23:37:32 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/16 09:11:55 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

// void	handle_sig(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		g_c.dolar_q = 130;
// 		write(1, "\n", 1);
// 		rl_on_new_line();
// 		rl_replace_line("", 0);
// 		rl_redisplay();
// 	}
// 	else if (sig == SIGQUIT)
// 	{
// 		write(2, "\b\b  \b\b", 6);
// 		// printf("ESTO es Ctrl + /\n");
// 		// rl_redisplay();
// 		return ;
// 	}
// }

// void	sig_init(void)
// {
// 	if (signal(SIGINT, handle_sig) == SIG_ERR)
// 		exit(EXIT_FAILURE);
// 	else if (signal(SIGQUIT, handle_sig) == SIG_ERR)
// 		exit(EXIT_FAILURE);
// }

// void	execution_signal_hadler(int sig)
// {
// 	if (sig == SIGINT)
// 	{
// 		free(g_c.tokens);
// 		g_c.dolar_q = 130;
// 		write(2, "\n", 1);
// 	}
// 	else if (sig == SIGQUIT)
// 	{
// 		g_c.dolar_q = 131;
// 		ft_putstr_fd("Exit, bye\n", 2);
// 	}
// }

// void	execution_signal_init(void)
// {
// 	if (signal(SIGINT, execution_signal_hadler) == SIG_ERR)
// 		exit(EXIT_FAILURE);
// 	else if (signal(SIGQUIT, execution_signal_hadler) == SIG_ERR)
// 		exit(EXIT_FAILURE);
// }

void	signal_parent(int signal)
{
	if (signal == SIGINT)
	{
		write(1, "\n", 1);
		rl_on_new_line();
		rl_replace_line("", 0);
		rl_redisplay();
		g_c.dolar_q = 130;
	}
}

void	signal_heredoc(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_IGN);
}

void	signal_child(void)
{
	signal(SIGINT, SIG_DFL);
	signal(SIGQUIT, SIG_DFL);
}

void	signal_ignore(void)
{
	signal(SIGINT, SIG_IGN);
	signal(SIGQUIT, SIG_IGN);
}

void	manage_signal(void)
{
	signal(SIGINT, signal_parent);
	signal(SIGQUIT, SIG_IGN);
}
