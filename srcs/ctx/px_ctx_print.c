/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ctx_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 21:43:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/05 03:38:58 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type/t_ctx.h"

void	px_ctx_print(void)
{
	t_ctx *const	ctx = px_ctx_get();
	char			**path;

	printf("ctx->infile_fd: %d\n", ctx->infile_fd);
	printf("ctx->outfile_fd: %d\n", ctx->outfile_fd);
	printf("ctx->infile_name: %s\n", ctx->infile_name);
	printf("ctx->outfile_name: %s\n", ctx->outfile_name);
	printf("ctx->infile_content:\n%s\n", ctx->infile_content);
	printf("ctx->path:\n");
	path = ctx->path;
	while (path && *path)
		printf("\t%s\n", *path++);
}
