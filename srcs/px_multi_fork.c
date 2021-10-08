/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_multi_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 02:03:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEBUG */
#include <stdio.h>

#include <unistd.h>
#include <sys/wait.h>
#include "pipex.h"
#include "type/t_int.h"
#include "enum/e_fd.h"
#include "enum/e_ret.h"

/*
**	./pipex infile cmd0 cmd1 outfile
**	             W-R  W-R  W-R
*/
int	px_multi_fork(int **fd, t_uint const pipe_count, t_uint const depth)
{
	int	pid;
	int	ret;

	pid = fork();
	if (pid == -1)
		return (FORK_ERR);
	else if (!pid)
	{
		if (pipe_count > 3)
			return (px_multi_fork(fd + 1, pipe_count - 1, depth + 1));
		return (px_process_run_child(depth, *(fd + 1), *(fd + 2)));
	}
	else
	{
		ret = px_process_run_parent(depth, *fd, *(fd + 1));
		if (waitpid(pid, NULL, 0) == -1)
			return (WAITPID_ERR);
		return (ret);
	}
}
