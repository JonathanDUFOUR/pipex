/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:54:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 08:16:54 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	int			infile_fd;
	int			outfile_fd;
	char const	**path;
	char const	**ep;
};

int		px_ctx_init(int const ac, char const **av, char const **ep);

void	px_ctx_clear(void);
void	px_ctx_print(void);

t_ctx	*px_ctx_get(void);

#endif
