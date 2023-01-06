/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:37:31 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/06 20:00:58 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

int	main(void)
{
	unsigned char	*command_buff;
	
	while(1)
	{
		command_buff = (unsigned char *)readline("Shellhinki");
		// if (ft_strlen(command_buff) < 0)
		// {
		// 	add_history(command_buff);
		// 	printf("%s\n", command_buff);
		// }
		printf("%s\n", command_buff);
	}
	return (0);	
}
