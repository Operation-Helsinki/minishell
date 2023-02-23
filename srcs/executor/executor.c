/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   executor.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: davgarci <davgarci@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/27 21:41:24 by davgarci          #+#    #+#             */
/*   Updated: 2023/02/23 18:48:23 by davgarci         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minishell.h"

void	which_type(int i)
{
	int	type;

	type = what_cmd(g_c.tokens[i]);
	printf("type: %i\n", type);
	if (type == BUILTIN)
	{
		g_c.dolar_q = builtins(g_c.tokens[i]);
		exit(0);
	}
	else if (type == STDLIB)
		ft_exec(g_c.tokens[i]);
	else
		cmd_not_found(g_c.tokens[i]);
	exit(EXIT_SUCCESS);
}

int	ft_ijump(int i)
{
	i++;
	if (g_c.tokens[i])
	{
		while (ft_strcmp(g_c.tokens[i], "|") != 0)
			i++;
		return(i);
	}
	return (197);
}

t_pipe			*ft_lstlast_pipe(t_pipe *lst)
{
	if (lst == NULL)
		return (NULL);
	while (lst->next)
		lst = lst->next;
	return (lst);
}

void			ft_lstadd_back_pipe(t_pipe **alst, t_pipe *newitem)
{
	t_pipe *item;

	if (!*alst && newitem)
		*alst = newitem;
	else if (*alst && newitem)
	{
		item = *alst;
		while (item->next)
			item = item->next;
		item->next = newitem;
	}
}

t_pipe			*new_pipe(char *command, int have_pipe, t_pipe *pipes, int read)
{
	t_pipe *new;

	if (!(new = malloc(sizeof(t_pipe))))
		return (NULL);
	new->pipe_parse = ft_comand_split(command, ' '); //Este creo que lo teneis hecho, es para separar el comando en palabras
	new->pipe = have_pipe;
	new->read = read;
	new->previous = ft_lstlast_pipe(pipes);
	new->next = 0;
	return (new);
}

int				create_pipes(void)
{
	int			i;
	t_pipe		*new_elem;
	
	i = 0;
	while (g_c.tokens[i])
	{
		printf("Preparamos el pipe para: %s\n", g_c.tokens[i]);
		//aqui hay que mirar si tiene redireccion el token, lo dejamos para el final y de momento solo miramos tokens
		if (pipetab[i + 1] == NULL)
			new_elem = new_pipe(g_c.tokens[i], 0, g_c.pipe_list, g_read);
		else
			new_elem = new_pipe(g_c.tokens[i], 1, g_c.pipe_list, g_read);
		ft_lstadd_back_pipe(&g_c.pipe_list, new_elem);
		i = i + 2;
	}
	return (1);
}

int				ft_pipe2(t_pipe *list_cmnd, int *pipe_open, int *ret)
{
	pid_t	pid;
	int		status;

	if ((list_cmnd->pipe == 1 || (list_cmnd->previous &&
	list_cmnd->previous->pipe == 1)) && (*pipe_open = 1))
		if (pipe(list_cmnd->fd))
			return (0);
	g_forking = 1;
	if ((pid = fork()) < 0)
		return (0);
	else if (pid == 0)
		ft_child_process(shell, list_cmnd);
	else
	{
		waitpid(pid, &status, 0);
		if ((g_read != 1) && shell->redirection_out
		&& !list_cmnd->next && !(g_read = 0) && close(shell->redirection_out))
			shell->redirection_out = 0;
		ft_close_fds(shell, list_cmnd, *pipe_open);
		if (WIFEXITED(status))
			*ret = WEXITSTATUS(status);
		g_forking = 0;
	}
	return (1);
}

void	pipas_handler(void)
{
	/*
	int	i;
	int	pid2 = 2;
	int	fd_read;


	int	status;
	int	pid;
	i = 0;*/


	int		ret;
	int		pipe_open;

	printf("Numero de tokens: %d\n", g_c.tok_count);

	create_pipes()


	while (g_c.pipe_list)
	{
		ret = EXIT_FAILURE;
		pipe_open = 0;
		if (!(ft_pipe2(g_c.pipe_list, &pipe_open, &ret)))
			return (0);
		g_c.pipe_list = g_c.pipe_list->next;
	}
	return (1);
	/*pid = fork();
	if (pid == 0)
	{
	printf("hello: %s %s %s\n", g_c.tokens[0], g_c.tokens[1], g_c.tokens[2]);
	while (i < g_c.tok_count)
	{
		pipe(g_c.fd);
		pid2 = fork();
		if (pid2 == 0)
		{
			//write(2, "hola1", 5);
			if (i == 0 && g_c.pipas > 0)
			{
				//write(2, "hola2", 5);
				//printf("%d %d\n", g_c.fd[0], g_c.fd[1]);
				dup2(g_c.fd[WRITE_END], 1);
				fd_read = g_c.fd[READ_END];
			}
			else if (i == g_c.tok_count - 1)
			{
				//write(2, &g_c.fd[0], 1);
				//printf("%d %d\n", g_c.fd[0], g_c.fd[1]);
				//write(2, "hola3", 5);
				dup2(g_c.fd[READ_END], 0);
				dup2(0, g_c.fd[WRITE_END]);
			}
			else if (g_c.pipas > 0)
			{
				//write(2, "hola4", 5);
				dup2(g_c.fd[READ_END], 0);
				dup2(g_c.fd[WRITE_END], g_c.fd[READ_END]);
			}
			which_type(i);
			fd_read = g_c.fd[READ_END];
		}
		i = ft_ijump(i);
		i++;
	}
	}
	i = 0;
		waitpid(-1, &status, 0);
	g_c.dolar_q = status;
	*/
}

//void	piperrak(int i)
//{
//	pid_t	pid;
//
//	if (pipe(g_c.fd) == -1)
//		exit(-1);
//	pid = fork();
//	if (pid == 0)
//	{
//		if (i != g_c.pipas * 2)
//			dup2(g_c.fd[WRITE_END], STDOUT_FILENO);
//		if (builtins(g_c.tokens[i]) != NONE)
//			exit(0);
//		ft_exec(g_c.tokens[i]);
//	}
//	else
//	{
//		dup2(g_c.fd[READ_END], STDIN_FILENO);
//		if (g_c.fd[WRITE_END] != STDIN_FILENO)
//			close(g_c.fd[WRITE_END]);
//		if (g_c.fd[READ_END] != STDOUT_FILENO)
//			close(g_c.fd[READ_END]);
//	}
//}

	//  ls | wc

	// else
	// {
	// 	dup2(g_c.fd[READ_END], STDIN_FILENO);
	// 	if (g_c.fd[WRITE_END] != STDIN_FILENO)
	// 		close(g_c.fd[WRITE_END]);
	// 	if (g_c.fd[READ_END] != STDOUT_FILENO)
	// 		close(g_c.fd[READ_END]);
	// }

	//FOR LATER -> IMPleMENT PIPES

	//ELSE IF THERE IS PIPES
	// {
	// 	while (i <= g_c.pipas * 2)
	// 	{
	// 		if (!token_is_symbol(g_c.tokens[i]))
	// 			piperrak(i);
	// 		i++;
	// 	}
	// 	i = 0;
	// 	while (i < g_c.pipas + 1)
	// 	{
	// 		waitpid(-1, &status, 0);
	// 		i++;
	// 	}
	// }