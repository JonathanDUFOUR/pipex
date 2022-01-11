/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   str3join.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 23:31:20 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/10 23:45:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include "ft_string.h"

char	*str3join(char const *str0, char const *str1, char const *str2)
{
	char			*output;
	size_t const	len0 = ft_strlen(str0);
	size_t const	len1 = ft_strlen(str1);
	size_t const	len2 = ft_strlen(str2);

	output = malloc((len0 + len1 + len2 + 1) * sizeof(char));
	if (!output)
		return (NULL);
	output[len0 + len1 + len2] = 0;
	ft_memcpy(output + len0 + len1, str2, len2);
	ft_memcpy(output + len0, str1, len1);
	return (ft_memcpy(output, str0, len0));
}
