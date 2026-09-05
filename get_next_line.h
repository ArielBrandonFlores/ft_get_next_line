/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: agiron-f <agiron-f@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/08/21 18:06:23 by agiron-f          #+#    #+#             */
/*   Updated: 2026/09/05 12:14:48 by agiron-f         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 42
# endif

# include<fcntl.h>
# include<unistd.h>
# include<stdlib.h>

char	*get_next_line(int fd);
int		search_newline(char *str);
char	*ft_strjoin(char *s1, char *s2);
int		ft_strlen(const char *array);
char	*read_and_stash(int fd, char *stash);
char	*extract_line(char *stash);
char	*clear_stash(char *stash);

#endif
