/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/31 19:39:04 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readline_create(void)
{
	const char	*command_buf;
	// char **jaja;

	while (1)
	{
		g_c.dolar_q = 123;
		command_buf = (const char *)readline(PROMPT);
		if (!command_buf)
			exit(0);
		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		g_c.tokens = malloc(sizeof(char *) * (count_tokens(command_buf) + 1));
		store_tokens(command_buf, g_c.tokens);
		ft_print_matrix(g_c.tokens, "before");
		if (double_symbols(g_c.tokens) == 1)
		{
			printf("TO MANY SYMBOLS IN A ROW\n");
			continue ;
		}
		g_c.tokens = tokens_to_pipas(g_c.tokens);
		g_c.tok_count = 0;
		while (g_c.tokens[g_c.tok_count])
		{
			g_c.tokens[g_c.tok_count] = expan_token2(g_c.tokens[g_c.tok_count],
					g_c.env);
			g_c.tok_count++;
		}
		g_c.tokens[g_c.tok_count] = NULL;
		g_c.count_pipes = 2;
		//while pipas>0
		//piperrak();
		//pipas--
		ft_print_matrix(g_c.tokens, "after");
		check_quotes(command_buf);
		if (!ft_strcmp(command_buf, "exit")
			|| !ft_strcmp(command_buf, "quit") || !ft_strcmp(command_buf, "e")
			|| !ft_strcmp(command_buf, "q"))
			{			
				free((void *)command_buf);
				break ;
			}
	}
}

// ft_print_matrix(g_c.env);
//ft_exec(command_buf);
//map_readline(command_buf);
// system("leaks -q minishell");