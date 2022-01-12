/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_pid_lst.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/11 23:02:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 06:55:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_PID_LST_H
# define T_PID_LST_H

# include "type/t_pid.h"

typedef struct s_pid_lst	t_pid_lst;

struct s_pid_lst
{
	t_pid	*head;
	t_pid	*tail;
	size_t	size;
};

int		pid_lst_add_back(t_pid_lst *const lst, pid_t const id)
		__attribute__((nonnull(1)));
int		pid_lst_wait(t_pid_lst *const lst)
		__attribute__((nonnull));

void	pid_lst_clear(t_pid_lst *const lst)
		__attribute__((nonnull));
void	pid_lst_push_back(t_pid_lst *const lst, t_pid *const node)
		__attribute__((nonnull));

#endif
