/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   map_readline.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/10 22:16:10 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/10 22:18:45 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MAP_READLINE_H
# define MAP_READLINE_H

# include "minishell.h"

char	what_is(const char readline);
char	*map_readline(const char *readline);

#endif
