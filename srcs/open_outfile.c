/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   open_outfile.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 19:39:09 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/10 19:42:04 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <unistd.h>
#include <fcntl.h>

/*
	Open the given outfile `file`
	and store its associated file descriptor in the given `fd`
*/
int	open_outfile(char const *file, int *const fd)
{
	*fd = open(file, O_CREAT | O_TRUNC | O_WRONLY, 0644);
	if (*fd == -1)
		return (EXIT_FAILURE);
	return (EXIT_SUCCESS);
}
