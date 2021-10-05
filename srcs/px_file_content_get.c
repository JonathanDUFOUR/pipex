/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_file_content_get.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/04 23:54:26 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/05 00:20:42 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_mem.h"
#include "ft_string.h"
#include "pipex.h"

char	*px_file_content_get(int const fd)
{
	char	buff[BUFFER_SIZE + 1];
	char	*output;
	char	*tmp;
	ssize_t	rd;

	output = NULL;
	rd = read(fd, buff, BUFFER_SIZE);
	while (rd > 0)
	{
		buff[rd] = 0;
		tmp = output;
		output = ft_strjoin(output, buff);
		ft_memdel(&tmp);
		if (!output)
			return (NULL);
		rd = read(fd, buff, BUFFER_SIZE);
	}
	if (rd == -1)
	{
		ft_memdel(&output);
		return (NULL);
	}
	return (output);
}
