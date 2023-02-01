/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:57:51 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/01 22:19:58 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(char *str)
{
	char	**commands;

	commands = ft_split(str, ' ');
	if (!str || !commands)
		return (1);
	if (ft_strcmp(commands[0], "pwd") == 0)
		return (ft_pwd());
	if (ft_strcmp(str, "env") == 0)
		return (ft_env(g_c.env));
	// if (ft_strncmp(str[0], "exit\0", 5) == 0)
	// 	return (ft_exit(&tokens[1], t));
	if (ft_strcmp(commands[0], "cd") == 0)
		return (ft_cd(commands, g_c.env));
	if (ft_strcmp(commands[0], "echo") == 0)
		return (ft_echo(commands));
	if (ft_strcmp(commands[0], "export") == 0)
		return (ft_export(g_c.env, commands));
	if (ft_strcmp(commands[0], "unset") == 0)
		return (ft_unset(g_c.env, commands));
	else
		return (1);
}
