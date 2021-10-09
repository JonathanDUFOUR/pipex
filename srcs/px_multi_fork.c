/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_multi_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/09 10:59:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "pipex.h"
#include "type/t_int.h"
#include "enum/e_fd.h"
#include "enum/e_ret.h"

int	px_multi_fork(int **fd, t_uint const pipe_count, char const **av,
	t_uint depth)
{
	int	pid;
	int	ret;

	pid = fork();
	if (pid == -1)
		return (FORK_ERR);
	else if (!pid)
	{
		++av;
		if ((pipe_count - depth++) > 3)
			return (px_multi_fork(fd, pipe_count, av, depth));
		ret = px_multi_close(fd, pipe_count, depth);
		if (ret == SUCCESS)
			ret = px_command_run(fd[depth][RD], fd[depth + 1][WR], *av);
		return (ret);
	}
	else
	{
		ret = px_multi_close(fd, pipe_count, depth);
		if (ret == SUCCESS)
			ret = px_command_run(fd[depth][RD], fd[depth + 1][WR], *av);
		if (waitpid(pid, NULL, 0) == -1)
			return (WAITPID_ERR);
		return (ret);
	}
}
