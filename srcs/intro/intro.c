/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   intro.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/07 18:16:07 by psegura-          #+#    #+#             */
/*   Updated: 2023/02/04 23:48:36 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	ft_print_header(void)
{
	int		fd;
	char	*line;

	fd = open("srcs/intro/intro.txt", O_RDONLY);
	if (fd < 0)
		return ;
	line = "HOLA";
	printf("\033c");
	while (line)
	{
		line = get_next_line(fd);
		if (line)
			printf("%s", line);
		free(line);
	}
	printf("\n");
	usleep(100000 * 10);
	printf("\033c");
}
