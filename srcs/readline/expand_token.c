/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 23:56:28 by davgarci          #+#    #+#             */
/*   Updated: 2023/01/15 13:56:26 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expander(char *post_dolar, int i, char **environment)
{
	if (ft_strncmp(post_dolar, "?", 1) == 0)
	{
		return ("?EXP");
	}
	while (*environment)
	{
		if (ft_strncmp(post_dolar, *environment, i) == 0
			&& ft_strncmp(*environment + i, "=", 1) == 0)
			return (*environment + i + 1);
		environment++;
	}
	return ("");
}

void	first_if(char *command_buf, t_expand *ex)
{
	ex->l = ex->i;
	ex->i++;
	ex->j = ex->i;
	while (ft_isalnum(command_buf[ex->j]) || command_buf[ex->j] == '_'
		|| command_buf[ex->j] == '?')
	{
		if ((ft_isdigit(command_buf[ex->j]) == 1 || command_buf[ex->j] == '?')
			&& command_buf[ex->j - 1] == '$')
		{
			ex->j++;
			break ;
		}
		ex->j++;
	}
	ex->m = ex->j;
	ex->dolar = (char *)malloc(sizeof(char) * (ex->j - ex->i) + 1);
	while (ex->i != ex->j)
	{
		ex->dolar[ex->k] = command_buf[ex->i];
		ex->k++;
		ex->i++;
	}
	ex->dolar[ex->k] = '\0';
}

void	second_if(char *command_buf, char **environment, t_expand *ex)
{
	ex->expanded = expander(ex->dolar, ex->k, environment);
	free(ex->dolar);
	ex->j = 0;
	ex->dolar = (char *)malloc(sizeof(char) * ex->l + 1);
	while (ex->j < ex->l)
	{
		ex->dolar[ex->j] = command_buf[ex->j];
		ex->j++;
	}
	ex->dolar[ex->j] = '\0';
	ex->post_expanded = ft_strjoin(ex->dolar, ex->expanded);
	free(ex->dolar);
	ex->j = 0;
	ex->k = 0;
	while (command_buf[ex->j] != ' ' && command_buf[ex->j] != '\0'
		&& command_buf[ex->j] != '$')
		ex->j++;
}

void	last_else(char *command_buf, t_expand *ex)
{
	while (command_buf[ex->j] != '\0')
		ex->j++;
	ex->dolar = (char *)malloc(sizeof(char) * ex->j - ex->l + 1);
	while (ex->m <= ex->j)
	{
		ex->dolar[ex->k] = command_buf[ex->m];
		ex->m++;
		ex->k++;
	}
	if (ex->final != NULL)
		free(ex->final);
	ex->final = ft_strjoin(ex->post_expanded, ex->dolar);
	free(ex->dolar);
	free(ex->post_expanded);
}

char	*expan_token(char *command_buf, char **environment)
{
	t_expand	ex;

	ft_memset(&ex, 0, sizeof(t_expand));
	while (command_buf[ex.i])
	{
		if (command_buf[ex.i] == '$' && command_buf[ex.i + 1] != ' '
			&& command_buf[ex.i + 1] != '\0')
		{
			first_if(command_buf, &ex);
			second_if(command_buf, environment, &ex);
			if (command_buf[ex.j] == '\0')
				return (ex.post_expanded);
			else
			{
				last_else(command_buf, &ex);
				return (expan_token(ex.final, environment));
			}
		}
		ex.i++;
	}
	return (command_buf);
}
