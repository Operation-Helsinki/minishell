/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:02:08 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 22:10:18 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

static int	check_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (i == 0 && (ft_isalpha(str[i]) == 0 && str[i] != '_'))
			return (0);
		if (i != 0 && ((ft_isalnum(str[i]) == 0) && str[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_unset(char **env, char *str)
{
	int		pos;
	char	*to_find;

	if (check_syntax(str) == 0)
		return (printf("export: %s: not a valid identifier\n", str));
	to_find = ft_strjoin(str, "=");
	pos = ft_locate_str_in_matrix(env, to_find);
	free(to_find);
	g_c.env = ft_delete_row_matrix(env, pos);
	ft_free_matrix(env);
	return (0);
}
