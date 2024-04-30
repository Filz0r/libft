/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/22 21:03:21 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 16:15:36 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

# include <ft_lists.h>

void	ft_lstadd_back(t_list **lst, t_list *new)
{
	t_list	*current;

	current = *lst;
	if (*lst)
	{
		while (current->next != 0)
			current = current->next;
		current->next = new;
	}
	else
		*lst = new;
}
