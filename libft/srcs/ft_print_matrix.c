/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_matrix.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 02:42:16 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 02:45:55 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_print_matrix(char **matrix, char *str)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i] != NULL)
			printf("%s [%d] -> [%s]\n", str, i, matrix[i]);
		i++;
	}
}
