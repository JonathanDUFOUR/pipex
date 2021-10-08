/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ctx_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 04:10:50 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type/t_ctx.h"

void	px_ctx_print(void)
{
	t_ctx *const	ctx = px_ctx_get();
	char			**path;
	char const		**ep;

	printf("ctx->infile_fd: %d\n", ctx->infile_fd);
	printf("ctx->outfile_fd: %d\n", ctx->outfile_fd);
	printf("ctx->path:\n");
	path = ctx->path;
	while (path && *path)
		printf("\t%s\n", *path++);
	printf("ctx->ep:\n");
	ep = ctx->ep;
	while (ep && *ep)
		printf("\t%s\n", *ep++);
}
