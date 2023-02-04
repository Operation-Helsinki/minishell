/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_expand_token_aux.c                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/04 16:29:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/04 16:30:18 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cp_expander2(char *post_dolar, int i, char **environment)
{
	while (*environment)
	{
		if (ft_strncmp(post_dolar, *environment, i) == 0
			&& ft_strncmp(*environment + i, "=", 1) == 0)
			return (*environment + i + 1);
		environment++;
	}
	return ("");
}

void	cp_find_dolar_aux(t_expand *expand, char *command_buf, char *new_str)
{
	expand->i++;
	expand->j++;
	new_str[expand->n] = '$';
	expand->n++;
	if (command_buf[expand->i - 1] == ' ')
	{
		new_str[expand->n] = ' ';
		expand->n++;
	}
}

void	copy_expanded_aux(t_expand *expand, char *command_buf, char *new_str)
{
	expand->i++;
	while (command_buf[expand->i] != '\'' && command_buf[expand->i])
	{
		new_str[expand->n] = command_buf[expand->i];
		expand->j++;
		expand->i++;
		expand->n++;
	}
	if (command_buf[expand->i])
		expand->i++;
}
