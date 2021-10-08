/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   t_cmd.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 06:51:03 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 11:07:51 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef T_CMD_H
# define T_CMD_H

# include "type/t_int.h"

typedef struct s_cmd	t_cmd;

struct s_cmd
{
	char	*name;
	char	*path;
	char	**av;
};

int		px_cmd_clear(t_cmd *cmd, int const ret);

char	*px_cmd_name_get(char const *av);
char	*px_cmd_path_get(char const *cmd_name, char const **path);

char	**px_cmd_av_get(t_uint cmd_ac, char const *av, char const *file);

void	px_cmd_print(t_cmd cmd);

t_uint	px_cmd_input_count_get(char const *file);
t_uint	px_cmd_option_count_get(char const *av);

#endif
