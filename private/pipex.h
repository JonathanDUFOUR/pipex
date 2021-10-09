/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:42:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/09 10:27:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stddef.h>
# include "type/t_int.h"

int		px_command_run(int fd_in, int fd_out, char const *av);
int		px_multi_close(int **fd, t_uint const pipe_count, t_uint const depth);
int		px_multi_fork(int **fd, t_uint const pipe_count, char const **av,
			t_uint depth);
int		px_multi_pipe(t_uint const pipe_count, char const **av);

void	px_err_msg(int err);

char	*px_file_content_get(int const fd);

char	**px_path_get(char const **ep);

#endif
