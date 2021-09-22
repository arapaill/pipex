/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: arapaill <arapaill@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/16 16:32:55 by arapaill          #+#    #+#             */
/*   Updated: 2021/09/21 13:48:21 by arapaill         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/ft_pipex.h"

char	*ft_strjoin_free(char *s1, char *s2)
{
	char	*array;
	size_t	len1;
	size_t	len2;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	array = malloc(sizeof(char ) * (len1 + len2 + 1));
	if (!array)
		return (NULL);
	ft_memcpy(array, s1, len1);
	ft_memcpy(&array[len1], s2, len2 + 1);
	free(s1);
	return (array);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*array;
	size_t	len1;
	size_t	len2;

	if (s2 == NULL)
		return (NULL);
	if (s1 == NULL)
		return (ft_strdup(s2));
	len1 = ft_strlen(s1);
	len2 = ft_strlen(s2);
	array = malloc(sizeof(char ) * (len1 + len2 + 1));
	if (!array)
		return (NULL);
	ft_memcpy(array, s1, len1);
	ft_memcpy(&array[len1], s2, len2 + 1);
	return (array);
}
