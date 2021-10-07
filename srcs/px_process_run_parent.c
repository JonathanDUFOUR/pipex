/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process_run_parent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 01:20:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "ft_mem.h"
#include "pipex.h"
#include "enum/e_fd.h"
#include "enum/e_ret.h"

static void	data_print(t_uint const depth, int *prev, int *next)
{
	printf("PARENT %u - prev[RD]: %d\n", depth, prev[RD]);
	printf("PARENT %u - prev[WR]: %d\n", depth, prev[WR]);
	printf("PARENT %u - next[RD]: %d\n", depth, next[RD]);
	printf("PARENT %u - next[WR]: %d\n", depth, next[WR]);
}

static int	legacy_transfer(t_uint const depth, int *prev, int *next)
{
	char	*legacy;

	printf("PARENT %u - Getting my legacy\n", depth);
	legacy = px_file_content_get(prev[RD]);
	if (!legacy)
		return (FILE_CONTENT_GET_ERR);
	printf("PARENT %u - This is my legacy: |%s|\n", depth, legacy);
	if (depth)
		printf("PARENT %u - Sending it to PARENT %u\n", depth, depth - 1);
	else
		printf("PARENT %u - Sending it to outfile\n", depth);
	if (write(next[WR], legacy, ft_strlen(legacy)) == -1)
		return (WRITE_ERR);
	printf("PARENT %u - Done!\n", depth);
	ft_memdel(&legacy);
	return (SUCCESS);
}

int	px_process_run_parent(t_uint const depth, int *prev, int *next)
{
	data_print(depth, prev, next);
	if (close(prev[WR]) == -1)
		return (CLOSE_ERR);
	prev[WR] = -1;
	if (close(next[RD]) == -1)
		return (CLOSE_ERR);
	next[RD] = -1;
	return (legacy_transfer(depth, prev, next));
	return (SUCCESS);
}
