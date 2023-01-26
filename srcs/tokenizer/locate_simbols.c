/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_simbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:26:38 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/26 02:31:41 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

typedef struct s_count {
	int		i;
	int		j;
	int		k;
}	t_count;

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

// void	if_str_is_symbol(const char *str, int *i, int *token_c)
// {
// 	char				symbol;
// 	// static const char	*limits[] = {"<", "<<", ">", ">>", "|", NULL};

// 	// ft_print_matrix((char **)limits, "");	
// 	if (char_is_symbol(str[(*i)], ">|<") == 1)
// 	{
// 		if ((*i) > 0 && str[(*i) - 1] != ' ') // : ( ROTO
// 			(*token_c)++;
// 		symbol = str[(*i)];
// 		while (str[(*i)] && str[(*i)] == symbol)
// 			(*i)++;
// 		if (str[(*i)])
// 			(*token_c)++;
// 	}
// }

// int	count_tokens(const char *str)
// {
// 	int		i;
// 	int		token_c;

// 	i = 0;
// 	token_c = 0;
// 	while (str[i])
// 	{
// 		while (str[i] == ' ')
// 			i++;
// 		while (str[i] != ' ' && str[i])
// 		{
// 			if (str[i] == '\"')
// 			{
// 				find_next_quote(str, &i, '\"');
// 				printf("quote: [%c]\n", str[i]);
// 			}
// 			if (str[i] == '\'')
// 				find_next_quote(str, &i, '\'');
// 			if_str_is_symbol(str, &i, &token_c);
// 			if (str[i])
// 				i++;
// 		}
// 		if (str[i])
// 				i++;
// 		token_c++;
// 	}
// 	printf("token_C: [%d]\n", token_c);
// 	return (token_c);
// }

void	store_tokens(const char *str, char **tokens)
{
	t_count	c;
	int		len;

	ft_memset(&c, 0, sizeof(t_count));
	while (str[c.i])
	{
		while (str[c.i] == ' ' && str[c.i])
			c.i++;
		while (str[c.i] && str[c.i] != ' '
			&& (char_is_symbol(str[c.i], ">|<") == 0))
		{
			if (str[c.i] == '\"')
				find_next_quote(str, &c.i, '\"');
			if (str[c.i] == '\'')
				find_next_quote(str, &c.i, '\'');
			if (str[c.i])
				c.i++;
		}
		len = c.i - c.j;
		tokens[c.k] = ft_strndup(str + c.j, len);
		c.j = c.i;
		if (char_is_symbol(str[c.i], ">|<") == 1 && c.i != 0)
			c.k++;
		if (char_is_symbol(str[c.i], ">|<") == 1)
		{
			len = 1;
			if (char_is_symbol(str[c.i], "><") == 1 && str[c.i + 1]
				&& str[c.i + 1] == str[c.i])
			{
				c.i++;
				len++;
			}
			tokens[c.k] = ft_strndup(str + c.j, len);
		}
		c.i++;
		c.j = c.i;
		c.k++;
	}
	tokens[c.k] = NULL;
}
