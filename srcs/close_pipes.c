/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   close_pipes.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:36:36 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/11 01:20:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"

/*
	Close both entries of the given pipe `pipe0`
	and set their value to -1
	Foreach negative given file descriptor, do nothing
*/
int	close_pipe(int *const pipe0)
{
	if ((ft_fddel(&pipe0[0])
			| ft_fddel(&pipe0[1]))
		== -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}

/*
	Close both entries of both given pipes `pipe0` and `pipe1`
	and set their value to -1
	Foreach negative given file descriptor, do nothing
*/
int	close_pipes(int *const pipe0, int *const pipe1)
{
	if ((ft_fddel(&pipe0[0])
			| ft_fddel(&pipe0[1])
			| ft_fddel(&pipe1[0])
			| ft_fddel(&pipe1[1]))
		== -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
