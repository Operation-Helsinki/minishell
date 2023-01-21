/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 22:14:35 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readline_create(void)
{
	const char	*command_buf;
	char		*not_expanded_token;
	char		*expanded_token;

	// tokens = tokens();
	not_expanded_token = "\"$USER'$USER'\"";
	while (1)
	{
		command_buf = (const char *)readline(PROMPT);
		if (!command_buf)
			exit(0);
		g_c.tokens = malloc(sizeof(char *) * (count_tokens(command_buf) + 1));
		store_tokens(command_buf, g_c.tokens);
		ft_print_matrix(g_c.tokens, "tokens ->");
		expanded_token = expan_token(not_expanded_token, g_c.env);
		printf("EX: %s\n", expanded_token);
		check_quotes(command_buf);
		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		// ft_exec(command_buf);
		if (!ft_strcmp(command_buf, "exit")
			|| !ft_strcmp(command_buf, "quit") || !ft_strcmp(command_buf, "e")
			|| !ft_strcmp(command_buf, "q"))
			break ;
		//system("leaks -q minishell");
	}
}
