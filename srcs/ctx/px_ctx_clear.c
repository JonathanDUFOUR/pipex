/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ctx_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:17:52 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/06 02:12:20 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include "ft_mem.h"
#include "pipex.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

void	px_ctx_clear(void)
{
	t_ctx *const	ctx = px_ctx_get();

	if (ctx->infile_fd != -1 && close(ctx->infile_fd) == -1)
		px_err_msg(CLOSE_ERR);
	if (ctx->outfile_fd != -1 && close(ctx->outfile_fd) == -1)
		px_err_msg(CLOSE_ERR);
	free(ctx->path);
	ft_memset(ctx, 0, sizeof(t_ctx));
}
