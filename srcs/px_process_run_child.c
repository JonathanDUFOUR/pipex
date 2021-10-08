/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process_run_child.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:27:19 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 02:05:04 by jodufour         ###   ########.fr       */
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
	printf("CHILD %u - prev[RD]: %d\n", depth, prev[RD]);
	printf("CHILD %u - prev[WR]: %d\n", depth, prev[WR]);
	printf("CHILD %u - next[RD]: %d\n", depth, next[RD]);
	printf("CHILD %u - next[WR]: %d\n", depth, next[WR]);
}

static int	legacy_transfer(t_uint const depth, int *prev, int *next)
{
	char	*legacy;

	legacy = px_file_content_get(prev[RD]);
	if (!legacy)
		return (FILE_CONTENT_GET_ERR);
	printf("CHILD %u - This is my legacy: |%s|\n", depth, legacy);
	printf("CHILD %u - Sending it to outfile\n", depth);
	if (write(next[WR], legacy, ft_strlen(legacy)) == -1)
		return (WRITE_ERR);
	printf("CHILD %u - Done!\n", depth);
	ft_memdel(&legacy);
	return (SUCCESS);
}

int	px_process_run_child(t_uint const depth, int *prev, int *next)
{
	if (close(prev[WR]) == -1)
		return (CLOSE_ERR);
	prev[WR] = -1;
	if (close(next[RD]) == -1)
		return (CLOSE_ERR);
	next[RD] = -1;
	return (legacy_transfer(depth, prev, next));
	return (SUCCESS);
}
