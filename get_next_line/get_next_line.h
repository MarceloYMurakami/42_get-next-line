/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:47:53 by mmurakam          #+#    #+#             */
/*   Updated: 2021/02/17 16:35:18 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <unistd.h>
# include <stdlib.h>
# include <limits.h>
# include <fcntl.h>

# ifndef BUFFER_SIZE
# 	define BUFFER_SIZE 2
# endif
# define LBREAK '\n' | 'LF'

int					ft_validate(int fd);
char				*ft_clear_line(char	*line);
char				*ft_strjoin(char const *s1, char const *s2);
char				*ft_substr(char const *s, unsigned int start, size_t len);
int					ft_strchr(const char *str, int c);
size_t				ft_strlen(const char *str);
void				*ft_calloc(size_t nmemb, size_t size);
char				*ft_strdup(const char *s);

#endif
