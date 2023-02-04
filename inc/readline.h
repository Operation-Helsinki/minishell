/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:16:46 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/04 16:32:48 by psegura-         ###   ########.fr       */
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
char	*copy_join(char *str1, char *str2, t_expand *expand);
void	readline_create(void);

/*__MALLOC_EXPAND_TOKENS_AUX__*/
char	*cp_expander2(char *post_dolar, int i, char **environment);
void	copy_expanded_aux(t_expand *expand, char *command_buf, char *new_str);
void	cp_find_dolar_aux(t_expand *expand, char *command_buf, char *new_str);

#endif
