/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_wait.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:50:59 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 00:52:07 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <sys/wait.h>
#include "type/t_pid.h"

int	pid_wait(t_pid *const node)
{
	if (waitpid(node->id, NULL, 0) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
