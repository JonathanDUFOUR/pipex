/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_multi_pipe.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 04:02:23 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/09 00:52:11 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_mem.h"
#include "pipex.h"
#include "type/t_ctx.h"
#include "type/t_int.h"
#include "enum/e_fd.h"
#include "enum/e_ret.h"

static int	**fd_init(t_uint const pipe_count)
{
	int		**output;
	t_uint	i;

	output = malloc((pipe_count + 1) * sizeof(int *));
	if (!output)
		return (NULL);
	i = 0;
	while (i < pipe_count)
	{
		output[i] = malloc(2 * sizeof(int));
		if (!output[i])
		{
			while (i)
			{
				--i;
				ft_memdel(output + i);
			}
			return (NULL);
		}
		output[i][0] = -1;
		output[i][1] = -1;
		++i;
	}
	return (output);
}

static void	fd_clear(int **fd, t_uint const pipe_count)
{
	t_uint	i;

	i = 0;
	while (i < pipe_count)
	{
		if (fd[i][0] != -1)
			close(fd[i][0]);
		if (fd[i][1] != -1)
			close(fd[i][1]);
		ft_memdel(fd + i);
		++i;
	}
	ft_memdel(&fd);
}

static int	dup2_infile(int **fd)
{
	t_ctx *const	ctx = px_ctx_get();

	fd[0][RD] = dup2(ctx->infile_fd, fd[0][RD]);
	if (fd[0][RD] == -1)
		return (DUP2_ERR);
	if (ctx->infile_fd != -1 && close(ctx->infile_fd) == -1)
		return (CLOSE_ERR);
	ctx->infile_fd = -1;
	return (SUCCESS);
}

static int	dup2_outfile(int **fd, t_uint const pipe_count)
{
	t_ctx *const	ctx = px_ctx_get();

	fd[pipe_count - 1][WR] = dup2(ctx->outfile_fd, fd[pipe_count - 1][WR]);
	if (fd[pipe_count - 1][WR] == -1)
		return (DUP2_ERR);
	if (ctx->outfile_fd != -1 && close(ctx->outfile_fd) == -1)
		return (CLOSE_ERR);
	ctx->outfile_fd = -1;
	return (SUCCESS);
}

int	px_multi_pipe(t_uint const pipe_count, char const **av)
{
	int		**fd;
	int		ret;
	t_uint	i;

	fd = fd_init(pipe_count);
	if (!fd)
		return (MALLOC_ERR);
	ret = SUCCESS;
	i = 0;
	while (ret == SUCCESS && i < pipe_count)
	{
		if (pipe(fd[i]) == -1)
			ret = PIPE_ERR;
		++i;
	}
	if (ret == SUCCESS)
		ret = dup2_infile(fd);
	if (ret == SUCCESS)
		ret = dup2_outfile(fd, pipe_count);
	if (ret == SUCCESS)
		ret = px_multi_fork(fd, pipe_count, av, 0);
	fd_clear(fd, pipe_count);
	return (ret);
}
