/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiron-f <agiron-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:06:23 by agiron-f          #+#    #+#             */
/*   Updated: 2026/08/23 16:50:00 by agiron-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifdef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

# include<fcntl.h>
# include<unistd.h>
# include<stdlib.h>

struct	s_list
{
	char			*str_buff;
	struct s_list	*next;
}	s_list;


char	*get_next_line(int fd);

#endif
