/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:33:13 by user42            #+#    #+#             */
/*   Updated: 2021/09/16 17:15:34 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/ft_pipex.h"

int	main(int argc, char **argv, char **env)
{
	int		in;
	int		out;

	if (argc < 5)
		ft_exit("usage : ./pipex file1 cmd1 cmd2 file2\n", NULL);
	in = open(argv[1], O_RDONLY);
	if (in == -1)
		ft_exit("input file error : ", argv[1]);
	out = open(argv[argc - 1], O_WRONLY);
	if (out == -1)
		ft_exit("output file error : ", argv[argc - 1]);
	if (dup2(in, STDIN) == -1)
		ft_exit("Failed to connect infile with STDIN", NULL);
	if (dup2(out, STDOUT) == -1)
		ft_exit("Failed to connect STDOUT with pipe's WRITE END", NULL);
	ft_pipex(argv, env, in, out);
}
