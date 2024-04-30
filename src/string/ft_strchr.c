/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/12 17:17:46 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 15:23:26 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

/**
 * @brief returns a pointer of str where c happens.
 * @param str source we are searching
 * @param c char we are looking for
 * @return returns NULL if c isn't found otherwise returns a pointer to the
 * first occurrence of c.
 */
char	*ft_strchr(const char *str, int c)
{
	while (*str && *str != (char)c)
		str++;
	if (*str == (char)c)
		return ((char *)str);
	return (0);
}
