/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/04 23:42:48 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	read_exit(const char *command_buf)
{
	return (!ft_strcmp(command_buf, "exit")
		|| !ft_strcmp(command_buf, "quit") || !ft_strcmp(command_buf, "e")
		|| !ft_strcmp(command_buf, "q"));
}

void	expand_while(void)
{
	g_c.tok_count = 0;
	while (g_c.tokens[g_c.tok_count])
	{
		g_c.tokens[g_c.tok_count] = expan_token2(g_c.tokens[g_c.tok_count],
				g_c.env);
		if (token_is_symbol(g_c.tokens[g_c.tok_count]))
			g_c.pipas++;
		g_c.tok_count++;
	}
	g_c.tokens[g_c.tok_count] = NULL;
}

void	readline_create(void)
{
	const char	*command_buf;

	while (1)
	{
		command_buf = ft_strtrim((const char *)readline(PROMPT), " ");
		if (!command_buf)
			exit(0);
		if (!*command_buf)
			continue ;
		if (read_exit(command_buf))
			break ;
		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		if (!check_quotes(command_buf))
			continue ;
		g_c.tokens = malloc(sizeof(char *) * (count_tokens(command_buf) + 1));
		store_tokens(command_buf, g_c.tokens);
		if (double_symbols(g_c.tokens) == 1)
			continue ;
		g_c.tokens = tokens_to_pipas(g_c.tokens);
		expand_while();
		pipas_handler();
		ft_free_matrix(g_c.tokens);
	}
}
