/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redirect.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:24:49 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 06:10:55 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include "ft_io.h"

/*
	Redirect the STDIN_FILENO to the given file descriptor `redirin`
	Redirect the STDOUT_FILENO to the given file descriptor `redirout`
*/
int	redirect(int const redirin, int const redirout)
{
	if ((close(STDIN_FILENO) | close(STDOUT_FILENO)) == -1
		|| dup2(redirin, STDIN_FILENO) == -1
		|| dup2(redirout, STDOUT_FILENO) == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
