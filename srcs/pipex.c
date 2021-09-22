/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:33:07 by user42            #+#    #+#             */
/*   Updated: 2021/09/22 08:37:55 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

void	need_space(int pipefd[2], int out, char **argv, char **env)
{
	pid_t	pid_two;

	pid_two = fork();
	if (pid_two == -1)
		ft_exit("Failed to create a fork\n", NULL);
	if (!pid_two)
	{	
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		dup2(out, STDOUT);
		ft_exec(argv[3], env);
	}
	else
		close(out);
}

void	ft_pipex(char **argv, char **env, int in, int out)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		ft_exit("Failed to create a pipe\n", NULL);
	pid = fork();
	if (pid == -1)
		ft_exit("Failed to create a fork\n", NULL);
	if (!pid)
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		dup2(in, STDIN);
		ft_exec(argv[2], env);
	}
	else
	{
		waitpid(pid, NULL, 0);
		close(in);
		need_space(pipefd, out, argv, env);
	}
}

char	**get_path(char **env)
{
	char	**path;
	int		i;

	i = -1;
	path = NULL;
	while (env[++i])
	{
		if (ft_strncmp(env[i], "PATH=", 5) == 0)
		{
			path = ft_split((env[i] + 5), ':');
			break ;
		}
	}
	return (path);
}

void	free_array(char **array)
{
	int		i;

	i = -1;
	while (array[++i])
		free (array[i]);
	free(array);
}

void	ft_exec(char *cmd, char **env)
{
	char	**args;
	char	**path;
	char	*tmp;
	size_t	i;

	i = -1;
	if (ft_strlen(cmd) == 0)
		ft_exit("command not found\n", NULL);
	args = ft_split(cmd, ' ');
	path = get_path(env);
	while (path[++i])
	{
		if (args[0][0] != '/')
		{
			tmp = ft_strjoin(path[i], "/");
			tmp = ft_strjoin_free(tmp, args[0]);
		}
		execve(tmp, args, env);
		free(tmp);
	}
	free_array(args);
	free_array(path);
	ft_exit("command not found: ", cmd);
}
