/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   locate_simbols.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 14:26:38 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/18 16:27:56 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

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

void find_tokens(const char *str, int *i, int *j, char** tokens, int* k)
{
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
        int len = (*i) - (*j);
        char* token = malloc(sizeof(char) * (len + 1));
        strncpy(token, str + (*j), len);
        token[len] = '\0';
        tokens[*k] = token;
        (*k)++;
    }
}

void store_tokens(const char *str, char **tokens)
{
    int i = 0;
    int j;
    int k = 0;

    while (str[i])
    {
        while (str[i] == ' ' && str[i])
            i++;
        j = i;
        find_tokens(str, &i, &j, tokens, &k);
    }
	tokens[k] = NULL;
}

void	ft_print_matrix(char **matrix)
{
	int	i;

	i = 0;
	while (matrix[i])
	{
		if (matrix[i] != NULL)
			printf("token [%d] -> [%s]\n", i, matrix[i]);
		i++;
	}
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
