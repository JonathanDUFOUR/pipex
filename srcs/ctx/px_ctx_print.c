/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ctx_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 08:19:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type/t_ctx.h"

void	px_ctx_print(void)
{
	t_ctx *const	ctx = px_ctx_get();
	char const		**path = ctx->path;
	char const		**ep = ctx->ep;

	printf("ctx->infile_fd: %d\n", ctx->infile_fd);
	printf("ctx->outfile_fd: %d\n", ctx->outfile_fd);
	printf("ctx->path:\n");
	while (path && *path)
		printf("\t%s\n", *path++);
	printf("ctx->ep:\n");
	while (ep && *ep)
		printf("\t%s\n", *ep++);
}
