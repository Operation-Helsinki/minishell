/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cmd_type.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/16 05:11:14 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/16 06:58:12 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	cmd_is_builtin(char *cmd)
{
	int			i;
	int			type;
	char		*path;
	char		**splited;
	static char	*symbols[] = {"pwd", "env", "cd", "echo", "export",
		"unset", NULL};

	if (!cmd)
		return (0);
	path = NULL;
	splited = ft_split(cmd, SPACE);
	free((void *)cmd);
	if (splited == NULL)
		exit_failure("malloc", NULL, 1);
	path = splited[0];
	type = OTHER;
	i = -1;
	while (symbols[++i])
		if (ft_strcmp(path, symbols[i]) == 0)
			type = BUILTIN;
	return (type);
}

int	cmd_is_stdlib(char *argv)
{
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = ft_split(argv, SPACE);
	free((void *)argv);
	if (cmd == NULL)
		exit_failure("malloc", NULL, 1);
	path = cmd[0];
	if (cmd[0][0] != '/' && cmd[0][0] != '.')
	{
		path = only_path(cmd[0]);
		if (!path)
			return (OTHER);
	}
	return (STDLIB);
}

int	what_cmd(char *argv)
{
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = ft_split(argv, SPACE);
	if (cmd == NULL)
		exit_failure("malloc", NULL, 1);
	path = cmd[0];
	if (cmd_is_builtin(path) == BUILTIN)
		return (BUILTIN);
	if (cmd_is_stdlib(path) == STDLIB)
		return (STDLIB);
	else
		return (OTHER);
}
