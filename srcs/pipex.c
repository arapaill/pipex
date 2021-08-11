/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:33:07 by user42            #+#    #+#             */
/*   Updated: 2021/08/11 10:29:06 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

void	ft_pipex(char *cmd, char **env, int in)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		ft_exit("Failed to create a pipe\n", NULL);
	pid = fork();
	if (pid)
	{
		close(pipefd[1]);
		dup2(pipefd[0], STDIN);
		waitpid(pid, NULL, 0);
	}
	else
	{
		close(pipefd[0]);
		dup2(pipefd[1], STDOUT);
		if (in == STDIN)
			ft_exit("failed to dup2\n", NULL);
		else
			ft_exec(cmd, env);
	}
}

char	*cut(char *str, size_t size)
{
	char				*array;
	unsigned int		i;

	i = 0;
	array = malloc(sizeof(char) * (size + 1));
	if (!array)
		ft_exit("Malloc Error\n", NULL);
	while (i < size)
		array[i++] = *str++;
	array[size] = 0;
	return (array);
}

char	*ft_join_path(char *path, char *bin)
{
	char	*ret;
	int		i;
	int		len1;
	int		len2;

	if (!bin)
		return (NULL);
	if (!path)
		return (ft_strdup(bin));
	len1 = ft_strichr(path, 0);
	len2 = ft_strichr(bin, 0);
	i = -1;
	ret = malloc(sizeof(char *) * len1 + len2 + 2);
	if (!ret)
		return (NULL);
	while (++i < len1)
		ret[i] = path[i];
	ret[i++] = '/';
	free(path);
	i = -1;
	while (++i < len2)
		ret[len1 + i] = bin[len2];
	ret[len1 + i] = '\0';
	return (ret);
}

char	*get_path(char *arg, char **env)
{
	char	*path;
	char	*dir;
	char	*bin;
	int		i;

	i = 0;
	while (env[i] && ft_strncmp(env[i], "PATH=", 5))
		i++;
	if (!env[i])
		return (arg);
	path = env[i] + 5;
	while (path && ft_strichr(path, ':') > -1)
	{
		dir = cut(path, ft_strichr(path, ':'));
		bin = ft_join_path(dir, arg);
		if (access(bin, F_OK) == 0)
			return (bin);
		free(bin);
		path += ft_strichr(path, ':') + 1;
	}
	return (arg);
}

void	ft_exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

	if (ft_strlen(cmd) == 0)
		ft_exit("command not found\n", NULL);
	args = ft_split(cmd, ' ');
	if ((ft_strichr(args[0], '/')) > -1)
		path = args[0];
	else
		path = get_path(args[0], env);
	execve(path, args, env);
	ft_exit("command not found: ", cmd);
}
