/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:28:37 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/06 04:00:44 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "pipex.h"
#include "type/t_ctx.h"
#include "enum/e_ret.h"

int	main(int const ac, char const **av, char const **ep)
{
	int	ret;

	if (ac < 5)
		ret = AC_ERR;
	else
		ret = px_ctx_init(ac, av, ep);
	if (ret == SUCCESS)
		px_ctx_print();
	if (ret == SUCCESS)
		ret = px_multi_pipe((t_uint)(ac - 2));
	px_ctx_clear();
	if (ret != SUCCESS)
		px_err_msg(ret);
	return (ret);
}
