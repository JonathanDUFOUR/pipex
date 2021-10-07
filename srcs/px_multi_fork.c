/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_multi_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 01:08:35 by jodufour         ###   ########.fr       */
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

	pid = fork();
	if (pid == -1)
		return (FORK_ERR);
	else if (!pid)
	{
		if ((pipe_count - depth) > 3)
			return (px_multi_fork(fd, pipe_count, depth + 1));
		return (px_process_run_child(depth,
				fd[0],
				fd[1]));
	}
	else
	{
		if (waitpid(pid, NULL, 0) == -1)
			return (WAITPID_ERR);
		return (px_process_run_parent(depth,
				fd[pipe_count - depth - 2],
				fd[pipe_count - depth - 1]));
	}
}
