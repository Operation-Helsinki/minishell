/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_readline.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:17:14 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/10 22:17:15 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	what_is(const char readline)
{
	char	letter;

	letter = '\0';
	if (readline == '\"')
		letter = 'd';
	else if (readline == '\'')
		letter = 's';
	else if (readline == ' ')
		letter = 'e';
	else if (readline == '<' || readline == '>' || readline == '|')
		letter = 'x';
	else
		letter = 'c';
	return (letter);
}

char	*map_readline(const char *readline)
{
	char	*map_tab;
	int		i;
	int		readline_len;

	readline_len = ft_strlen(readline);
	map_tab = (char *)malloc(sizeof(char) * (readline_len + 1));
	if (!map_tab)
		return (NULL);
	i = 0;
	printf("Readline content: [%s]\n", readline);
	while (readline[i])
	{
		map_tab[i] = what_is(readline[i]);
		write(1, &map_tab[i], 1);
		i++;
	}
	map_tab[i] = '\0';
	printf("\n");
	return (map_tab);
}
