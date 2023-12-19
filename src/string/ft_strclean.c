/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:50:56 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/19 10:50:56 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_string.h"

static int	count_garbage(char *src, char c)
{
	int	i;

	i = 0;
	while (src && *src++)
		if (*src == c)
			i++;
	return (i);
}

char	*ft_strclean(char *src, char c, size_t size)
{
	char	*res;
	int		new_size;

	new_size = size - count_garbage(src, c);
	if (new_size <= 0)
		return (NULL);
	res = malloc(sizeof(char) * new_size + 1);
	if (!res)
		return (NULL);
	while (src && *src)
	{
		if (*src != c)
			*res++ = *src;
		src++;
	}
	res[new_size] = '\0';
	return (res);
}
