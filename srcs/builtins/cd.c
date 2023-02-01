/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   cd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:01:49 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/31 23:10:44 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

/**
 * It changes the current working directory to the one specified by the user.
 * 
 * @param tokens An array of strings, each string is a token from the command
 * line.
 * @param env The environment variables.
 * 
 * @return The return value of the function is the return value of the last
 * command executed.
 */
int	ft_cd(char **tokens, char **env)
{
	char		*path;
	int			i;

	i = 1;
	path = tokens[i];
	if (!path)
	{	
		while (env[i])
		{
			if (ft_strncmp("HOME=", env[i], 5) == 0)
				chdir(env[i] + 5);
			i++;
		}
	}
	else if (chdir(path) == -1)
		printf("ESTO NO EXISTE\n");
	return (0);
}

		// ft_print_error(*tokens);
	// else
	// {
	// 	i = 0;
	// 	while (tokens[i])
	// 	{
	// 		path = ft_strjoin(path, tokens[i]);
	// 		i++;
	// 		if (tokens[i])
	// 			path = ft_strjoin(path, " ");
	// 		free(path);
	// 	}
	// }