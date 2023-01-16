/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/14 13:22:23 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readline_create(char **environment)
{
	const char	*command_buf;
	char		*not_expanded_token;
	char		*expanded_token;
	//tokens = tokens();

	not_expanded_token = "HOLA $USER $ $HOLA$USER $ADIOS $'";
	while (1)
	{
		command_buf = (const char *)readline(PROMPT);
		if (!command_buf)
			exit(0);
		expanded_token = expan_token(not_expanded_token, environment);
		// system("leaks -q minishell");
		printf("EX: %s\n", expanded_token);
		check_quotes(command_buf);
		map_readline(command_buf);
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
