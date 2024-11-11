/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/24 16:37:37 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 12:57:53 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <gnl_utils.h>
#include <get_next_line.h>

char	*get_next_line(int fd)
{
	static char	*buffer;
	char		*line;

	if (fd < 0 || BUFFER_SIZE <= 0)
		return (NULL);
	buffer = ft_get_buffer(buffer, fd);
	if (!buffer)
		return (NULL);
	line = ft_get_line(buffer);
	buffer = ft_del_line(buffer);
	return (line);
}
