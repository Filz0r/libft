/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf_utils.h                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:52:03 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 14:55:48 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PRINTF_UTILS_H
# define PRINTF_UTILS_H

# include <stdarg.h>
# include <unistd.h>

# define HEX_LOWER "0123456789abcdef"
# define HEX_UPPER "0123456789ABCDEF"

int		ft_type_parser(const char *buffer, va_list(args));
int		ft_handle_pointer(int hex, unsigned long int nb);
int		ft_putstr(char *str);
int		ft_putchar(int c);
int		ft_putnbr(int c);
int		ft_putu(unsigned int nb);
int		ft_puthex(int hex, unsigned long int nb);

#endif //PRINTF_UTILS_H
