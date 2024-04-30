/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:01:15 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 15:23:54 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

/**
 * @brief Joins two strings together
 * @param s1 source string
 * @param s2 second source string
 * @return null if malloc fails otherwise returns a pointer to an string
 * containing the contents of both s1 and s2.
 */
char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buffer;
	size_t	total_len;
	size_t	i;

	i = 0;
	total_len = ft_strlen(s1) + ft_strlen(s2) + 1;
	buffer = (char *)malloc(total_len * sizeof(char));
	if (!buffer)
		return (0);
	while (*s1)
		buffer[i++] = *s1++;
	while (*s2)
		buffer[i++] = *s2++;
	buffer[i] = 0;
	return (buffer);
}
