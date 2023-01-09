/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/09 11:17:16 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#include "minishell.h"

// int	main(void)
// {
// 	unsigned char *command_buf;
	
// 	while(1)
// 	{
// 		command_buf = readline("\033[0;36mShellhinki> \033[0m");
// 		if(strlen(command_buf)>0) { add_history(command_buf); }
// 		if(!strcmp(command_buf, "ifconfig")) { system("ifconfig"); }
// 		else if(!strcmp(command_buf, "date")) { system("date"); }
// 		else if(!strcmp(command_buf, "ls")) { system("ls"); }
// 		else if(!strcmp(command_buf, "hola")) { system("say hola, me llamo Shellhinki!"); }
// 		else if(!strcmp(command_buf, "exit") || !strcmp(command_buf, "quit") || !strcmp(command_buf, "e") || !strcmp(command_buf, "q")) { break; }
// 		else if (!command_buf){ exit(EXIT_SUCCESS); }
// 	}	
// 	return (0);	
// }

void	readline_create(void)
{
	const char *command_buf;

	while(1)
	{
		command_buf = (const char *)readline("\033[0;36mShellhinki> \033[0m");
		if (!command_buf) { exit(0); }
		if(ft_strlen(command_buf)>0) { add_history(command_buf); }
		if(!ft_strcmp(command_buf, "ifconfig")) { system("ifconfig"); }
		else if(!ft_strcmp(command_buf, "date")) { system("date"); }
		else if(!ft_strcmp(command_buf, "ls")) { system("ls"); }
		else if(!ft_strcmp(command_buf, "hola")) { system("say hola, me llamo Shellhinki!"); }
		else if(!ft_strcmp(command_buf, "exit") || !ft_strcmp(command_buf, "quit") ||
			!ft_strcmp(command_buf, "e") || !ft_strcmp(command_buf, "q")) { break; }
		else if (!command_buf){ exit(EXIT_SUCCESS); }
	}
}
//gcc readline.c -lreadline -o shell