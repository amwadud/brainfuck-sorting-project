/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   puts.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: abait-el <abait-el@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/25 22:19:51 by abait-el          #+#    #+#             */
/*   Updated: 2026/01/01 12:35:20 by abait-el         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static size_t	ps_strlen(const char *str)
{
	size_t	length;

	length = 0;
	while (str[length])
		length++;
	return (length);
}

ssize_t	ps_puts(char *str)
{
	ssize_t	bytes_written;

	if (!str)
		return (-1);
	bytes_written = write(STDOUT_FILENO, str, ps_strlen(str));
	if (bytes_written < 0)
		return (-1);
	if (write(STDOUT_FILENO, "\n", 1) < 0)
		return (-1);
	return (bytes_written + 1);
}
