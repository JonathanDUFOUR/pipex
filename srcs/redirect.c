/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:24:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/11 00:58:16 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"

/*
	Close the write entry of the given `l_pipe`
	Close the read entry of the given `r_pipe`
	Redirect the STDIN_FILENO to the read entry of the given `l_pipe`
	Redirect the STDOUT_FILENO to the write entry of the given `r_pipe`
*/
int	redirect(int *const l_pipe, int *const r_pipe)
{
	fprintf(stderr, "Enter: %s\n", __func__);
	if ((ft_fddel(&l_pipe[1])
			| ft_fddel(&r_pipe[0])
			| close(STDIN_FILENO)
			| close(STDOUT_FILENO))
		== -1
		|| dup2(l_pipe[0], STDIN_FILENO) == -1
		|| dup2(r_pipe[1], STDOUT_FILENO) == -1)
	{
		ft_fddel(&l_pipe[0]);
		ft_fddel(&r_pipe[1]);
		return (EXIT_FAILURE);
	}
	fprintf(stderr, "Leave: %s\n", __func__);
	return (EXIT_SUCCESS);
}
