/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:18:56 by fayan             #+#    #+#             */
/*   Updated: 2022/02/15 17:46:41 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get(int fd, char *ana_s)
{
	char	*tutucu;
	int		okunanbyte;

	tutucu = malloc(sizeof(char) * (BUFFER_SIZE + 1));
	if (!tutucu)
		return (NULL);
	okunanbyte = 1;
	while (okunanbyte != 0 && !ft_strchr(ana_s, '\n'))
	{
		okunanbyte = read(fd, tutucu, BUFFER_SIZE);
		if (okunanbyte == -1)
		{
			free (tutucu);
			return (NULL);
		}
		tutucu[okunanbyte] = '\0';
		ana_s = ft_strjoin(ana_s, tutucu);
	}
	free (tutucu);
	return (ana_s);
}

char	*linekadar(char *ana_s)
{
	char	*s;
	int		i;

	i = 0;
	if (!ana_s[i])
		return (NULL);
	while (ana_s[i] != '\n' && ana_s[i] != '\0')
		i++;
	s = malloc(sizeof(char) * (i + 2));
	if (!s)
		return (NULL);
	i = 0;
	while (ana_s[i] != '\n' && ana_s[i])
	{
		s[i] = ana_s[i];
		i++;
	}
	if (ana_s[i] == '\n')
	{
		s[i] = '\n';
		i++;
	}
	s[i] = '\0';
	return (s);
}

char	*yenisatir(char *ana_s)
{
	int		i;
	int		j;
	char	*s;

	i = 0;
	while (ana_s[i] != '\0' && ana_s[i] != '\n')
		i++;
	if (!ana_s[i])
	{
		free (ana_s);
		return (NULL);
	}
	s = malloc(sizeof(char) * (ft_strlen(ana_s) - i + 1));
	if (!s)
		return (NULL);
	if (ana_s[i] == '\n')
		i++;
	else
		return (NULL);
	j = 0;
	while (ana_s[i] != '\0' && ana_s[i])
		s[j++] = ana_s[i++];
	s[j] = '\0';
	free (ana_s);
	return (s);
}

char	*get_next_line(int fd)
{
	static char	*ana_s[4096];
	char		*line;

	if (BUFFER_SIZE <= 0 || fd < 0)
		return (NULL);
	ana_s[fd] = get(fd, ana_s[fd]);
	if (!ana_s[fd])
		return (NULL);
	line = linekadar(ana_s[fd]);
	ana_s[fd] = yenisatir(ana_s[fd]);
	return (line);
}
