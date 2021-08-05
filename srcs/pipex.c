/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pipex.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:33:07 by user42            #+#    #+#             */
/*   Updated: 2021/08/05 15:23:52 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

void	ft_pipex(int argc, char **argv)
{
	int		in;
	int		out;
	int		pid;
	int		pipefd[2];

	in = open(argv[1], O_RDONLY);
	if (in == -1)
		ft_exit("input file (file1) error\n");
	out = open(argv[argc - 1], O_WRONLY);
	if (out == -1)
		ft_exit("output file (file2) error\n");
	if (pipe(pipefd) == -1)
		ft_exit("Failed to create a pipe.");
	pid = fork;
}
