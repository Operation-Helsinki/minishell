/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   store_tokens_utils.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 18:34:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/27 18:35:32 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	find_next_quote(const char *str, int *i, char quote)
{
	(*i)++;
	while (str[(*i)] != quote && str[(*i)])
		(*i)++;
}

int	char_is_symbol(char letter, char *symbols)
{
	int	i;

	i = -1;
	while (symbols[++i])
		if (letter == symbols[i])
			return (1);
	return (0);
}

void	main_while(const char *str, t_count *c)
{
	while (str[c->i] == ' ' && str[c->i])
	{
		c->i++;
		c->j = c->i;
	}
	while (str[c->i] && str[c->i] != ' '
		&& (char_is_symbol(str[c->i], ">|<") == 0))
	{
		if (str[c->i] == '\"')
			find_next_quote(str, &c->i, '\"');
		if (str[c->i] == '\'')
			find_next_quote(str, &c->i, '\'');
		if (str[c->i])
			c->i++;
	}
}

void	if_char_is_symbol(const char *str, t_count *c, int *len)
{
	(*len) = 1;
	if (char_is_symbol(str[c->i], "><") == 1 && str[c->i + 1]
		&& str[c->i + 1] == str[c->i])
	{
		c->i++;
		(*len)++;
	}
}

int	count_tokens(const char *str)
{
	t_count	c;
	int		len;
	int		token_c;

	token_c = 0;
	ft_memset(&c, 0, sizeof(t_count));
	while (str[c.i])
	{
		main_while(str, &c);
		len = c.i - c.j;
		if (len != 0)
			token_c++;
		c.j = c.i;
		if (char_is_symbol(str[c.i], ">|<") == 1)
		{
			if_char_is_symbol(str, &c, &len);
			token_c++;
		}
		if (str[c.i])
			c.i++;
		c.j = c.i;
	}
	return (token_c);
}
