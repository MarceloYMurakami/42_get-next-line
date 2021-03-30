/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:53:05 by mmurakam          #+#    #+#             */
/*   Updated: 2021/02/17 17:39:35 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>
# include <fcntl.h>
# include <sys/stat.h>

int get_next_line(int fd, char **line)
{
	unsigned int	i;
	int				len;
	char			*buff;
	static char 	*str;

	i = 1;
	buff = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
	if ((str == NULL) || (str[0] == '\0'))
	{
		str = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		len = read(fd, str, BUFFER_SIZE);
		if (len == 0)
			return(0);
		if (len == -1)
			return(-1);
	}
	while (ft_strchr(str, 10) == -1)
	{
		buff = ft_strdup(str);
		free(str);
		str = ft_calloc((BUFFER_SIZE * i), sizeof(char));
		str = ft_strdup(buff);
		len = read(fd, buff, BUFFER_SIZE);
		if (len == 0)
		{
			*line = ft_strdup(str);
			free(str);
			free(buff);
			return (0);
		}
		buff[len] = '\0';
		str = ft_strjoin(str, buff);
		free(buff);
		i++;
	}
	len = ft_strlen(str);
	i = ft_strchr(str, 10);
	*line = ft_substr(str, 0, i);
	buff = ft_substr(str, i + 1, len);
	str = buff;
	i = 1;
	return (1);
}
