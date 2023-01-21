/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 02:37:36 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 03:08:13 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./inc/libft.h"

int	main(int argc, char **argv, char **env)
{
	char	**later;

	ft_print_matrix(env, "env");
	later = ft_delete_row_matrix(env, 10);
	ft_print_matrix(later, "aux");
	system("leaks -q a.out");
	return (0);
}
