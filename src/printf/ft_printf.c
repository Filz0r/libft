/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 12:12:21 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 14:53:20 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_printf.h>
#include <printf_utils.h>

int	ft_printf(const char *buffer, ...)
{
	va_list	args;
	int		k;

	k = 0;
	va_start(args, buffer);
	while (*buffer != 0)
	{
		if (*buffer == '%')
		{
			k += ft_type_parser(++buffer, args);
			buffer++;
		}
		else
			k += ft_putchar(*buffer++);
	}
	va_end(args);
	return (k);
}
