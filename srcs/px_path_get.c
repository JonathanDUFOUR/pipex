/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_path_get.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/05 00:48:02 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/05 02:48:47 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

char	**px_path_get(char const **ep)
{
	while (*ep)
	{
		if (ft_strnstr(*ep, "PATH", 4))
			return (ft_split((*ep) + 5, ':'));
		++ep;
	}
	return (NULL);
}
