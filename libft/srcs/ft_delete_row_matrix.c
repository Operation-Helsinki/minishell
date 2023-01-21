/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_delete_row_matrix.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:48:53 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 03:30:23 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	**ft_delete_row_matrix(char **matrix, int delete)
{
	int		len;
	char	**aux;
	int		i;
	int		j;

	if (!matrix)
		return (NULL);
	len = ft_len_matrix(matrix);
	if (delete > len)
		return (matrix);
	aux = malloc(sizeof(char *) * len);
	if (!aux)
		return (NULL);
	i = 0;
	j = 0;
	while (i < len)
	{
		if (i != delete)
		{	
			aux[j] = malloc(sizeof(char) * (ft_strlen(matrix[i]) + 1));
			if (!aux[j])
				return (ft_free_matrix(aux), NULL);
			ft_strncpy(aux[j], matrix[i], ft_strlen(matrix[i]) + 1);
			j++;
		}
		i++;
	}
	aux[j] = NULL;
	return (aux);
}
