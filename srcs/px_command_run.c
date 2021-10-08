/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_command_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:10:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 04:22:03 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DEBUG */
#include <stdio.h>

#include <unistd.h>
#include "ft_string.h"
#include "ft_mem.h"
#include "pipex.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	px_command_run(int fd_in, int fd_out, char const *cmd)
{
	char	*file;

	printf("Running command: %s\n", cmd);
	file = px_file_content_get(fd_in);
	if (!file)
		return (FILE_CONTENT_GET_ERR);
	if (write(fd_out, file, ft_strlen(file)) == -1)
		return (WRITE_ERR);
	ft_memdel(&file);
	return (SUCCESS);
}
