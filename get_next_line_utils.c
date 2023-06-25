/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:18:24 by fayan             #+#    #+#             */
/*   Updated: 2022/02/15 15:58:45 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *ana_s)
{
	int	i;

	if (!ana_s)
		return (0);
	i = 0;
	while (ana_s[i] != '\0' && ana_s[i])
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	if (!str)
		return (NULL);
	i = 0;
	while (str[i] != '\0' && str[i])
	{
		if (str[i] == (char)c)
			return ((char *)&str[i]);
		i++;
	}
	return (NULL);
}

char	*ft_strjoin(char *ana_s, char *tutucu)
{
	char	*s;
	int		i;
	int		j;

	if (!ana_s)
	{
		ana_s = malloc(sizeof(char) * 1);
		ana_s[0] = '\0';
	}
	s = malloc (sizeof(char) * (ft_strlen(ana_s) + ft_strlen(tutucu) + 1));
	if (!s)
		return (NULL);
	i = 0;
	while (ana_s[i] != '\0')
	{
		s[i] = ana_s[i];
		i++;
	}
	j = 0;
	while (tutucu[j] != '\0')
		s[i++] = tutucu[j++];
	s[i] = '\0';
	free (ana_s);
	return (s);
}
