/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fsplit.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/06 16:18:28 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/06 16:19:13 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_memory.h"

void	ft_fsplit(char **arr)
{
	int	i;

	i = 0;
	while (arr[i] != 0)
		free(arr[i++]);
	free(arr);
}
