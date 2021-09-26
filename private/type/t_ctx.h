/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_ctx.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 01:54:09 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/26 03:03:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CTX_H
# define T_CTX_H

typedef struct s_ctx	t_ctx;

struct s_ctx
{
	int			infile_fd;
	int			outfile_fd;
	char const	*infile_name;
	char const	*outfile_name;
	char		*infile_content;
};

int		px_ctx_init(int const ac, char const **av);

void	px_ctx_clear(void);

t_ctx	*px_ctx_get(void);

#endif
