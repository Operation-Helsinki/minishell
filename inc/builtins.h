/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:03:40 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/30 00:08:13 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

void piperrak(void);
int	builtins(char **str);
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
