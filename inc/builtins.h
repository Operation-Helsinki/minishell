/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:03:40 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/21 14:06:24 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

/*__CD______*/
int	ft_cd(char **tokens, char **env);

/*__ECHO____*/
int	ft_echo(char **tokens);

/*__ENV_____*/
int	ft_env(char **env);

/*__EXIT____*/

/*__EXPORT__*/
int	ft_export(char **env, char *str);

/*__PWD_____*/
int	ft_pwd(void);

/*__UNSET___*/
int	ft_unset(char **env, char *str);

#endif
