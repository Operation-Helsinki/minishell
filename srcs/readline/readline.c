/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/06 16:55:15 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/13 16:50:17 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*expander(char *post_dolar, int i, char **environment)
{
	while (*environment)
	{
		if (ft_strncmp(post_dolar, *environment, i) == 0)
			return (*environment + i + 1);
		environment++;
	}
	return ("");
}

char	*expan_token(char *command_buf, char **environment) /*en readline.h*/
{
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	char	*expanded;
	char	*post_expanded;
	char	*final;
	char	*dolar;

	i = 0;
	j = 0;
	k = 0;
	dolar = NULL;
	while (command_buf[i])
	{
		if (command_buf[i] == '$' && command_buf[i+1] != ' ' && command_buf[i+1] != '\0')
		{
			l = i;
			i++;
			j = i;
			while (command_buf[j] != ' ' && command_buf[j] != '\0'
				&& command_buf[j] != '$')
				j++;
			m = j;
			dolar = (char *)malloc(sizeof(char) * (j - i) + 1);
			while (i != j)
			{
				dolar[k] = command_buf[i];
				k++;
				i++;
			}
			dolar[k] = '\0';
			expanded = expander(dolar, k, environment);
			free(dolar);
			j = 0;
			dolar = (char *)malloc(sizeof(char) * l + 1);
			while (j < l)
			{
				dolar[j] = command_buf[j];
				j++;
			}
			dolar[j] = '\0';
			post_expanded = ft_strjoin(dolar, expanded);
			free(dolar);
			j = 0;
			k = 0;
			while (command_buf[j] != ' ' && command_buf[j] != '\0'
				&& command_buf[j] != '$')
				j++;
			if (command_buf[j] == '\0')
				return (post_expanded);
			else
			{
				while (command_buf[j] != '\0')
					j++;
				dolar = (char *)malloc(sizeof(char) * j - l + 1);
				while (m <= j) /* mete el barra cero*/
				{
					dolar[k] = command_buf[m];
					m++;
					k++;
				}
				final = ft_strjoin(post_expanded, dolar);
				free(dolar);
				free(post_expanded);
				//printf("final:%s", final);
				return (expan_token(final, environment));
			}
		}
		i++;
	}
	return (command_buf);
}

void	readline_create(char **environment)
{
	const char	*command_buf;
	char		*not_expanded_token;
	char		*expanded_token;
	//tokens = tokens();

	not_expanded_token = "HOLA $USER $ $HOLA$USER $ADIOS $";
	while (1)
	{
		command_buf = (const char *)readline("\033[0;36mShellhinki> \033[0m");
		if (!command_buf)
			exit(0);
		expanded_token = expan_token(not_expanded_token, environment);
		printf("EX: %s\n", expanded_token);
		map_readline(command_buf);
		if (ft_strlen(command_buf) > 0)
			add_history(command_buf);
		// ft_exec(command_buf);
		if (!ft_strcmp(command_buf, "exit")
			|| !ft_strcmp(command_buf, "quit") || !ft_strcmp(command_buf, "e")
			|| !ft_strcmp(command_buf, "q"))
			break ;
		//system("leaks -q minishell");
	}
}

//gcc readline.c -lreadline -o shell