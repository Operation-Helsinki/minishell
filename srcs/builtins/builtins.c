/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:57:51 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/04 22:11:50 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	builtins(char *str)
{
	char	**commands;

	commands = ft_split(str, SPACE);
	if (!str || !commands)
		return (1);
	else if (ft_strcmp(commands[0], "pwd") == 0)
		return (ft_pwd(commands));
	else if (ft_strcmp(str, "env") == 0)
		return (ft_env(g_c.env, commands));
	else if (ft_strcmp(commands[0], "cd") == 0)
		return (ft_cd(g_c.env, commands));
	else if (ft_strcmp(commands[0], "echo") == 0)
		return (ft_echo(commands));
	else if (ft_strcmp(commands[0], "export") == 0)
		return (ft_export(g_c.env, commands));
	else if (ft_strcmp(commands[0], "unset") == 0)
		return (ft_unset(g_c.env, commands));
	else
	{
		free(commands);
		return (42);
	}
}
