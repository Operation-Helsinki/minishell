/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   environment.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 17:35:36 by davgarci          #+#    #+#             */
/*   Updated: 2023/01/12 20:25:53 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	**ft_get_env(char **env)
{
	int		i;
	int		j;
	char	**environment;

	i = 0;
	while (env[i])
		i++;
	environment = (char **)malloc(sizeof(char *) * (i + 1));
	i = 0;
	while (env[i])
	{
		environment[i] = (char *)malloc(sizeof(char) * ft_strlen(env[i]) + 1);
		j = 0;
		while (env[i][j])
		{
			environment[i][j] = env[i][j];
			j++;
		}
		environment[i][j] = '\0';
		i++;
	}
	environment[i] = NULL;
	return (environment);
}
