/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   err_msg_lookup.h                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:46:27 by jodufour          #+#    #+#             */
/*   Updated: 2021/09/26 03:46:57 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef ERR_MSG_LOOKUP_H
# define ERR_MSG_LOOKUP_H

# include <stddef.h>
# include <stdbool.h>
# include "enum/e_ret.h"

typedef struct s_err_msg	t_err_msg;

struct s_err_msg
{
	int const		err;
	char const		*msg;
	size_t const	len;
	bool const		detail;
};

static t_err_msg const		g_err_msg[] = {
	{AC_ERR, "Too few arguments", 17, false},
	{OPEN_ERR, "open() failed", 13, true},
	{CLOSE_ERR, "close() failed", 14, true},
	{0, NULL, 0, false}
};

#endif
