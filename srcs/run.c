/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   run.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: jodufour <jodufour@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/10 20:37:08 by jodufour          #+#    #+#             */
/*   Updated: 2022/01/12 05:51:32 by jodufour         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "ft_string.h"
#include "pipex.h"

static int	__relabs_path(char const *cmd, char const **ep)
{
	char const	**av = (char const **)ft_split(cmd, ' ');

	if (!av)
		return (EXIT_FAILURE);
	if (access(av[0], F_OK) || access(av[0], X_OK))
	{
		perror(av[0]);
		ft_memdel(&av);
		return (EXIT_SUCCESS);
	}
	if (execve(av[0], (char *const *)av, (char *const *)ep) == -1)
	{
		ft_memdel(&av);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

static char	*__get_abs_path(char const *cmd, char const **ep)
{
	char const	*path = get_env("PATH", ep);
	char		**pathes;
	char		*abs_path;
	int			i;

	if (!path)
		return (NULL);
	pathes = ft_split(path, ':');
	if (!pathes)
		return (NULL);
	abs_path = NULL;
	i = 0;
	while (pathes[i])
	{
		abs_path = str3join(pathes[i], "/", cmd);
		if (!abs_path || !access(abs_path, F_OK))
			break ;
		ft_memdel(&abs_path);
		++i;
	}
	ft_memdel(&pathes);
	return (abs_path);
}

static int	__env_path(char const *cmd, char const **ep)
{
	char const	**av = (char const **)ft_split(cmd, ' ');

	if (!av)
		return (EXIT_FAILURE);
	av[0] = __get_abs_path(av[0], ep);
	if (!av[0])
	{
		perror(av[0]);
		ft_memdel(&av);
		return (EXIT_SUCCESS);
	}
	if (access(av[0], X_OK))
	{
		perror(av[0]);
		ft_memdel(&av[0]);
		ft_memdel(&av);
		return (EXIT_SUCCESS);
	}
	if (execve(av[0], (char *const *)av, (char *const *)ep) == -1)
	{
		ft_memdel(&av[0]);
		ft_memdel(&av);
		return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}

/*
	Run the given `cmd` in the current process, using the given env `ep`
*/
int	run(char const *cmd, char const **ep)
{
	if ((cmd[0] == '/') || (cmd[0] == '.' && cmd[1] == '/'))
	{
		if (__relabs_path(cmd, ep))
			return (EXIT_FAILURE);
	}
	else
	{
		if (__env_path(cmd, ep))
			return (EXIT_FAILURE);
	}
	return (EXIT_SUCCESS);
}
