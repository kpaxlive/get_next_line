/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fayan <42istanbul.com.tr>                  +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/02/15 14:18:12 by fayan             #+#    #+#             */
/*   Updated: 2022/02/15 17:54:53 by fayan            ###   ########.tr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <stdio.h>
# include <fcntl.h>
# include <sys/types.h>
# include <sys/uio.h>
# include <unistd.h>
# include <stdlib.h>

char	*get_next_line(int fd);
char	*get(int fd, char *ana_s);
char	*linekadar(char *ana_s);
size_t	ft_strlen(char *ana_s);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *ana_s, char *tutucu);
char	*yenisatir(char *ana_s);
#endif
