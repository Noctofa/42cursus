/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sgaspard <sgaspard@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/02/27 14:16:32 by sgaspard          #+#    #+#             */
/*   Updated: 2023/03/22 16:00:12 by sgaspard         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

static char	*read_fd(int fd, char *s)
{
	char	buf[BUFFER_SIZE + 1];
	int		i;

	i = 1;
	while (i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
		{
			free(s);
			return (NULL);
		}
		buf[i] = '\0';
		s = ft_strjoin(s, buf);
		if (ft_strchr(buf, '\n'))
			break ;
	}
	return (s);
}

static char	*s_to_line(const char *s)
{
	char	*tmp;
	int		i;

	i = 0;
	if (!s[0])
		return (NULL);
	while (s[i] && s[i] != '\n')
		++i;
	tmp = malloc(i + 2);
	if (!tmp)
		return (NULL);
	i = 0;
	while (s[i] && s[i] != '\n')
	{
		tmp[i] = s[i];
		++i;
	}
	if (s[i] == '\n')
	{
		tmp[i] = s[i];
		++i;
	}
	tmp[i] = '\0';
	return (tmp);
}

static char	*clean_s(char *s)
{
	char	*tmp;
	int		i;
	int		j;

	i = 0;
	while (s[i] && s[i] != '\n')
		++i;
	if (!s[i])
	{
		free(s);
		return (NULL);
	}
	tmp = malloc((ft_strlen(s) - i + 1));
	if (!tmp)
		return (NULL);
	++i;
	j = 0;
	while (s[i])
		tmp[j++] = s[i++];
	tmp[j] = '\0';
	free(s);
	return (tmp);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	*s;

	if (fd < 0 || BUFFER_SIZE <= 0 || BUFFER_SIZE > INT_MAX)
		return (NULL);
	s = read_fd(fd, s);
	if (!s)
		return (NULL);
	line = s_to_line(s);
	s = clean_s(s);
	return (line);
}
