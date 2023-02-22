/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/11 10:25:30 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/21 00:25:52 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef EXECUTOR_H
# define EXECUTOR_H

# include "minishell.h"

# define SPACE		' '
# define NONE		42
# define BUILTIN	1
# define STDLIB		2
# define OTHER		0

/*___EXECUTOR___*/
void	piperrak(int i);
void	pipas_handler(void);

/*___CMD_TYPE___*/
int		cmd_is_builtin(char *cmd);
int		what_cmd(char *argv);

/*___EXEC_CMD___*/
void	ft_exec(const char *argv);

/*___FIND_COMMAND___*/
char	*check_path(void);
char	*only_path(char *cmd);
void	cmd_not_found(char *cmd);
void	exit_failure(char *err_msg, char **to_free, int flag);

#endif
