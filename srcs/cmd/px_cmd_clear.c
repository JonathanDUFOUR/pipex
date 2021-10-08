/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cmd_clear.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 07:37:18 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 11:07:12 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_mem.h"
#include "type/t_cmd.h"

int	px_cmd_clear(t_cmd *cmd, int const ret)
{
	ft_memdel(&cmd->av);
	ft_memdel(&cmd->name);
	ft_memdel(&cmd->path);
	ft_memset(cmd, 0, sizeof(t_cmd));
	return (ret);
}
