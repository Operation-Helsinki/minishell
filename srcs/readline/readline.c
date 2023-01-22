/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/22 20:25:25 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readline_create(void)
{
	const char	*command_buf;
	//char		*expanded_token;

	while (1)
	{
		//int i;
		g_c.dolar_q = 123;
		
		command_buf = (const char *)readline(PROMPT); //hehe
		if (!command_buf)
			exit(0);
		g_c.tokens = malloc(sizeof(char *) * (count_tokens(command_buf) + 1));
		store_tokens(command_buf, g_c.tokens);
		printf("-> imput\n");
		ft_print_matrix(g_c.tokens);
		g_c.tok_count = 0;
		while (g_c.tokens[g_c.tok_count])
		{
			printf("token al entrar [%s]\n", g_c.tokens[g_c.tok_count]);
			g_c.tokens[g_c.tok_count] = expan_token2(g_c.tokens[g_c.tok_count], g_c.env);
			printf("token al salir [%s]\n", g_c.tokens[g_c.tok_count]);
			g_c.tok_count++;
		}
		printf("-> out_put\n");
		// ft_print_matrix(g_c.tokens);
		check_quotes(command_buf);
		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		// ft_exec(command_buf);
		if (!ft_strcmp(command_buf, "exit")
			|| !ft_strcmp(command_buf, "quit") || !ft_strcmp(command_buf, "e")
			|| !ft_strcmp(command_buf, "q"))
			break ;
	}
}

		// ft_print_matrix(g_c.env);
		//ft_exec(command_buf);
		//map_readline(command_buf);
		//system("leaks -q minishell");
		// system("leaks -q minishell");