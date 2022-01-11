/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:38:16 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/11 04:07:52 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include "ft_io.h"
#include "pipex.h"

static int	__decrypt(int const status)
{
	if (WIFEXITED(status))
		return (WEXITSTATUS(status));
	else if (WIFSIGNALED(status))
		return (WTERMSIG(status));
	return (status);
}

/*
	Dupplicate the current process
	Run the given command `cmd` in the child process,
	applying input and output redirections using the given `l_pipe` and `r_pipe`
*/
int	exec(char const *cmd, int *const l_pipe, int *const r_pipe, char const **ep)
{
	pid_t	cmd_id;
	int		status;
	char	buff[42];
	ssize_t	rd;

	fprintf(stderr, "Enter: %s\n", __func__);
	cmd_id = fork();
	if (cmd_id == -1)
		return (EXIT_FAILURE);
	else if (!cmd_id)
	{
		if (redirect(l_pipe, r_pipe)
			// || run(cmd, ep)
			)
			exit(EXIT_FAILURE);
		rd = read(STDIN_FILENO, buff, 41);
		buff[rd] = 0;
		write(STDOUT_FILENO, buff, rd);
		fprintf(stderr, " Exit: %s\n", __func__);
		exit(EXIT_SUCCESS);
	}
	if (waitpid(cmd_id, &status, 0) == -1)
		return (EXIT_FAILURE);
	status = __decrypt(status);
	fprintf(stderr, "status: %i\n", status);
	fprintf(stderr, "Leave: %s\n", __func__);
	return (EXIT_SUCCESS);
}
