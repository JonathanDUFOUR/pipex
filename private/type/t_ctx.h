/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:54:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/10 20:31:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	char const	*first_cmd;
	char const	*last_cmd;
	int			fd_in;
	int			fd_out;
	int			pipe0[2];
	int			pipe1[2];
};

#endif
