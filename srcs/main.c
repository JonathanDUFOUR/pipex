/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:28:37 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 12:18:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include "ft_io.h"
#include "ft_string.h"
#include "ft_colors.h"
#include "pipex.h"

static int	__usage_err(char const *program)
{
	ft_putstr_fd(RED "Error: wrong usage\n" RESET, STDERR_FILENO);
	ft_putstr_fd("Usage: ", STDERR_FILENO);
	ft_putstr_fd(program, STDERR_FILENO);
	ft_putstr_fd(" <infile> <cmd0> <cmd1> ... <cmdn> <outfile>", STDERR_FILENO);
	ft_putchar_fd('\n', STDERR_FILENO);
	return (EXIT_FAILURE);
}

static void	__init(t_ctx *const ctx, char const *infile, char const *outfile,
	char const **ep)
{
	ft_bzero(&ctx->pids, sizeof(t_pid_lst));
	ft_memset(&ctx->fds, -1, sizeof(t_fds));
	ctx->infile = infile;
	ctx->outfile = outfile;
	ctx->ep = ep;
	ctx->fds.save = dup(STDIN_FILENO);
}

int	main(int const ac, char const **av, char const **ep)
{
	t_ctx	ctx;

	if (ac < 5)
		return (__usage_err(av[0]));
	__init(&ctx, av[1], av[ac - 1], ep);
	// if (ctx.fds.save == -1 || pipeline_recursive(&ctx, av + 2, ac - 3, 0))
	if (ctx.fds.save == -1 || pipeline_iterative(&ctx, av + 2, ac - 3, 0))
	{
		pid_lst_wait(&ctx.pids);
		pid_lst_clear(&ctx.pids);
		ft_fddel(&ctx.fds.save);
		perror(av[0]);
		return (EXIT_FAILURE);
	}
	pid_lst_wait(&ctx.pids);
	pid_lst_clear(&ctx.pids);
	ft_fddel(&ctx.fds.save);
	return (EXIT_SUCCESS);
}
