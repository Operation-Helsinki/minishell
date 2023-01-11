/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:26:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/11 11:29:28 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*check_path(char *str)
{
	char	*env;

	env = getenv(str);
	if (!env)
		ft_print_error("There is no PATH defined in the enviroment");
	return (env);
}

char	*only_path(char *cmd)
{
	int			i;
	char		**env_paths;
	char		*path;
	char		*path_cmd;
	const char	*env;

	env = check_path("PATH");
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
	char		**cmd;
	char		*path;
	extern char	**environ;

	cmd = ft_split(argv, SPACE);
	path = only_path(cmd[0]);
	if (execve(path, cmd, environ) == -1)
		ft_perror("");
}
