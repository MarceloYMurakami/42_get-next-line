/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurakam <mmurakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:48:33 by mmurakam          #+#    #+#             */
/*   Updated: 2020/02/25 22:08:55 by mmurakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		ft_validate(int fd)
{
	if (fd < 0 )
	{
		write(1, "Error: Reading File!\n", 23);
		return (0);
	}
	else return (1);
}

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

char	*ft_read_file(int fd)
{
	char *tmp;

	tmp = (char *)malloc((BUFFER_SIZE + 1)* sizeof(char));
	read(fd, &tmp, BUFFER_SIZE);
	printf("%s", tmp);
	free(tmp);
}
