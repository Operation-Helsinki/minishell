/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tokenizer.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 20:22:05 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/02 22:48:28 by psegura-         ###   ########.fr       */
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

typedef struct s_count {
	int		i;
	int		j;
	int		k;
}	t_count;

/*__STORE_TOKENS_UTILS____*/
int		count_tokens(const char *str);
void	main_while(const char *str, t_count *c);
int		char_is_symbol(char letter, char *symbols);
void	find_next_quote(const char *str, int *i, char quote);
void	if_char_is_symbol(const char *str, t_count *c, int *len);

/*__STORE_TOKENS____*/
void	store_tokens(const char *str, char **tokens);

/*__UTILS____*/
int		check_quotes(const char *readline);

/*__LOCATE_SYMBOLS____*/
void	find_next_quote(const char *str, int *i, char quote);
int		count_tokens(const char *str);
void	store_tokens(const char *str, char **tokens);

/*__TOKENS_TO_PIPAS____*/
int		count_pipas(char **tokens);
int		double_symbols(char **tokens);
char	**tokens_to_pipas(char **tokens);
int		token_is_symbol(char *token);

#endif
