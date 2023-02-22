/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pwd.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/12 21:02:06 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/18 18:58:20 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	ft_pwd(char **commands)
{
	char	*str_pwd;

	str_pwd = malloc(1024);
	getcwd(str_pwd, 1024);
	ft_putstr_fd(str_pwd, 1);
	ft_putchar_fd('\n', 1);
	free(str_pwd);
	ft_free_matrix(commands);
	return (EXIT_SUCCESS);
}
