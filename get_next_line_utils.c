/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiron-f <agiron-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:06:20 by agiron-f          #+#    #+#             */
/*   Updated: 2026/09/07 10:49:31 by agiron-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	search_newline(char *str)
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

	dest = malloc(ft_strlen(s1) + ft_strlen(s2) + 1);
	if (!dest)
	{
		free(s1);
		return (NULL);
	}
	i = 0;
	while (s1 && s1[i])
	{
		dest[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2 && s2[j])
		dest[i++] = s2[j++];
	dest[i] = '\0';
	free(s1);
	return (dest);
}

int	ft_strlen(const char *array)
{
	size_t	i;

	if (!array)
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}

char	*free_and_null(char *s1, char *s2)
{
	if (s1)
		free(s1);
	if (s2)
		free(s2);
	return (NULL);
}
