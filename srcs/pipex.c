/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:33:07 by user42            #+#    #+#             */
/*   Updated: 2021/08/06 11:23:12 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

void	ft_pipex(char *cmd, char **env, int in)
{
	pid_t	pid;
	int		pipefd[2];

	if (pipe(pipefd) == -1)
		ft_exit("Failed to create a pipe.");
	pid = fork;
	if (pid == -1)
		ft_exit("Failed to pipe\n");
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
			exit(1);
		else
			ft_exec(cmd, env);
	}
}

void	ft_exec(char *cmd, char **env)
{
	char	**args;
	char	*path;

}