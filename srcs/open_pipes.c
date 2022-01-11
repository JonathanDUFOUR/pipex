/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_pipes.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:28:26 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/11 01:16:38 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "pipex.h"

/*
	Create one pipe,
	storing its associated file descriptors in the given `pipe0`
*/
int	open_pipe(int *const pipe0)
{
	if (pipe(pipe0) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
	Create two pipes,
	storing their associated file descriptors in both given `pipe0` and `pipe1`
*/
int	open_pipes(int *const pipe0, int *const pipe1)
{
	if (pipe(pipe0) == -1 || pipe(pipe1) == -1)
		return (close_pipes(pipe0, pipe1) | EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
