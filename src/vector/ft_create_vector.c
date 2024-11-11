/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_create_vector.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:00:19 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/11 13:58:04 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_memory.h>
#include <ft_vector.h>
#include <ft_vector_private.h>

static void init_vector_methods(t_vector *vec)
{
	vec->find = get_vector_item;
	vec->set = set_vector_item;
	vec->resize = resize_vector;
	vec->clear = clear_vector;
	vec->remove = remove_vector_element;
	vec->push_back = vector_push_back;
}

t_vector *ft_vector_init(void)
{
	t_vector *res;

	res = ft_calloc(1, sizeof(t_vector));
	if (!res)
		return NULL;
	init_vector_methods(res);
	res->vector.capacity = VECTOR_INIT_SIZE;
	res->vector.length = 0;
	res->vector.array = ft_calloc(VECTOR_INIT_SIZE, sizeof(void *));
	if (!res->vector.array)
	{
		free(res);
		return NULL;
	}
	return res;
}
