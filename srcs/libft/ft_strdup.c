/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: user42 <user42@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/08/10 10:24:11 by user42            #+#    #+#             */
/*   Updated: 2021/08/10 10:27:51 by user42           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_pipex.h"

char	*ft_strdup(const char *s)
{
	char			*str;
	unsigned int	n;

	n = ft_strlen(s);
	str = malloc((sizeof(char) * (n + 1)))
	if (!str)
		ft_exit("Error malloc\n");
	ft_strlcpy(str, s, n + 1);
	str[n] = '\0';
	return (str);
}
