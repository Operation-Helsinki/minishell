/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   export.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:02:04 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 22:06:46 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	check_syntax(char *str)
{
	int	i;

	i = 0;
	while (str[i] && str[i] != '=')
	{
		if (i == 0 && (ft_isalpha(str[i]) == 0 && str[i] != '_'))
			return (0);
		if (i != 0 && ((ft_isalnum(str[i]) == 0) && str[i] != '_'))
			return (0);
		i++;
	}
	return (1);
}

int	ft_export(char **env, char *str)
{
	int		pos;
	char	**temp;

	if (check_syntax(str) == 0)
		return (printf("export: %s: not a valid identifier\n", str));
	pos = ft_locate_str_in_matrix(env, str);
	g_c.env = ft_delete_row_matrix(env, pos);
	ft_free_matrix(env);
	temp = ft_add_row_matrix(g_c.env, str);
	ft_free_matrix(g_c.env);
	g_c.env = ft_cpy_matrix(temp);
	ft_free_matrix(temp);
	return (0);
}
