/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readline.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:16:46 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/15 21:44:03 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef READLINE_H
# define READLINE_H

# include "minishell.h"

# define PROMPT "\033[0;32m➜  \033[0;36mShellhinki \033[1;33m✗ \033[0m"

char	*expander(char *post_dolar, int i, char **environment);
char	*expan_token(char *not_expanded_token, char **environment);
void	readline_create(char **environment);

#endif
