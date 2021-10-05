/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_ctx_get.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:53:44 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/05 00:43:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include "type/t_ctx.h"

t_ctx	*px_ctx_get(void)
{
	static t_ctx	ctx = {-1, -1, NULL, NULL, NULL, NULL};

	return (&ctx);
}
