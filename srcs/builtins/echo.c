/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   echo.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:01:54 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/15 19:10:48 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"



int	ft_echo(char **tokens)
{
	int		i;
	int		menos_n;

	menos_n = 0;
	i = 0;
	if (tokens[i] && ft_strncmp("-n", tokens[i], 2) == 0)
	{
		i++;
		menos_n++;
	}
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
