/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:28:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/11 01:09:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_io.h"
#include "ft_string.h"
#include "ft_colors.h"
#include "pipex.h"
#include "type/t_ctx.h"

static int	__usage_err(char const *program)
{
	ft_putstr_fd(RED "Error: wrong usage\n" RESET, STDERR_FILENO);
	ft_putstr_fd("Usage: ", STDERR_FILENO);
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(" <infile> <cmd0> <cmd1> ... <cmdn> <outfile>", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (EXIT_FAILURE);
}

/*
	Run a pipeline with an even number of commands
*/
static int	__even(int const ac, char const **av, char const **ep,
	t_ctx *const ctx)
{
	fprintf(stderr, "(%i)Enter: %s\n", getpid(), __func__);
	if (open_pipes(ctx->pipe0, ctx->pipe1)
		|| open_infile(av[1], &ctx->fd_in)
		|| exec(ctx->first_cmd, (int []){ctx->fd_in, -1}, ctx->pipe0, ep)
		|| ft_fddel(&ctx->fd_in)
		|| pipeline(av + 3, ctx->pipe0, ctx->pipe1, ep)
		|| open_outfile(av[ac - 1], &ctx->fd_out)
		|| exec(ctx->last_cmd, ctx->pipe0, (int []){-1, ctx->fd_out}, ep)
		|| ft_fddel(&ctx->fd_out)
		|| close_pipes(ctx->pipe0, ctx->pipe1))
	{
		ft_fddel(&ctx->fd_in);
		ft_fddel(&ctx->fd_out);
		close_pipes(ctx->pipe0, ctx->pipe1);
		perror(av[0]);
		return (EXIT_FAILURE);
	}
	fprintf(stderr, "(%i)Leave: %s\n", getpid(), __func__);
	return (EXIT_SUCCESS);
}

/*
	Run a pipeline with an odd number of commands
*/
static int	__odd(int const ac, char const **av, char const **ep,
	t_ctx *const ctx)
{
	fprintf(stderr, "(%i)Enter: %s\n", getpid(), __func__);
	if (open_pipes(ctx->pipe0, ctx->pipe1)
		|| open_infile(av[1], &ctx->fd_in)
		|| exec(ctx->first_cmd, (int []){ctx->fd_in, -1}, ctx->pipe0, ep)
		|| ft_fddel(&ctx->fd_in)
		|| pipeline(av + 3, ctx->pipe0, ctx->pipe1, ep)
		|| open_outfile(av[ac - 1], &ctx->fd_out)
		|| exec(ctx->last_cmd, ctx->pipe1, (int []){-1, ctx->fd_out}, ep)
		|| ft_fddel(&ctx->fd_out)
		|| close_pipes(ctx->pipe0, ctx->pipe1))
	{
		ft_fddel(&ctx->fd_in);
		ft_fddel(&ctx->fd_out);
		close_pipes(ctx->pipe0, ctx->pipe1);
		perror(av[0]);
		return (EXIT_FAILURE);
	}
	fprintf(stderr, "(%i)Leave: %s\n", getpid(), __func__);
	return (EXIT_SUCCESS);
}

int	main(int const ac, char const **av, char const **ep)
{
	t_ctx	ctx;

	if (ac < 5)
		return (__usage_err(av[0]));
	ft_memset(&ctx, -1, sizeof(t_ctx));
	ctx.first_cmd = av[2];
	ctx.last_cmd = av[ac - 2];
	av[2] = NULL;
	av[ac - 2] = NULL;
	if (((ac % 2) && __even(ac, av, ep, &ctx))
		|| (!(ac % 2) && __odd(ac, av, ep, &ctx)))
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
