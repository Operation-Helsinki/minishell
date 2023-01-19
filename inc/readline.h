/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:16:46 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/18 21:17:23 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "minishell.h"

# define PROMPT "\033[0;32m➜  \033[0;36mShellhinki \033[1;33m✗ \033[0m"

typedef struct s_expand {
	int		i;
	int		j;
	int		k;
	int		l;
	int		m;
	int		flag;
	char	*expanded;
	char	*post_expanded;
	char	*final;
	char	*dolar;
}	t_expand;

char	*expander(char *post_dolar, int i, char **environment);
char	*expan_token(char *not_expanded_token, char **environment);
void	readline_create(void);

#endif
