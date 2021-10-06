/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_process_run_parent.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 23:28:12 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/06 04:05:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "ft_mem.h"
#include "pipex.h"
#include "enum/e_fd.h"
#include "enum/e_ret.h"

/*
**	./pipex infile cmd0 cmd1 outfile
**	             W-R  W-R  W-R
*/
int	px_process_run_parent(int depth)
{
	printf("PARENT %d - I am alive !\n", depth);
	return (SUCCESS);
}
