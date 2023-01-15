/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: hualhash <hualhash@student.42abudhabi.a    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/04 20:11:25 by hualhash          #+#    #+#             */
/*   Updated: 2023/01/16 00:43:52 by hualhash         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(const char *s)
{
	size_t	i;

	i = 0;
	while (s[i] != '\0')
		i++;
	return (i);
}

int	check_new_line(char *s)
{
	int	i;

	i = 0;
	while (s[i])
	{
		if (s[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char			*str;
	size_t			i;
	size_t			j;

	if (!s1)
	{
		s1 = (char *)malloc(1 * sizeof(char));
		s1[0] = '\0';
	}
	str = malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) +1));
	if (!str)
		return (NULL);
	i = 0;
	j = 0;
	while (s1[i] != '\0')
		str[j++] = s1[i++];
	i = 0;
	while (s2[i] != '\0')
		str[j++] = s2[i++];
	str[j] = '\0';
	free (s1);
	return (str);
}

char	*get_line(char *s)
{
	char	*ptr;
	int		i;

	i = 0;
	if (!s || s[i] == 0)
		return (0);
	ptr = malloc(sizeof(char) * ft_strlen(s) + 1);
	if (!ptr)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	if (s[i] == '\n')
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_cut(char *s)
{
	char	*ptr;
	int		i;
	int		j;

	i = 0;
	if (!s)
		return (NULL);
	while (s[i] && s[i] != '\n')
		i++;
	if (s[i] == 0)
	{
		free(s);
		return (NULL);
	}
	i++;
	ptr = malloc((ft_strlen(s) - i + 1) * sizeof(char));
	if (!ptr)
		return (NULL);
	j = 0;
	while (s[i])
		ptr[j++] = s[i++];
	ptr[j] = '\0';
	free(s);
	return (ptr);
}
