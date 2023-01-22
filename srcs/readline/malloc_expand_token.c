/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   malloc_expand_token.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/21 01:13:06 by davgarci          #+#    #+#             */
/*   Updated: 2023/01/22 18:21:02 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

char	*cp_expander2(char *post_dolar, int i, char **environment)
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

char	*cp_find_dolar(t_expand *expand, char *command_buf, char **environment, char *new_str)
{
	expand->i++;
	if ((ft_isdigit(command_buf[expand->i]) == 1))
	{
		expand->i++;
		return (new_str);
	}
	else if (command_buf[expand->i] == '?')
	{
		expand->i++;
		expand->j += ft_strlen(ft_itoa(g_c.dolar_q));
		expand->n += ft_strlen(ft_itoa(g_c.dolar_q));
		return (ft_strjoin(new_str, ft_itoa(g_c.dolar_q)));
	}
	else if (command_buf[expand->i] == ' ' || command_buf[expand->i] == '\0')
	{
		printf("dol sp:%s", new_str);
		expand->i++;
		expand->j++;
		new_str[expand->n] = '$';
		expand->n++;
		if (command_buf[expand->i - 1] == ' ')
		{
			new_str[expand->n] = ' ';
			expand->n++;
		}
		printf("dol sp:%s", new_str);
		return (new_str);
	}
	expand->k = expand->i;
	//expand->n = expand->i;
	//printf("n = %i, i = %i\n", expand->n, expand->i);
	while (ft_isalnum(command_buf[expand->i]) || command_buf[expand->i] == '_')
		expand->i++;
	expand->j += ft_strlen(cp_expander2(command_buf + expand->k,
				expand->i - expand->k, environment));
	expand->n += ft_strlen(cp_expander2(command_buf + expand->k,
				expand->i - expand->k, environment));
	return (ft_strjoin(new_str, cp_expander2(command_buf + expand->k,
				expand->i - expand->k, environment)));
}

char	*cp_second_elif(t_expand *expand, char *command_buf, char **environment, char *new_str)
{
	expand->i++;
	while (command_buf[expand->i] != '\"' && command_buf[expand->i])
	{
		if (command_buf[expand->i] == '$')
			new_str = cp_find_dolar(expand, command_buf, environment, new_str);
		else
		{
			new_str[expand->n] = command_buf[expand->i];
			expand->n++;
			expand->j++;
			expand->i++;
		}
	}
	//printf("second->%i %c", expand->i, command_buf[expand->i]);
	if (command_buf[expand->i])
		expand->i++;
	return (new_str);
}

/* n es el contador de new_str*/
char	*copy_expanded(t_expand *expand, char *command_buf, char **environment, char *new_str)
{
	expand->i = 0;
	while (command_buf[expand->i])
	{
		//printf("%i!%c\n", expand->i, command_buf[expand->i]);
		if (command_buf[expand->i] == '$')
			new_str = cp_find_dolar(expand, command_buf, environment, new_str);
		else if (command_buf[expand->i] == '\'')
		{
			expand->i++;
			printf("%i!!%c\n", expand->i, command_buf[expand->i]);
			while (command_buf[expand->i] != '\'' && command_buf[expand->i])
			{
				new_str[expand->n] = command_buf[expand->i];
				expand->j++;
				expand->i++;
				expand->n++;
			}
			if (command_buf[expand->i])
				expand->i++;
		}
		else if (command_buf[expand->i] == '\"')
		{
			printf("si \"-> %s\n",new_str = cp_second_elif(expand, command_buf, environment, new_str));
		
		}
		else
		{
			//printf("entra? %c", command_buf[expand->i]);
			new_str[expand->n] = command_buf[expand->i];
			expand->n++;
			expand->j++;
			if (command_buf[expand->i])
				expand->i++;
		}
	}
	new_str[expand->n] = '\0';
	return (new_str);
}

char	*malloc_expand(t_expand *expand, char *command_buf, char **environment)
{
	char *new_str;
	
	expand->n = 0;
	new_str = NULL;
	new_str = (char *)malloc(expand->j * (sizeof(char) + 1));
	new_str = copy_expanded(expand, command_buf, environment, new_str);
	printf("reservado:%d ->%s\n", expand->j, new_str);
	free(command_buf);
	return(new_str);
}