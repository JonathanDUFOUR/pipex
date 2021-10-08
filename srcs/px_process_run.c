/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/09 00:35:33 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "pipex.h"
#include "enum/e_fd.h"
#include "enum/e_ret.h"

int	px_process_run(int *prev, int *next, char const *av)
{
	if (prev[WR] != -1 && close(prev[WR]) == -1)
		return (CLOSE_ERR);
	prev[WR] = -1;
	if (next[RD] != -1 && close(next[RD]) == -1)
		return (CLOSE_ERR);
	next[RD] = -1;
	return (px_command_run(prev[RD], next[WR], av));
}
