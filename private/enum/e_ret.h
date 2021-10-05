/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   e_ret.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:29:21 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/05 03:52:26 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef E_RET_H
# define E_RET_H

enum	e_ret
{
	SUCCESS,
	AC_ERR,
	PIPE_ERR,
	FORK_ERR,
	OPEN_ERR,
	CLOSE_ERR,
	PATH_GET_ERR,
	FILE_CONTENT_GET_ERR
};

#endif
