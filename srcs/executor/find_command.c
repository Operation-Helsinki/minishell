/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_command.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:26:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/14 21:58:29 by psegura-         ###   ########.fr       */
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

void	exit_failure(char *err_msg, char **to_free)
{
	perror(err_msg);
	ft_free_matrix(to_free);
	exit(EXIT_FAILURE);
}

void	ft_exec(const char *argv)
{
	char	**cmd;
	char	*path;

	path = NULL;
	cmd = ft_split(argv, SPACE);
	free((void *)argv);
	if (cmd == NULL)
		exit_failure("malloc", NULL);
	path = cmd[0];
	if (cmd[0][0] != '/' && cmd[0][0] != '.')
		path = only_path(cmd[0]);
	printf("PATH: [%s]\n", path);
	execve(path, cmd, g_c.env);
	exit_failure(path, cmd);
}
