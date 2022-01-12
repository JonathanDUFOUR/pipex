/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline_recursive.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:33:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 12:08:14 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>
#include "ft_io.h"
#include "pipex.h"

static int	__first(t_ctx *const ctx, char const *cmd)
{
	pid_t	id;
	int		infile;

	id = fork();
	if (id == -1)
		return (EXIT_FAILURE);
	else if (!id)
	{
		infile = open(ctx->infile, O_RDONLY);
		if (infile == -1)
			return (EXIT_FAILURE);
		if (redirect(infile, ctx->fds.tube[1]))
			return (ft_fddel(&infile) | EXIT_FAILURE);
		if ((ft_fddel(&infile)
				| ft_fddel(&ctx->fds.save)
				| ft_fddel(&ctx->fds.tube[0])
				| ft_fddel(&ctx->fds.tube[1]))
			|| run(cmd, ctx->ep))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	return (pid_lst_add_back(&ctx->pids, id));
}

static int	__inter(t_ctx *const ctx, char const *cmd)
{
	pid_t	id;

	id = fork();
	if (id == -1)
		return (EXIT_FAILURE);
	else if (!id)
	{
		if (redirect(ctx->fds.save, ctx->fds.tube[1]))
			return (EXIT_FAILURE);
		if ((ft_fddel(&ctx->fds.save)
				| ft_fddel(&ctx->fds.tube[0])
				| ft_fddel(&ctx->fds.tube[1]))
			|| run(cmd, ctx->ep))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	return (pid_lst_add_back(&ctx->pids, id));
}

static int	__last(t_ctx *const ctx, char const *cmd)
{
	pid_t	id;
	int		outfile;

	id = fork();
	if (id == -1)
		return (EXIT_FAILURE);
	else if (!id)
	{
		outfile = open(ctx->outfile, O_CREAT | O_TRUNC | O_WRONLY, 0644);
		if (outfile == -1)
			return (EXIT_FAILURE);
		if (redirect(ctx->fds.save, outfile))
			return (ft_fddel(&outfile) | EXIT_FAILURE);
		if ((ft_fddel(&outfile)
				| ft_fddel(&ctx->fds.save))
			|| run(cmd, ctx->ep))
			return (EXIT_FAILURE);
		return (EXIT_SUCCESS);
	}
	return (pid_lst_add_back(&ctx->pids, id));
}

/*
	Execute the commands contained in the given array `cmd_arr` recursively
	redirecting the output of each command to the input of the next
*/
int	pipeline_recursive(t_ctx *const ctx, char const **cmd_arr,
	t_uint const cmd_cnt, t_uint const i)
{
	if (!i)
	{
		if (pipe(ctx->fds.tube) == -1)
			return (EXIT_FAILURE);
		if (__first(ctx, *cmd_arr)
			|| dup2(ctx->fds.tube[0], ctx->fds.save) == -1
			|| ft_fddel(&ctx->fds.tube[0]) | ft_fddel(&ctx->fds.tube[1])
			|| pipeline_recursive(ctx, cmd_arr + 1, cmd_cnt, i + 1))
			return (ft_fddel(&ctx->fds.tube[0]) | ft_fddel(&ctx->fds.tube[1])
				| EXIT_FAILURE);
	}
	else if (i + 1 < cmd_cnt)
	{
		if (pipe(ctx->fds.tube) == -1)
			return (EXIT_FAILURE);
		if (__inter(ctx, *cmd_arr)
			|| dup2(ctx->fds.tube[0], ctx->fds.save) == -1
			|| ft_fddel(&ctx->fds.tube[0]) | ft_fddel(&ctx->fds.tube[1])
			|| pipeline_recursive(ctx, cmd_arr + 1, cmd_cnt, i + 1))
			return (ft_fddel(&ctx->fds.tube[0]) | ft_fddel(&ctx->fds.tube[1])
				| EXIT_FAILURE);
	}
	else if (__last(ctx, *cmd_arr))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
