/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiron-f <agiron-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:06:20 by agiron-f          #+#    #+#             */
/*   Updated: 2026/08/29 13:18:33 by agiron-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*search_newline(char *str)
{
	if (!str)
		return (0);
	while (*str)
	{
		if (*str == '\n')
			return (1);
		str++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*dest;
	int		i;
	int		j;

	dest = malloc((ft_strchr(s1) + ft_strlen(s2)) + 1);
	if (!dest)
		return (NULL);
	while (*s1)
	{
		dest[i] = *s1;
		s1++;
		i++;
	}
	while (*s2)
	{
		dest[i + j] = *s2;
		s2++;
		j++;
	}
	dest[i + j] = '\0';
	return (dest);
}

int	ft_strlen(const char *array)
{
	size_t	i;

	i = 0;
	while (array[i])
		i++;
	return (i);
}

