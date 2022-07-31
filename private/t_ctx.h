/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:54:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 05:50:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

# include "t_fds.h"
# include "t_pid_lst.h"

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	char const	*infile;
	char const	*outfile;
	char const	**ep;
	t_pid_lst	pids;
	t_fds		fds;
};

#endif
