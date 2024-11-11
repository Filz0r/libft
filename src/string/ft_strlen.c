/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:07:04 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 15:24:15 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

/**
 * @brief counts how many chars exist in a char *
 * @param str source string we want to count
 * @return 0 if str is null otherwise returns the length of the string.
 */
size_t	ft_strlen(const char *str)
{
	size_t	i;

	i = 0;
	while (str && *str++)
		i++;
	return (i);
}
