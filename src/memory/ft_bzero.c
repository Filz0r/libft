/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/13 21:35:10 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/11 15:45:19 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>

/**
 * @brief null terminates the given void  * until length is 0 or we reach
 * the end of the contents of the pointer.
 * @param str source pointer
 * @param length length of the pointer;
 */
void	ft_bzero(void	*str, size_t length)
{
	unsigned char	*string;
	size_t 			i;

	i = 0;
	string = (unsigned char *)str;
	while (string && i++ < length)
		*string++ = '\0';
}
