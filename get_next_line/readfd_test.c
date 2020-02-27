/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readfd_test.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurakam <mmurakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/22 22:29:49 by mmurakam          #+#    #+#             */
/*   Updated: 2020/02/25 22:13:41 by mmurakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <unistd.h>
#include <stdlib.h>
#include <fcntl.h>
#include <stdio.h>
#ifndef BUFFER_SIZE
# define BUFFER_SIZE 1024
#endif

/*
char	*ft_clear_line(char	*line)
{
	int i;

	i = 0;
	while (line[i] != '\0')
	{
		line[i] = '\0';
		i++;
	}
	return (line);
}

void	ft_print_line(int fd, char *line)
{
	int	readbyte;
	int	i;
	char c;

	i = 0;
	while ((readbyte = read(fd, &c, 1)) != 0)
	{
		line[i] = c;
		i++;
		if (c == 0 || c == '\n')
		{
			printf("%s", line);
			i = 0;
			ft_clear_line(line);
		}
	}
}
*/
int	ft_read_file(int fd)
{
	char *tmp;

	tmp = (char *)malloc((BUFFER_SIZE + 1)* sizeof(char));
	read(fd, tmp, BUFFER_SIZE);
	printf("%s", tmp);
	free(tmp);
	return (1);
}

int	main(int argc, char	*argv[])
{
	int		fd;

	if (argc <= 1)
	{
		write(1, "Error: Write file path!\n", 23);
		return (0);
	}
	fd = open(argv[1], O_RDONLY);
	if (fd < 0 )
	{
		write(1, "Error: Reading File!\n",23);
		return (0);
	}
	printf("File Descriptor: %i\n", fd);
	ft_read_file(fd);
	return (0);
}
