/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 11:29:03 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 15:23:40 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

/**
 * @brief duplicates the given string
 * @param str source string
 * @return returns NULL if malloc fails otherwise returns a allocated pointer
 * to a null terminated copy of its parameter.
 */
char	*ft_strdup(const char *str)
{
	char	*buffer;
	int		i;

	i = 0;
	buffer = malloc((ft_strlen(str) + 1) * sizeof(char));
	if (!buffer)
		return (0);
	while (str[i])
	{
		buffer[i] = str[i];
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
