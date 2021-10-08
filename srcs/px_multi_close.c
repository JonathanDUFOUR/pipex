/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_multi_close.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 23:35:50 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/09 01:20:08 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_io.h"
#include "type/t_int.h"
#include "enum/e_fd.h"
#include "enum/e_ret.h"

int	px_multi_close(int **fd, t_uint const pipe_count, t_uint const depth)
{
	t_uint	i;

	i = 0;
	while (i < pipe_count)
	{
		if (i == depth)
		{
			if (fd[i][WR] != -1 && ft_fddel(&fd[i][WR]) == -1)
				return (CLOSE_ERR);
		}
		else if (i == (depth + 1))
		{
			if (fd[i][RD] != -1 && ft_fddel(&fd[i][RD]) == -1)
				return (CLOSE_ERR);
		}
		else
		{
			if ((fd[i][RD] != -1 && ft_fddel(&fd[i][RD]) == -1)
				|| (fd[i][WR] != -1 && ft_fddel(&fd[i][WR]) == -1))
				return (CLOSE_ERR);
		}
		++i;
	}
	return (SUCCESS);
}
