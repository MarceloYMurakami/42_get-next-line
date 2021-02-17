/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:53:05 by mmurakam          #+#    #+#             */
/*   Updated: 2021/02/17 13:22:34 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>
# include <stdio.h>

/*
int	ft_read(int fd, char *buff)
{
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	return(read(fd, buff, BUFFER_SIZE));
}
*/
//printf("Debug\n");

int get_next_line(int fd, char **line)
{
	unsigned int	i;
	int				len;
	char			*buff;
	static char 	*str;

	i = 1;
	buff = (char *)malloc((BUFFER_SIZE + 1) * sizeof(char));
	if ((str == NULL) || (str[0] == '\0'))
	{
		str = ft_calloc((BUFFER_SIZE ), sizeof(char));
		len = read(fd, str, BUFFER_SIZE);
		if (len = 0)
			return(0);
	}
	while (ft_strchr(str, '\n') == -1)
	{
		buff = ft_strdup(str);
		free(str);
		str = ft_calloc((BUFFER_SIZE * i), sizeof(char));
		str = ft_strdup(buff);
		len = read(fd, buff, BUFFER_SIZE);
		str = ft_strjoin(str, buff);
		if (len == 0)
		{
			*line = ft_strdup(str);
			free(str);
			free(buff);
			return (0);
		}
		i++;
	}
	len = ft_strlen(str);
	i = ft_strchr(str, '\n');
	*line = ft_substr(str, 0, i);
	buff = ft_substr(str, i + 1, len);
	str = buff;
	i = 1;
	return (1);
}


int main(int argc, char *argv[])
{
	int i;
	int fd;
	char **s;

	s = 0;
	s = (char **)malloc((BUFFER_SIZE + 1) * sizeof(char));
	printf("Argc: %i\n", argc);
	fd = open(argv[1], O_RDONLY);
	while (get_next_line(fd, s) != -1)
		printf("%s\n", *s);
	/*
	printf("PRIMEIRA LEITURA\n");
	i = get_next_line(fd, s);
	printf("Retorno: %i\n", i);
	printf("Linha: %s\n", *s);
	printf("FIM PRIMEIRA LEITURA\n\n");
	printf("SEGUNDA LEITURA\n");
	i = get_next_line(fd, s);
	printf("Retorno: %i\n", i);
	printf("Linha: %s\n", *s);
	printf("FIM SEGUNDA LEITURA\n\n");
	printf("TERCEIRA LEITURA\n");
	i = get_next_line(fd, s);
	printf("Retorno: %i\n", i);
	printf("Linha: %s\n", *s);
	printf("FIM TERCEIRA LEITURA\n\n");
	*/
}
