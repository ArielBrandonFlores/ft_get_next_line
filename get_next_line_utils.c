/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiron-f <agiron-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:06:20 by agiron-f          #+#    #+#             */
/*   Updated: 2026/09/05 15:55:06 by agiron-f         ###   ########.fr       */
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
		free(s1); /* Libera s1 se malloc falhar para evitar leak */
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

	if (!array) /* Protecao: retorna 0 caso array seja NULL */
		return (0);
	i = 0;
	while (array[i])
		i++;
	return (i);
}
