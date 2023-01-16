/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/15 15:57:51 by davgarci          #+#    #+#             */
/*   Updated: 2023/01/15 20:33:03 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int			builtins(char *str)
{
	/*no recibirá char*str sino una estructura*/
	if (!str)
		return (1);
	if (ft_strncmp(str, "pwd\0", 4) == 0)
		return (ft_pwd());
	if (ft_strncmp(str, "env\0", 4) == 0)
		return (ft_env(g_c.env));
	//if (ft_strncmp(str, "exit\0", 5) == 0)
	//	return (ft_exit(&tokens[1], t));
	if (ft_strncmp(str, "cd\0", 3) == 0)
		return (ft_cd(g_c.tokens, g_c.env));
	if (ft_strncmp(str, "echo\0", 5) == 0)
		return (ft_echo(g_c.tokens));
	//if (ft_strncmp(str, "export\0", 7) == 0)
	//	return (ft_export(&tokens[1], t));
	//if (ft_strncmp(str, "unset\0", 6) == 0)
	//	return (ft_unset(&tokens[1], t));
	else
		return (1);
}
