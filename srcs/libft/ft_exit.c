/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/05 11:33:43 by user42            #+#    #+#             */
/*   Updated: 2021/08/11 10:17:17 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_pipex.h"

void	ft_putstr(char *s)
{
	while (*s)
		write(1, s++, 1);
}

void	ft_exit(char *msg, char *name)
{
	ft_putstr("pipex : ");
	ft_putstr(msg);
	if (name)
	{
		ft_putstr(name);
		write(1, "\n", 1);
	}
	exit(0);
}
