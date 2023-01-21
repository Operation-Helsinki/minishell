/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_simbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:26:38 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 02:41:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

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

void	find_tokens(const char *str, int *i, int *j, char **tokens, int *k)
{
	int		len;
	char	*token;

	token = NULL;
	while (str[(*i)] != ' ' && str[(*i)])
	{
		if (str[(*i)] == '\"')
			find_next_quote(str, i, '\"');
		if (str[(*i)] == '\'')
			find_next_quote(str, i, '\'');
		if (str[(*i)])
			(*i)++;
	}
	if ((*i) > (*j))
	{
		len = (*i) - (*j);
		token = malloc(sizeof(char) * (len + 1));
		ft_strncpy(token, str + (*j), len);
		token[len] = '\0';
		tokens[*k] = token;
		(*k)++;
	}
}

void	store_tokens(const char *str, char **tokens)
{
	int	i;
	int	j;
	int	k;

	i = 0;
	k = 0;
	while (str[i])
	{
		while (str[i] == ' ' && str[i])
			i++;
		j = i;
		find_tokens(str, &i, &j, tokens, &k);
	}
	tokens[k] = NULL;
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
