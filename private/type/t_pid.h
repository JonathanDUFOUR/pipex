/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pid.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 06:51:03 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 00:59:15 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PID_H
# define T_PID_H

# include "sys/types.h"

typedef struct s_pid	t_pid;

struct s_pid
{
	pid_t	id;
	t_pid	*next;
};

int		pid_wait(t_pid *const node)
		__attribute__((nonnull));

t_pid	*pid_new(pid_t const id);

#endif
