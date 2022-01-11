/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipeline.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 18:33:19 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/11 01:00:19 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/* DBG */
#include <stdio.h>

#include <stdlib.h>
#include "pipex.h"

/*
	Execute the commands contained in the given array `cmd_arr` recursively,
	redirecting their input to their left pipe read entry,
	and their output to their right pipe write entry
*/
int	pipeline(char const **cmd_arr, int *const l_pipe, int *const r_pipe,
	char const **ep)
{
	fprintf(stderr, "Enter: %s\n", __func__);
	if (!*cmd_arr)
	{
		fprintf(stderr, "Leave: %s\n", __func__);
		return (EXIT_SUCCESS);
	}
	if (exec(*cmd_arr, l_pipe, r_pipe, ep)
		|| pipeline(cmd_arr + 1, r_pipe, l_pipe, ep))
		return (EXIT_FAILURE);
	fprintf(stderr, "Leave: %s\n", __func__);
	return (EXIT_SUCCESS);
}
