/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:37:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/05 21:18:55 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(int argc, char **argv, char **env)
{
	(void)argc, (void)argv;
	ft_memset(&g_c, 0, sizeof(t_cosas));
	g_c.env = ft_get_env(env);
	g_c.dolar_q = 42;
	sig_init();
	readline_create();
	exit(EXIT_SUCCESS);
	return (0);
}

	// ft_print_header();
	// system("leaks -q minishell");