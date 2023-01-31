/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/06/27 13:15:45 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/31 19:09:05 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/**
 * It takes two strings, allocates a new string of the correct size, copies the
 * first string into the new string, then copies the second string into the new
 * string
 * 
 * @param s1 The first string to be joined.
 * @param s2 The string to be appended to the end of s1.
 * 
 * @return A pointer to a new string that is the result of the concatenation
 * of s1 and s2. 
 */
char	*ft_strjoin(char *s1, char *s2)
{
	char	*final;
	int		l_s1;
	int		l_total;
	int		i;

	if (s1 == NULL && s2)
		return ((char *)s2);
	if (s2 == NULL && s1)
		return ((char *)s1);
	l_s1 = ft_strlen(s1);
	l_total = l_s1 + ft_strlen(s2);
	final = ft_calloc(sizeof(char), l_total + 1);
	if (final == NULL)
		return (NULL);
	i = 0;
	while (i < l_s1)
	{
		final[i] = s1[i];
		i++;
	}
	while (i < l_total)
	{
		final[i] = s2[i - l_s1];
		i++;
	}
	return (final);
}
