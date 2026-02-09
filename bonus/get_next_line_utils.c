/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/14 17:00:53 by abait-el          #+#    #+#             */
/*   Updated: 2025/11/23 16:21:18 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

int	gnl_strlen(const char *s)
{
	int	len;

	len = 0;
	while (*(s + len))
		len++;
	return (len);
}

char	*gnl_strchr(const char *s, int c)
{
	if (!s)
		return (NULL);
	while (*s)
	{
		if (*s == (unsigned char)c)
			return ((char *)s);
		s++;
	}
	if (*s == c)
		return ((char *)s);
	return (NULL);
}

size_t	gnl_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = gnl_strlen(src);
	if (dstsize == 0)
		return (srclen);
	i = 0;
	while (i < (dstsize - 1) && src[i])
	{
		dst[i] = src[i];
		i++;
	}
	dst[i] = '\0';
	return (srclen);
}

char	*gnl_strjoin(char *s1, int free_s1, char *s2, int free_s2)
{
	char	*res;
	size_t	s1_len;
	size_t	s2_len;

	if (!s1)
		s1 = "";
	if (!s2)
		s2 = "";
	s1_len = gnl_strlen(s1);
	s2_len = gnl_strlen(s2);
	res = (char *)malloc(s1_len + s2_len + 1);
	if (res)
	{
		gnl_strlcpy(res, s1, s1_len + s2_len + 1);
		gnl_strlcpy(res + s1_len, s2, s2_len + 1);
	}
	if (free_s1)
		free(s1);
	if (free_s2)
		free(s2);
	return (res);
}

char	*gnl_strdup(const char *s)
{
	size_t	size;
	char	*res;

	size = gnl_strlen(s) + 1;
	res = (char *)malloc(size);
	if (!res)
		return (NULL);
	gnl_strlcpy(res, s, size);
	return (res);
}
