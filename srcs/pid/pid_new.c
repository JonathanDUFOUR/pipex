/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pid_new.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/12 00:41:30 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 00:48:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "t_pid.h"

t_pid	*pid_new(pid_t const id)
{
	t_pid	*node;

	node = malloc(sizeof(t_pid));
	if (!node)
		return (NULL);
	node->id = id;
	node->next = NULL;
	return (node);
}
