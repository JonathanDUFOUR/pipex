/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_lst_clear.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:52:51 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 00:54:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "type/t_pid_lst.h"

void	pid_lst_clear(t_pid_lst *const lst)
{
	t_pid	*next;

	while (lst->head)
	{
		next = lst->head->next;
		free((void *)lst->head);
		lst->head = next;
	}
	lst->tail = NULL;
	lst->size = 0;
}
