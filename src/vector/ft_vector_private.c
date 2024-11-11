/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_private.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 01:10:22 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/11 14:01:12 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_vector.h>
#include <ft_vector_private.h>

int resize_vector(t_vector* vec, size_t capacity)
{
	int status = UNDEFINE;
	if (vec)
	{
		void** data = realloc(vec->vector.array, (sizeof(void*) * capacity));
		if (!data)
		{
			free(vec->vector.array);
			free(vec);
			return status;
		}
		vec->vector.array = data;
		vec->vector.capacity = capacity;
		status = SUCCESS;
	}
	return status;
}

int vector_push_back(t_vector* vec, void* data)
{
	int status = UNDEFINE;
	if (vec)
	{
		if (vec->vector.length == vec->vector.capacity)
		{
			status = vec->resize(vec, (vec->vector.capacity * 2));
			if (status != UNDEFINE)
				vec->vector.array[vec->vector.length++] = data;
			else
			{
				vec->vector.array[vec->vector.length++] = data;
				status = SUCCESS;
			}
		}
	}
	return status;
}

void* get_vector_item(t_vector* vec, int index)
{
	void* data = NULL;
	if (vec)
	{
		if (index >= 0 && index < (int)vec->vector.length)
		{
			data = vec->vector.array[index];
		}
	}
	return data;
}

int set_vector_item(t_vector* vec, int index, void* data)
{
	int status = UNDEFINE;
	if (vec)
	{
		if (index >= 0 && index < (int)vec->vector.length)
		{
			vec->vector.array[index] = data;
			status = SUCCESS;
		}
	}
	return status;
}

int clear_vector(t_vector* vec)
{
	int status = UNDEFINE;
	if (vec)
	{
		for (size_t i = 0; i < vec->vector.length; i++)
			free(vec->vector.array[i]);
		free(vec->vector.array);
		free(vec);
		status = SUCCESS;
	}
	return status;
}

int remove_vector_element(t_vector* vec, int index)
{
	int status = UNDEFINE;
	int i = 0;
	if (vec)
	{
		if (index < 0 || index > (int)vec->vector.length)
			return status;

		vec->vector.array[index] = NULL;

		for (i = index; i < (int)vec->vector.length - 1; i++)
		{
			vec->vector.array[i] = vec->vector.array[i + 1];
			vec->vector.array[i + 1] = NULL;
		}
		vec->vector.capacity--;
		status = SUCCESS;
	}
	return status;
}
