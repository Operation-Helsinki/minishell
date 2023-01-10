/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/10 11:20:32 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	readline_create(void)
{
	const char	*command_buf;

	while (1)
	{
		command_buf = (const char *)readline("\033[0;36mShellhinki> \033[0m");
		if (!command_buf)
			exit(0);
		map_readline(command_buf);
		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		if (!ft_strcmp(command_buf, "ifconfig"))
			system("ifconfig");
		else if (!ft_strcmp(command_buf, "date"))
			system("date");
		else if (!ft_strcmp(command_buf, "ls"))
			system("ls");
		else if (!ft_strcmp(command_buf, "hola"))
			system("say hola, me llamo Shellhinki!");
		else if (!ft_strcmp(command_buf, "exit")
			|| !ft_strcmp(command_buf, "quit") || !ft_strcmp(command_buf, "e")
			|| !ft_strcmp(command_buf, "q"))
			break ;
	}
}

//gcc readline.c -lreadline -o shell