/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_fn.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/14 14:29:22 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/02 16:08:08 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ps_strlcpy(char *dst, const char *src, size_t dstsize)
{
	size_t	i;
	size_t	srclen;

	srclen = 0;
	while (src && src[srclen])
		srclen++;
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

static size_t	ps_countokens(const char *s, int (*is_sep)(char))
{
	size_t	count;

	count = 0;
	while (*s)
	{
		while (*s && is_sep(*s))
			s++;
		if (*s)
			count++;
		while (*s && !is_sep(*s))
			s++;
	}
	return (count);
}

static char	*ps_duptoken(const char **s, int (*is_sep)(char))
{
	char	*token;
	size_t	len;

	len = 0;
	while ((*s)[len] && !is_sep((*s)[len]))
		len++;
	token = malloc(len + 1);
	if (!token)
		return (NULL);
	ps_strlcpy(token, *s, len + 1);
	*s += len;
	return (token);
}

static void	ps_freetokens(char **words, size_t count)
{
	while (count--)
		free(words[count]);
	free(words);
}

char	**ps_split_fn(char const *s, int (*is_sep)(char))
{
	size_t	i;
	char	**res;

	if (!s || !is_sep)
		return (NULL);
	res = malloc(sizeof(char *) * (ps_countokens(s, is_sep) + 1));
	if (!res)
		return (NULL);
	i = 0;
	while (*s)
	{
		while (*s && is_sep(*s))
			s++;
		if (!*s)
			break ;
		res[i] = ps_duptoken(&s, is_sep);
		if (!res[i])
		{
			ps_freetokens(res, i);
			return (NULL);
		}
		i++;
	}
	res[i] = NULL;
	return (res);
}
