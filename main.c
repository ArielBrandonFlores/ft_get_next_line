/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiron-f <agiron-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 19:08:59 by agiron-f          #+#    #+#             */
/*   Updated: 2026/08/21 19:11:28 by agiron-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	main(void)
{
	int		fd;
	char	*buffer;
	int		bytes;

	fd = open("arquivo.txt", O_RDONLY);

	if (!fd)
		return ("NULL");
	return (0);
}
