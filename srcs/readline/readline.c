/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/01 22:21:06 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void expand_while()
{
	while (g_c.tokens[g_c.tok_count])
	{
		g_c.tokens[g_c.tok_count] = expan_token2(g_c.tokens[g_c.tok_count],
				g_c.env);
		if (ft_strcmp(g_c.tokens[g_c.tok_count], "|") == 0)
			g_c.pipas++;
		g_c.tok_count++;
	}
	g_c.tokens[g_c.tok_count] = NULL;
}

void	readline_create(void)
{
	const char	*command_buf;
	// int			i;
	
	while (1)
	{
		g_c.dolar_q = 123;
		command_buf = (const char *)readline(PROMPT);
		// command_buf = "echo hola";
		if (!command_buf)
			exit(0);
		if (!check_quotes(command_buf))
		{
			printf("THE QUOTES ARE NOT CLOSED\n");
			continue ;
		}
		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		g_c.tokens = malloc(sizeof(char *) * (count_tokens(command_buf) + 1));
		store_tokens(command_buf, g_c.tokens);
		if (double_symbols(g_c.tokens) == 1)
		{
			printf("TO MANY SYMBOLS IN A ROW\n");
			continue ;
		}
		g_c.tokens = tokens_to_pipas(g_c.tokens);
		ft_print_matrix(g_c.tokens, "before");
		g_c.tok_count = 0;
		/* Function that expands the tokens while there are tokens to expand.*/
		expand_while();
		ft_print_matrix(g_c.tokens, "after");
		builtins(g_c.tokens[0]);
		// i=0;
		// while (i<g_c.pipas)
		// {
		// 	pipe(g_c.fd);
		// 	printf("fd1 %d, fd2 %d\n", g_c.fd[0], g_c.fd[1]);
		// 	piperrak(i);
		// 	i++;
		// }
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