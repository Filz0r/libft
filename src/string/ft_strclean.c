/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclean.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/19 10:50:56 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 15:23:36 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

/**
 * @brief counts how many chars we want to remove from the string
 * @param src source string we want to trim
 * @param c char we are looking for
 * @return returns 0 if src is NULL otherwise it returns the number
 * of occurrences of c in src.
 */
static int	count_garbage(char *src, char c)
{
	int	i;

	i = 0;
	while (src && *src++)
		if (*src == c)
			i++;
	return (i);
}

/**
 * @brief Cleans the given 'c' char from the src source and returns a memory
 * allocated pointer to a new string without, goes without saying that if you
 * try to remove '\\0' from the string things are not guaranteed to work.
 * @param src source null terminated char pointer.
 * @param c char we want to remove
 * @param size original size of the string
 * @return returns NULL if malloc fails or if new size is less than 1, otherwise
 * it returns a memory allocated pointer to a new 'clean' string.
 *
 * NOTE: This function does not free the memory of source because that way
 * it makes it harder to work with char ** arrays that we want to trim without
 * leaking memory ;)
 */
char	*ft_strclean(char *src, char c, size_t size)
{
	char	*res;
	int		i;
	int		k;
	int		new_size;

	if (!src)
		return (NULL);
	new_size = size - count_garbage(src, c);
	k = 0;
	i = 0;
	if (new_size <= 0)
		return (NULL);
	res = malloc(sizeof(char) * new_size + 1);
	if (!res)
		return (NULL);
	while (src[i])
	{
		if (src[i] != c)
			res[k++] = src[i];
		i++;
	}
	res[k] = '\0';
	return (res);
}
