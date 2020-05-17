/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mmurakam <mmurakam@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:53:05 by mmurakam          #+#    #+#             */
/*   Updated: 2020/05/17 20:34:07 by mmurakam         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int		get_next_line(int fd, char **line)
{
	int			i;
	char		*tmp;
	char		*queue;
	static char	*line;

	if (fd < 0 || BUFFER_SIZE < 1)
		return (-1);


}
