/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/26 00:42:55 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/11 01:18:01 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PIPEX_H
# define PIPEX_H

int		close_pipe(int *const pipe0)
		__attribute__((nonnull));
int		close_pipes(int *const pipe0, int *const pipe1)
		__attribute__((nonnull));
int		exec(char const *cmd, int *const l_pipe, int *const r_pipe,
			char const **ep)
		__attribute__((nonnull));
int		open_infile(char const *file, int *const fd)
		__attribute__((nonnull));
int		open_outfile(char const *file, int *const fd)
		__attribute__((nonnull));
int		open_pipe(int *const pipe0)
		__attribute__((nonnull));
int		open_pipes(int *const pipe0, int *const pipe1)
		__attribute__((nonnull));
int		pipeline(char const **cmd_arr, int *const l_pipe, int *const r_pipe,
			char const **ep)
		__attribute__((nonnull));
int		redirect(int *const l_pipe, int *const r_pipe)
		__attribute__((nonnull));
int		run(char const *cmd, char const **ep)
		__attribute__((nonnull));

char	*get_env(char const *varname, char const **ep)
		__attribute__((nonnull));
char	*str3join(char const *str0, char const *str1, char const *str2)
		__attribute__((nonnull));

#endif
