/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:42:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/05 04:06:46 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 4096
# endif

# include <stddef.h>

int		px_multi_pipe(int const ac);
int		px_process_run_child(int *fd);
int		px_process_run_parent(int *fd);

void	px_err_msg(int err);

char	*px_file_content_get(int const fd);

char	**px_path_get(char const **ep);

#endif
