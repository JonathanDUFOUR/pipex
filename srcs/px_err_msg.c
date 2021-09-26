/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_err_msg.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:45:55 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/26 02:46:45 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <unistd.h>
#include "colors.h"
#include "err_msg_lookup.h"

void	px_err_msg(int err)
{
	int	i;

	write(2, RED "Error:\n", 12);
	i = 0;
	while (g_err_msg[i].msg && err != g_err_msg[i].err)
		++i;
	if (g_err_msg[i].msg)
	{
		if (g_err_msg[i].detail)
			perror(g_err_msg[i].msg);
		else
			write(2, g_err_msg[i].msg, g_err_msg[i].len);
	}
	write(2, WHITE "\n", 5);
}
