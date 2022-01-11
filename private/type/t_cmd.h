/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 06:51:03 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/10 14:40:40 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CMD_H
# define T_CMD_H

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char	*name;
	char	*path;
	char	**av;
};

#endif
