/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cpy_matrix.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:52:23 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 21:15:29 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_cpy_matrix(char **matrix)
{
	int		len;
	char	**aux;
	int		i;

	if (!matrix)
		return (NULL);
	len = ft_len_matrix(matrix);
	aux = malloc(sizeof(char *) * (len + 1));
	if (!aux)
		return (NULL);
	i = 0;
	while (i < len)
	{
		aux[i] = malloc(sizeof(char) * (ft_strlen(matrix[i]) + 1));
		if (!aux[i])
			return (ft_free_matrix(aux), NULL);
		ft_strncpy(aux[i], matrix[i], ft_strlen(matrix[i]) + 1);
		i++;
	}
	aux[i] = NULL;
	return (aux);
}
