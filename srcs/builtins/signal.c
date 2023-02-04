/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 08:26:17 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/04 17:44:50 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	handle_sig(int sig)
{
	if (sig == SIGINT)
	{
		g_c.dolar_q = 130;
		ft_putstr_fd("\n\033[0;32m➜  \033[0;36mShellhinki \033[1;33m✗ \033[0m", 2);
		rl_on_new_line();
		
		//rl_replace_line("", 0);
	}
	else if (sig == SIGQUIT)
		write(2, "\b\b  \b\b", 6);
}

void	sig_init(void)
{
	if (signal(SIGINT, handle_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
	else if (signal(SIGQUIT, handle_sig) == SIG_ERR)
		exit(EXIT_FAILURE);
}

void	execution_signal_hadler(int sig)
{
	if (sig == SIGINT)
	{
		free(g_c.tokens);
		g_c.dolar_q = 130;
		write(2, "\n", 1);
	}
	else if (sig == SIGQUIT)
	{
		g_c.dolar_q = 131;
		ft_putstr_fd("Exit, bye\n", 2);
	}
}

void	execution_signal_init(void)
{
	if (signal(SIGINT, execution_signal_hadler) == SIG_ERR)
		exit(EXIT_FAILURE);
	else if (signal(SIGQUIT, execution_signal_hadler) == SIG_ERR)
		exit(EXIT_FAILURE);
}