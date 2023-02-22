/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   unset.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:02:08 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/18 19:01:35 by davgarci         ###   ########.fr       */
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

int	ft_unset(char **env, char **args)
{
	int		pos;
	char	*to_find;
	int		i;

	i = 1;
	while (args[i])
	{
		if (check_syntax(args[i]) == 0)
			return (printf("export: %s: not a valid identifier\n", args[i]), 1);
		to_find = ft_strjoin(args[i], "=");
		pos = ft_locate_str_in_matrix(g_c.env, to_find);
		free(to_find);
		g_c.env = ft_delete_row_matrix(g_c.env, pos);
		i++;
	}
	ft_free_matrix(env);
	ft_free_matrix(args);
	return (EXIT_SUCCESS);
}

		// printf("DELETE: [%s]\n", args[i]);