/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   split_fn.c                                         */
/*                                                    */
/*   By: abait-el <abait-el@student.1337.ma>        */
/*                                                */
/*   Created: 2025/12/14 14:29:22 by abait-el          */
/*   Updated: 2026/03/17 00:00:00 by abait-el         */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file split_fn.c
 * @brief String splitting utility functions.
 * 
 * Provides a custom implementation of string splitting functionality,
 * similar to ft_split in the 42 library, but with a custom separator
 * function pointer for flexibility.
 */

#include <stdlib.h>

/**
 * @brief Safely copies a string with a size limit.
 * 
 * A simplified version of strlcpy that ensures null-termination
 * and doesn't read beyond dstsize bytes from src.
 * 
 * @param dst      Destination buffer
 * @param src      Source string to copy
 * @param dstsize  Size of destination buffer
 * @return Length of the source string
 */
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

/**
 * @brief Counts the number of tokens in a string separated by a separator.
 * 
 * @param s        String to count tokens in
 * @param is_sep   Function pointer that determines if a character is a separator
 * @return Number of tokens found
 */
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

/**
 * @brief Duplicates a single token from the string.
 * 
 * Advances the string pointer past the duplicated token.
 * 
 * @param s        Pointer to the string (will be advanced)
 * @param is_sep   Function pointer that determines if a character is a separator
 * @return Newly allocated copy of the token, or NULL on failure
 */
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

/**
 * @brief Frees an array of token strings.
 * 
 * Helper function to clean up allocated tokens on error.
 * 
 * @param words Array of string pointers to free
 * @param count Number of strings in the array
 */
static void	ps_freetokens(char **words, size_t count)
{
	while (count--)
		free(words[count]);
	free(words);
}

/**
 * @brief Splits a string into an array of tokens based on a separator function.
 * 
 * This function takes a string and a separator function, then splits
 * the string into individual tokens separated by characters that
 * satisfy the separator function.
 * 
 * Example: split_fn("hello world", is_space) returns ["hello", "world"]
 * 
 * @param s        String to split
 * @param is_sep   Function pointer that returns non-zero for separator characters
 * @return Array of strings (NULL-terminated), or NULL on failure
 */
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
