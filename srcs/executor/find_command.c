/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:26:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/18 22:02:36 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(void)
{
	int	i;

	i = 0;
	while (g_c.env[i])
	{
		if (ft_strncmp(g_c.env[i], "PATH=", 5) == 0)
			return (g_c.env[i] + 5);
		i++;
	}
	ft_print_error("There is no PATH defined in the environment");
	return (0);
}

char	*only_path(char *cmd)
{
	int			i;
	char		**env_paths;
	char		*path;
	char		*path_cmd;
	const char	*env;

	env = check_path();
	env_paths = ft_split(env, ':');
	i = 0;
	while (env_paths[i])
	{
		path = ft_strjoin(env_paths[i], "/");
		path_cmd = ft_strjoin(path, cmd);
		free(path);
		if (access(path_cmd, X_OK) == 0)
		{
			ft_free_matrix(env_paths);
			return (path_cmd);
		}
		free(path_cmd);
		i++;
	}
	ft_free_matrix(env_paths);
	ft_perror(cmd);
	return (EXIT_SUCCESS);
}

void	ft_exec(const char *argv)
{
	char	**cmd;
	char	*path;

	cmd = ft_split(argv, SPACE);
	path = only_path(cmd[0]);
	if (execve(path, cmd, g_c.env) == -1)
		ft_perror("");
}
