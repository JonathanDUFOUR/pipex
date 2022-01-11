/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_infile.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 15:17:58 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/10 19:42:48 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
	Open the given infile `file`
	and store its associated file descriptor in the given `fd`
*/
int	open_infile(char const *file, int *const fd)
{
	*fd = open(file, O_RDONLY);
	if (*fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
