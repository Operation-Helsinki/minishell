/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:37:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/15 20:17:40 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	//char	**environment;

	(void)argc, (void)argv;
	//ft_print_header();
	g_c.environment = ft_get_env(env);
	ft_pwd();
	readline_create(g_c.environment); /*añado input a la funcion*/
	exit(EXIT_SUCCESS);
	return (0);
}
