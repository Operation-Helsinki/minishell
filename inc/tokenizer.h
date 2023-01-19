/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:22:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/18 21:27:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef TOKENIZER_H
# define TOKENIZER_H

# include "minishell.h"

typedef struct s_quotes {
	int	s_count;
	int	d_count;
	int	i;
}	t_quotes;

/*__UTILS____*/
int		check_quotes(const char *readline);

/*__LOCATE_SYMBOLS____*/
void	find_next_quote(const char *str, int *i, char quote);
int		count_tokens(const char *str);
void	store_tokens(const char *str, char **tokens);
void	ft_print_matrix(char **matrix);

#endif
