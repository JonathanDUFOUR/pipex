/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cmd_print.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 09:18:07 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 11:12:25 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include "type/t_cmd.h"

void	px_cmd_print(t_cmd cmd)
{
	printf("cmd.name: %s\n", cmd.name);
	printf("cmd.path: %s\n", cmd.path);
	printf("cmd.av:\n");
	while (cmd.av && *cmd.av)
		printf("\t%s\n", *cmd.av++);
}
