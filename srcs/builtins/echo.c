/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:01:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/31 23:17:11 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_echo(char **tokens)
{
	int	i;
	int	menos_n;

	i = 0;
	menos_n = 0;
	if (tokens[1] && ft_strcmp(tokens[1], "-n") == 0)
	{
		i++;
		menos_n++;
	}
	i++;
	while (tokens[i])
	{
		ft_putstr_fd(tokens[i], STDOUT_FILENO);
		if (tokens[++i])
			ft_putchar_fd(' ', STDOUT_FILENO);
	}
	if (menos_n == 0)
		ft_putchar_fd('\n', STDOUT_FILENO);
	return (0);
}
