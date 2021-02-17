/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: marvin <marvin@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2020/02/25 16:48:33 by mmurakam          #+#    #+#             */
/*   Updated: 2021/02/17 13:11:06 by marvin           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
# include <stdio.h>

void	*ft_calloc(size_t nmemb, size_t size)
{
	void				*ptr;
	unsigned int		i;

	i = 0;
	if (!(ptr = malloc((sizeof(char) * (nmemb * size)))))
		return (NULL);
	while (i < (nmemb * size))
	{
		((char *)ptr)[i] = 0;
		i++;
	}
	return (ptr);
}

size_t	ft_strlen(const char *str)
{
	int count;

	count = 0;
	while (str[count])
		count++;
	return (count);
}

int	ft_strchr(const char *str, int c)
{
	unsigned char *pstr;
	int i;

	i = 0;
	pstr = (unsigned char *)str;
	while (pstr[i] != '\0')
	{
		if (pstr[i] == c)
			return (i);
		i++;
	}
	if (pstr[i] == c)
		return (i);
	return (-1);
}

char	*ft_strdup(const char *s)
{
	size_t	n;
	char	*ptr;
	int		i;

	i = 0;
	n = ft_strlen((char *)s);
	if (!(ptr = (char *)malloc((sizeof(char) * n + 1))))
		return (NULL);
	while (n-- > 0)
	{
		ptr[i] = s[i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}

char	*ft_strjoin(char const *s1, char const *s2)
{
	char			*str;
	unsigned int	i;
	unsigned int	len;

	if (s1 == NULL || s2 == NULL)
		return (NULL);
	i = 0;
	len = ft_strlen(s1);
	if (!(str = malloc((len + ft_strlen(s2) + 1) * sizeof(char))))
		return (NULL);
	while (len-- > 0)
	{
		str[i] = *s1;
		i++;
		s1++;
	}
	len = ft_strlen(s2);
	while (len-- > 0)
	{
		str[i] = *s2;
		s2++;
		i++;
	}
	str[i] = '\0';
	return (str);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char				*sub;
	unsigned int		i;

	i = 0;
	if (s == NULL)
		return (NULL);
	if (!(sub = malloc((len + 1) * sizeof(char))))
		return (NULL);
	if (start > ft_strlen(s))
	{
		sub[0] = '\0';
		return (sub);
	}
	while (i < len && s[i + start] != '\0')
	{
		sub[i] = s[i + start];
		i++;
	}
	sub[i] = '\0';
	return (sub);
}
