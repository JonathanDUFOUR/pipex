/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ctx_init.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 02:05:58 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/05 00:45:10 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include "pipex.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	px_ctx_init(int const ac, char const **av, char const **ep)
{
	t_ctx *const	ctx = px_ctx_get();

	ctx->infile_name = av[1];
	ctx->outfile_name = av[ac - 1];
	ctx->infile_fd = open(ctx->infile_name, O_RDONLY);
	if (ctx->infile_fd == -1)
		return (OPEN_ERR);
	ctx->outfile_fd = open(ctx->outfile_name, O_WRONLY);
	if (ctx->outfile_fd == -1)
		return (OPEN_ERR);
	ctx->infile_content = px_file_content_get(ctx->infile_fd);
	if (!ctx->infile_content)
		return (FILE_CONTENT_GET_ERR);
	ctx->path = px_path_get(ep);
	if (!ctx->path)
		return (PATH_GET_ERR);
	return (SUCCESS);
}
