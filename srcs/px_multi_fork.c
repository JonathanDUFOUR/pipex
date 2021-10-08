/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_multi_fork.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 22:22:14 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 12:04:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <sys/wait.h>
#include "pipex.h"
#include "type/t_int.h"
#include "enum/e_ret.h"

int	px_multi_fork(int **fd, t_uint const pipe_count, char const **av)
{
	int	pid;
	int	ret;

	pid = fork();
	if (pid == -1)
		return (FORK_ERR);
	else if (!pid)
	{
		sleep(1);
		if (pipe_count > 3)
			return (px_multi_fork(fd + 1, pipe_count - 1, av + 1));
		return (px_process_run(*(fd + 1), *(fd + 2), *(av + 1)));
	}
	else
	{
		ret = px_process_run(*fd, *(fd + 1), *av);
		if (waitpid(pid, NULL, 0) == -1)
			return (WAITPID_ERR);
		return (ret);
	}
}
