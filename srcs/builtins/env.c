/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:01:57 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/01 21:50:18 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_env(char **matrix)
{
	int	i;

	i = -1;
	while (matrix[++i])
		printf("%s\n", matrix[i]);
}

int	ft_env(char **env)
{
	ft_print_env(env);
	return (0);
}
