/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   copy_join.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/23 16:13:04 by davgarci          #+#    #+#             */
/*   Updated: 2023/01/27 18:54:03 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*copy_join(char *str1, char *str2, t_expand *expand)
{
	int	j;

	j = 0;
	while (str2[j])
	{
		str1[expand->j] = str2[j];
		expand->j++;
		j++;
	}
	return (str1);
}
