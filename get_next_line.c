/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:11:14 by hualhash          #+#    #+#             */
/*   Updated: 2023/01/15 23:35:02 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

char	*read_file(int fd, char *s)
{
	char	*buff;
	int		red;

	buff = malloc((unsigned int)BUFFER_SIZE + 1);
	if (!buff)
		return (NULL);
	red = 1;
	while (red != 0)
	{
		red = read (fd, buff, BUFFER_SIZE);
		if (red == -1)
		{
			free(s);
			free(buff);
			return (NULL);
		}
		buff[red] = '\0';
		s = ft_strjoin(s, buff);
		if (check_new_line(s))
			break ;
	}
	if (buff)
		free(buff);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*s;
	char		*ptr;

	if (BUFFER_SIZE <= 0 || fd < 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	s = read_file(fd, s);
	ptr = get_line(s);
	s = ft_cut(s);
	return (ptr);
}
