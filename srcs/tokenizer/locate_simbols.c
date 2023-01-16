/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_simbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:26:38 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/16 21:00:31 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "minishell.h"
#include <stdio.h>
#include <stdlib.h>

void	count_symbols(char letter, int *symbol_c)
{
	if (letter != '\0'
		&& (letter == '<' || letter == '>'))
		(*symbol_c)++;
}

int	tokens(char *str)
{
	int	i;
	int	j;
	int	symbol_c;
	int	*symbol_index;

	i = -1;
	symbol_c = 0;
	while (str[++i])
		count_symbols(str[i], &symbol_c);
	symbol_index = malloc(symbol_c * sizeof(int));
	i = -1;
	j = 0;
	while (str[++i])
	{
		if (str[i] != '\0' && (str[i] == '<' || str[i] == '>'))
				symbol_index[j++] = i;
	}
	printf("[%d]\n", symbol_index[0]);
	return (symbol_c);
}

int	more_text(char *str)
{
	int	i;
	int	flag;

	i = 0;
	flag = 1;
	if (!str)
		return (0);
	while (str[i])
	{
		if (str[i] == '\"' || str[i] == '\"')
			flag = 0;
		i++;
	}
	return (flag);
}

void	find_next_quote(char *str, int *i, char quote)
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

int	count_tokens(char *str)
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

// int main(int argc, char **argv)
// {
// 	(void)argc;
// 	printf("Input: [%s]\n", argv[1]);
// 	printf("Tokens count: %d\n", count_tokens(argv[1]));
// 	// printf("Symbols count: %d\n", tokens(argv[1]));
// 	return (0);
// }
