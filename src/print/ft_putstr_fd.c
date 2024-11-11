/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/17 12:03:28 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 16:30:39 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_fd.h>
#include <ft_string.h>

void	ft_putstr_fd(char *str, int fd)
{
	size_t	length;

	length = ft_strlen((const char *)str);
	write(fd, str, (int)length);
}
