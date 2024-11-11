/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector_private.h                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:49:14 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/11 01:10:01 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_VECTOR_PRIVATE_H
#define FT_VECTOR_PRIVATE_H

#include <stdlib.h>

typedef struct s_vector_data t_vector_data;
typedef struct s_vector  t_vector;



int		resize_vector(t_vector *vec, size_t capacity);
int		vector_push_back(t_vector *vec, void *data);
void	*get_vector_item(t_vector *vec, int index);
int		set_vector_item(t_vector *vec, int index, void *data);
int		clear_vector(t_vector *vec);
int		remove_vector_element(t_vector *vec, int index);


#endif //FT_VECTOR_PRIVATE_H
