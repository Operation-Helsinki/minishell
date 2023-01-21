/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_simbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:26:38 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 23:40:54 by psegura-         ###   ########.fr       */
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
	if (quote == '\"')
	{
		(*i)++;
		while (str[(*i)] != '\"' && str[(*i)])
			(*i)++;
	}
	if (quote == '\'')
	{
		(*i)++;
		while (str[(*i)] != '\'' && str[(*i)])
			(*i)++;
	}
}

int	count_tokens(const char *str)
{
	int	i;
	int	token_c;

	i = 0;
	token_c = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		while (str[i] != ' ' && str[i])
		{
			if (str[i] == '\"')
				find_next_quote(str, &i, '\"');
			if (str[i] == '\'')
				find_next_quote(str, &i, '\'');
			if (str[i])
				i++;
		}
		if (str[i])
				i++;
		token_c++;
	}
	return (token_c);
}

void	find_tokens(const char *str, char **tokens, t_count *c)
{
	int		len;
	char	*token;

	token = NULL;
	while (str[(c->i)] != ' ' && str[(c->i)])
	{
		if (str[(c->i)] == '\"')
			find_next_quote(str, &c->i, '\"');
		if (str[(c->i)] == '\'')
			find_next_quote(str, &c->i, '\'');
		if (str[(c->i)])
			(c->i)++;
	}
	if ((c->i) > (c->j))
	{
		len = (c->i) - (c->j);
		token = malloc(sizeof(char) * (len + 1));
		ft_strncpy(token, str + (c->j), len);
		token[len] = '\0';
		tokens[c->k] = token;
		(c->k)++;
	}
}

void	store_tokens(const char *str, char **tokens)
{
	t_count	c;

	ft_memset(&c, 0, sizeof(t_count));
	while (str[c.i])
	{
		while (str[c.i] == ' ' && str[c.i])
			c.i++;
		c.j = c.i;
		find_tokens(str, tokens, &c);
	}
	tokens[c.k] = NULL;
}

/*
int	main(int argc, char **argv)
{
	char	**tokens;
	int		i = 0;

	(void)argc;
	printf("Tokens count: %d\n", count_tokens(argv[1]));
	tokens = malloc(sizeof(char *) * count_tokens(argv[1]) + 1);
	store_tokens(argv[1], tokens);
	while (tokens[i])
	{
		if (tokens[i] != NULL)
			printf("token [%d] -> [%s]\n", i, tokens[i]);
		i++;
	}
	return (0);
}
*/
