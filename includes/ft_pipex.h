/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pipex.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:36:23 by user42            #+#    #+#             */
/*   Updated: 2021/08/05 14:42:15 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PIPEX_H
# define FT_PIPEX_H

# include <stdlib.h>
# include <stdio.h>
# include <stddef.h>
# include <unistd.h>
# include <math.h>
# include <time.h>
# include <unistd.h>
# include <fcntl.h>
# include <sys/wait.h>

/*
** libft
*/
void	ft_exit(char *msg);
void	ft_putstr_fd(char *s, int fd);

/*
** pipex
*/
void    ft_pipex(int argc, char **argv);
#endif