/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:46:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 03:54:29 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_LOOKUP_H
# define ERR_MSG_LOOKUP_H

# include <stddef.h>
# include "enum/e_ret.h"

typedef struct s_err_msg	t_err_msg;

struct s_err_msg
{
	int const		err;
	char const		*msg;
	size_t const	len;
	int const		detail;
};

static t_err_msg const		g_err_msg[] = {
	{AC_ERR, "Too few arguments", 17, 0},
	{PIPE_ERR, "pipe() failed", 13, 1},
	{FORK_ERR, "fork() failed", 13, 1},
	{OPEN_ERR, "open() failed", 13, 1},
	{DUP2_ERR, "dup2() failed", 13, 1},
	{CLOSE_ERR, "close() failed", 14, 1},
	{WRITE_ERR, "write() failed", 14, 1},
	{MALLOC_ERR, "malloc() failed", 15, 0},
	{EXECVE_ERR, "execve() failed", 15, 1},
	{WAITPID_ERR, "waitpid() failed", 16, 1},
	{PATH_GET_ERR, "px_path_get() failed", 20, 0},
	{FILE_CONTENT_GET_ERR, "px_file_content_get() failed", 25, 0},
	{0, NULL, 0, 0}
};

#endif
