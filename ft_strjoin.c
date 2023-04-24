/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 15:01:15 by fparreir          #+#    #+#             */
/*   Updated: 2023/04/24 15:50:59 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(const char *s1, const char *s2)
{
	char	*buffer;
	size_t	total_len;
	size_t	i;
	size_t	len1;

	i = 0;
	len1 = ft_strlen(s1);
	total_len = len1 + ft_strlen(s2) + 1;
	buffer = (char *)malloc(total_len * sizeof(char));
	if (!buffer)
		return (0);
	while (i < len1)
		buffer[i++] = *s1++;
	while (i <= total_len)
		buffer[i++] = *s2++;
	buffer[i] = '\0';
	return (buffer);
}
