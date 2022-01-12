/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:42:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 11:51:31 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

# include "type/t_ctx.h"
# include "type/t_int.h"

int		pipeline_iterative(t_ctx *const ctx, char const **cmd_arr,
			t_uint const cmd_cnt, t_uint i)
		__attribute__((nonnull));
int		pipeline_recursive(t_ctx *const ctx, char const **cmd_arr,
			t_uint const cmd_cnt, t_uint const i)
		__attribute__((nonnull));
int		redirect(int const redirin, int const redirout);
int		run(char const *cmd, char const **ep)
		__attribute__((nonnull));

char	*get_env(char const *varname, char const **ep)
		__attribute__((nonnull));
char	*str3join(char const *str0, char const *str1, char const *str2)
		__attribute__((nonnull));

#endif
