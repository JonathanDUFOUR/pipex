/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process_run_parent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 12:03:22 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex.h"
#include "enum/e_fd.h"
#include "enum/e_ret.h"

int	px_process_run(int *prev, int *next, char const *av)
{
	if (close(prev[WR]) == -1)
		return (CLOSE_ERR);
	prev[WR] = -1;
	if (close(next[RD]) == -1)
		return (CLOSE_ERR);
	next[RD] = -1;
	return (px_command_run(prev[RD], next[WR], av));
}