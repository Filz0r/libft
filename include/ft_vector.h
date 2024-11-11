/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_vector.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/11/11 00:46:44 by fparreir          #+#    #+#             */
/*   Updated: 2024/11/11 14:13:36 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


// SOURCE: https://aticleworld.com/implement-vector-in-c/
#ifndef FT_VECTOR_H
#define FT_VECTOR_H

# define VECTOR_INIT_SIZE	6
# define UNDEFINE	-1
# define SUCCESS	0


#include <stdlib.h>

typedef struct s_vector t_vector;
typedef struct s_vector_data t_vector_data;

struct s_vector_data {
	void **array;
	size_t  length;
	size_t  capacity;
};

struct s_vector {
	t_vector_data vector;

    size_t	(*length)(void);
	int		(*resize)(t_vector*, size_t);
    int		(*push_back)(t_vector *,void *);
    int		(*clear)(t_vector *);
	int		(*remove)(t_vector *vec, int index);
    void	*(*find)(t_vector *, int);
    int		(*set)(t_vector *, int, void *);
};


t_vector *ft_create_vector(const size_t initial_size);
void *ft_clear_vector(t_vector *vec);
void *ft_add_to_vector(void *ptr);
void ft_remove_from_vector(void *ptr);

#endif //FT_VECTOR_H
