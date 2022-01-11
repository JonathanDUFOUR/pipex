/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_env.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 21:23:33 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/10 21:49:00 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

/*
	Search in the given env `ep` the given variable `varname`
	Return the value of the variable upon success
	Return NULL upon failure
*/
char	*get_env(char const *varname, char const **ep)
{
	size_t const	len = ft_strlen(varname);
	char const		*assign;

	while (*ep)
	{
		if (!ft_strncmp(varname, *ep, len))
		{
			assign = ft_strchr(*ep, '=');
			if (!assign)
				return ((char *)*ep + ft_strlen(*ep));
			return ((char *)assign + 1);
		}
		++ep;
	}
	return (NULL);
}
