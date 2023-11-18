/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_realloc.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/18 13:01:32 by fparreir          #+#    #+#             */
/*   Updated: 2023/11/18 13:01:32 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "ft_memory.h"

void    *ft_realloc(void *ptr, size_t size)
{
    void    *result;
    size_t  cp_size;
    size_t  i;

    if (size == 0)
    {
        free(ptr);
        return (NULL);
    }
    if (ptr == NULL)
        return (malloc(size));
    result = malloc(size);
    if (!result)
        return (NULL);
    cp_size = (size_t)-1;
    if (size < (size_t)-1)
        cp_size = size;
    i = -1;
    while (++i < cp_size)
        ((char *)result)[i] = ((char *)ptr)[i];

    free(ptr);
    return (result);
}