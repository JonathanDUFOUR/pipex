/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_lst_push_back.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:54:56 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 06:55:36 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "type/t_pid_lst.h"

void	pid_lst_push_back(t_pid_lst *const lst, t_pid *const node)
{
	if (!lst->size)
		lst->head = node;
	else
		lst->tail->next = node;
	lst->tail = node;
	++lst->size;
}
