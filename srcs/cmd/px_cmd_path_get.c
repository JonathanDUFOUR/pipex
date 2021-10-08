/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cmd_path_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 08:02:32 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 08:13:56 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_mem.h"
#include "ft_string.h"
#include "type/t_ctx.h"
#include "type/t_cmd.h"

char	*px_cmd_path_get(char const *cmd_name, char const **path)
{
	char	*output;
	char	*tmp;

	output = NULL;
	while (path && *path)
	{
		tmp = output;
		output = ft_strjoin(*path, "/");
		ft_memdel(&tmp);
		if (!output)
			return (NULL);
		tmp = output;
		output = ft_strjoin(output, cmd_name);
		ft_memdel(&tmp);
		if (!output)
			return (NULL);
		if (!access(output, X_OK))
			return (output);
		++path;
	}
	return (NULL);
}
