/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   expand_token.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/19 17:57:27 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/04 16:12:53 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expander2(char *post_dolar, int i, char **environment)
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

int	find_dolar(t_expand *expand, char *command_buf, char **environment)
{
	if (command_buf[expand->i])
		expand->i++;
	if ((ft_isdigit(command_buf[expand->i]) == 1))
		return (expand->i++);
	else if (command_buf[expand->i] == '?')
	{
		expand->i++;
		return (expand->j += ft_strlen(ft_itoa(g_c.dolar_q)));
	}
	else if (command_buf[expand->i] == ' ' || command_buf[expand->i] == '\0')
	{
		if (command_buf[expand->i] == ' ')
		{
			expand->j++;
		}
		expand->i++;
		expand->j++;
		return (0);
	}
	expand->k = expand->i;
	while (ft_isalnum(command_buf[expand->i]) || command_buf[expand->i] == '_')
		expand->i++;
	expand->j += ft_strlen(expander2(command_buf + expand->k,
				expand->i - expand->k, environment));
	return (0);
}

void	second_elif(t_expand *expand, char *command_buf, char **environment)
{
	expand->i++;
	while (command_buf[expand->i] != '\"' && command_buf[expand->i])
	{
		if (command_buf[expand->i] == '$')
		{
			find_dolar(expand, command_buf, environment);
		}
		else
		{
			expand->j++;
			expand->i++;
		}
	}
	if (command_buf[expand->i])
	{
		expand->i++;
	}
}

/*i para contar la posicion del string
	j para contar lo que necesitamos malloquear*/
void	counter_reserv(t_expand *expand, char *command_buf, char **environment)
{
	while (command_buf[expand->i])
	{
		if (command_buf[expand->i] == '$')
			find_dolar(expand, command_buf, environment);
		else if (command_buf[expand->i] == '\'')
		{
			expand->i++;
			while (command_buf[expand->i] != '\'' && command_buf[expand->i])
			{
				expand->j++;
				expand->i++;
			}
			if (command_buf[expand->i])
			expand->i++;
		}
		else if (command_buf[expand->i] == '\"')
			second_elif(expand, command_buf, environment);
		else if (command_buf[expand->i])
		{
			expand->i++;
			expand->j++;
		}
	}
}

char	*expan_token2(char *command_buf, char **environment)
{
	t_expand	expand;
	char		*new_str;

	memset(&expand, 0, sizeof(t_expand));
	counter_reserv(&expand, command_buf, environment);
	new_str = malloc_expand(&expand, command_buf, environment);
	return (new_str);
}
