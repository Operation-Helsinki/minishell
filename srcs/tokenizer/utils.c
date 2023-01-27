/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:22:43 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/27 18:12:09 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	check_q(const char *s, t_quotes *q, char quote)
{
	if (quote == '\'')
		q->s_count++;
	if (quote == '\"')
		q->d_count++;
	q->i++;
	while (s[q->i] && s[q->i] != quote)
		q->i++;
	if (s[q->i] == quote)
	{
		if (quote == '\'')
			q->s_count++;
		if (quote == '\"')
			q->d_count++;
		q->i++;
	}
}

int	check_quotes(const char *s)
{
	t_quotes	q;

	ft_memset(&q, 0, sizeof(t_quotes));
	while (s[q.i])
	{
		if (s[q.i] == '\"')
			check_q(s, &q, '\"');
		else if (s[q.i] == '\'')
			check_q(s, &q, '\'');
		else
			q.i++;
	}
	if ((q.s_count % 2 != 0) || (q.d_count % 2 != 0))
		return (0);
	return (1);
}
