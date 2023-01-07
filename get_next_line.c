/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:11:14 by hualhash          #+#    #+#             */
/*   Updated: 2023/01/07 19:22:51 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *s)
{
	char	buff[BUFFER_SIZE + 1];
	int		red;

	red = 1;
	while (red != 0)
	{
		red = read (fd, buff, BUFFER_SIZE);
		if (red == -1)
		{
			free(s);
			return (NULL);
		}
		buff[red] = '\0';
		s = ft_strjoin(s, buff);
		if (check_new_line(s))
			break ;
	}
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > 2147483647)
		return (NULL);
	// write(1, "fuck", 4);
	// printf("s= %s\n", s);
	s = read_file(fd, s);
	ptr = get_line(s);
	s = ft_cut(s);
	return (ptr);
}
