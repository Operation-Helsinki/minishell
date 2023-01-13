/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:16:46 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/13 00:13:05 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "minishell.h"

char	*expander(char * post_dolar, int i, char **environment);
char	*expan_token(char *not_expanded_token, char **environment);
void	readline_create(char **environment);

#endif
