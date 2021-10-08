/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_cmd_name_get.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 07:28:47 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 07:31:34 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_io.h"
#include "ft_string.h"

char	*px_cmd_name_get(char const *av)
{
	char		*output;
	char const	*ptr;

	while (ft_isspace(*av))
		++av;
	ptr = av;
	while (*ptr && !ft_isspace(*ptr))
		++ptr;
	output = ft_strndup(av, ptr - av);
	return (output);
}
