/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   px_command_run.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/10/08 03:10:17 by jodufour          #+#    #+#             */
/*   Updated: 2021/10/08 11:50:17 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include "ft_string.h"
#include "ft_mem.h"
#include "pipex.h"
#include "type/t_ctx.h"
#include "type/t_cmd.h"
#include "enum/e_ret.h"

static int	close_quit(int stdin, int stdout, int const ret)
{
	if (stdin != -1)
		close(stdin);
	if (stdout != -1)
		close(stdout);
	return (ret);
}

static int	reset_quit(int stdin, int stdout, int const ret)
{
	dup2(0, stdin);
	dup2(1, stdout);
	return (ret);
}

int	px_command_run(int fd_in, int fd_out, char const *av)
{
	t_ctx *const	ctx = px_ctx_get();
	t_cmd			cmd;
	int				stdin;
	int				stdout;

	ft_memset(&cmd, 0, sizeof(t_cmd));
	stdin = dup(0);
	stdout = dup(1);
	if (stdin == -1 || stdout == -1)
		return (close_quit(stdin, stdout, DUP_ERR));
	if (dup2(fd_in, 0) == -1 || dup2(fd_out, 1) == -1)
		return (reset_quit(stdin, stdout, DUP2_ERR));
	cmd.name = px_cmd_name_get(av);
	if (!cmd.name)
		return (CMD_NAME_GET_ERR);
	cmd.path = px_cmd_path_get(cmd.name, ctx->path);
	if (!cmd.path)
		return (px_cmd_clear(&cmd, CMD_PATH_GET_ERR));
	cmd.av = ft_split(av, ' ');
	if (!cmd.av)
		return (px_cmd_clear(&cmd, CMD_AV_GET_ERR));
	px_cmd_print(cmd);
	if (execve(cmd.path, cmd.av, (char *const *)ctx->ep) == -1)
		return (px_cmd_clear(&cmd, EXECVE_ERR) + reset_quit(stdin, stdout, 0));
	return (px_cmd_clear(&cmd, SUCCESS) + reset_quit(stdin, stdout, 0));
}
