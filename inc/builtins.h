/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:03:40 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/04 09:54:53 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef BUILTINS_H
# define BUILTINS_H

# include "minishell.h"

int		builtins(char *str);

/*__PWD_____*/
int		ft_pwd(char **commands);

/*__ENV_____*/
int		ft_env(char **env, char **commands);

/*__CD______*/
int		ft_cd(char **env, char **commands);

/*__ECHO____*/
int		ft_echo(char **commands);

/*__EXPORT__*/
int		ft_export(char **env, char **args);

/*__PWD_____*/
int		ft_pwd(void);

/*__SIGNALS___*/
void	sig_init(void);
void	execution_signal_init(void);
void	execution_signal_hadler(int sig);

/*__UNSET___*/
int		ft_unset(char **env, char **args);

/*__EXIT____*/

#endif
