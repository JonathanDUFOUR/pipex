/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:28:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/26 02:17:35 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	main(int const ac, char const **av)
{
	int	ret;

	if (ac < 5)
		ret = AC_ERR;
	else
	{
		ret = px_ctx_init(ac, av);
	}
	if (ret != SUCCESS)
		px_err_msg(ret);
	px_ctx_clear();
	return (ret);
}
