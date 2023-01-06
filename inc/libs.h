/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libs.h                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: psegura- <psegura-@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 20:40:30 by psegura-          #+#    #+#             */
/*   Updated: 2023/01/06 20:31:29 by psegura-         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBS_H
# define LIBS_H

/*______UNISTD_______
Access, Write, Read, Close, Fork, Getcwd
Chdir, Unlink, Execve, Dup, Dup2
Pipe, Isatty, Ttyname, Ttyslot
*/
# include <unistd.h>

/*______FCNTL________
Open
*/
# include <fcntl.h>

/*______SYS/WAIT_____
Wait, Waitpid, Wait3, Wait4
*/
# include <sys/wait.h>

/*______SYS/STAT_____
Stat, Lstat, Fstat
*/
# include <sys/stat.h>

/*______SYS/IOCTL____
Ioctl
*/
# include <sys/ioctl.h>

/*______SIGNAL_______
Signal, Sigaction, Kill
*/
# include <signal.h>

/*______STDIO________
Printf, Strerror, Perror
*/
# include <stdio.h>

/*______STDLIB_______
Malloc, Free, Exit, Getenv
*/
# include <stdlib.h>

/*______TERMIOS______
Tcsetattr, Tcgetattr
*/
# include <termios.h>

/*___CURSES_&_TERM___
Tgetent, Tgetflag, Tgetnum, Tgetstr, Tgoto, Tputs
*/
# include <curses.h>
# include <term.h>

/*_______DIRENT______
Opendir, Readdir, Closedir
*/
# include <dirent.h>

/*_______READLINE____
Readline, Rl_clear_history, Rl_on_new_line
Rl_replace_line, Rl_redisplay, Add_history
*/
# include <readline/readline.h>
# include <readline/history.h>

#endif
