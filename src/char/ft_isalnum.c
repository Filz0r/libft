/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 21:04:48 by fparreir          #+#    #+#             */
/*   Updated: 2023/05/13 14:32:14 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../includes/libft.h"

int	ft_isalnum(int c)
{
	if ((c >= 48 && c <= 57)
		|| (c >= 97 && c <= 122)
		|| (c >= 65 && c <= 90))
		return (1);
	return (0);
}