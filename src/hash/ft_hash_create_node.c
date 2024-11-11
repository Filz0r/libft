/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_hash_create_node.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/01/13 18:48:58 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/11 14:10:11 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_hash.h>
# include <ft_string.h>

t_hash_node	*ft_hash_create_node(const char *key, void *value)
{
	t_hash_node	*new;

	new = malloc(sizeof(t_hash_node));
	if (!new)
		return (NULL);
	if (key)
		new->key = ft_strdup(key);
	else
		new->key = NULL;
	new->value = value;
	new->_type = POINTER;
	new->source = NULL;
	new->next = NULL;
	return (new);
}
