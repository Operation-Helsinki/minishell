/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/07 18:47:36 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <readline/readline.h>
#include <readline/history.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

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
	unsigned char *command_buf;
	
	while(1)
	{
		command_buf = readline("\033[0;36mShellhinki> \033[0m");
		if(strlen(command_buf)>0) { add_history(command_buf); }
		if(!strcmp(command_buf, "ifconfig")) { system("ifconfig"); }
		else if(!strcmp(command_buf, "date")) { system("date"); }
		else if(!strcmp(command_buf, "ls")) { system("ls"); }
		else if(!strcmp(command_buf, "hola")) { system("say hola, me llamo Shellhinki!"); }
		else if(!strcmp(command_buf, "exit") || !strcmp(command_buf, "quit") || !strcmp(command_buf, "e") || !strcmp(command_buf, "q")) { break; }
		else if (!command_buf){ exit(EXIT_SUCCESS); }
	}
}
//gcc readline.c -lreadline -o shell