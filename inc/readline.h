/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:16:46 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 04:07:41 by davgarci         ###   ########.fr       */
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
	int		n;
	int		flag;
	char	*expanded;
	char	*post_expanded;
	char	*final;
	char	*dolar;
}	t_expand;

char	*expander(char *post_dolar, int i, char **environment);
char	*expan_token2(char *command_buf, char **environment);
char	*malloc_expand(t_expand *expand, char *command_buf, char **environment);
void	readline_create(void);

#endif
