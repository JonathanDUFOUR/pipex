/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:45:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/09 10:05:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <errno.h>
#include <unistd.h>
#include "ft_string.h"
#include "ft_mem.h"
#include "ft_io.h"
#include "colors.h"
#include "err_msg_lookup.h"

void	px_err_msg(int err)
{
	char	*msg;
	char	*tmp;
	int		i;

	msg = ft_strdup(RED "Error\n");
	i = 0;
	while (g_err_msg[i].msg && err != g_err_msg[i].err)
		++i;
	if (g_err_msg[i].msg)
	{
		msg = ft_strjoin(tmp = msg, g_err_msg[i].msg);
		ft_memdel(&tmp);
		if (g_err_msg[i].detail)
		{
			msg = ft_strjoin(tmp = msg, ": ");
			ft_memdel(&tmp);
			msg = ft_strjoin(tmp = msg, strerror(errno));
			ft_memdel(&tmp);
		}
	}
	msg = ft_strjoin(tmp = msg, "\n" WHITE);
	ft_memdel(&tmp);
	ft_putstr_fd(msg, 2);
	ft_memdel(&msg);
}
