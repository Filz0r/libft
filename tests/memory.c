/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   memory.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:11:10 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/11 16:35:56 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include "../include/libft.h"

static void	check_memset(void **state)
{
  	(void)state;
	char temp1[10];
	char temp2[10];

	memset(temp2, '$', 10);
	ft_memset(temp1, '$', 10);
	assert_memory_equal(temp1, temp2, 10);
}

static void	check_bzero(void **state)
{
  	(void)state;

	char temp1[10];
	char temp2[10];

	bzero(temp2, 10);
	ft_bzero(temp1, 10);
	assert_memory_equal(temp1, temp2, 10);
}

static void	check_calloc(void **state)
{
  	(void)state;

	char *temp1;
	char *temp2;

	temp1 =	calloc(1, 10);
	temp2 = ft_calloc(1, 10);
	assert_memory_equal(temp1, temp2, 10);
}

static void	check_memchr(void **state)
{
  	(void)state;

	char *temp1;
	char *temp2;
	char *temp3;
	char *temp4;

	temp1 =	calloc(1, 10);
	temp2 = ft_calloc(1, 10);
	temp3 = memchr(temp1, 0, 1);
	temp4 = ft_memchr(temp2, 0, 1);
	assert_memory_equal(temp3, temp4, 1);
}

static void	check_memcmp(void **state)
{
  	(void)state;

	char	*temp1;
	char	*temp2;
	int		test1;
	int		test2;

	temp1 =	calloc(1, 10);
	temp2 = ft_calloc(1, 10);
	test1 = memcmp(temp1, temp2, 1);
	test2 = ft_memcmp(temp1, temp2, 1);
	assert_int_equal(test1, test2);
}

static void	check_memcpy(void **state)
{
  	(void)state;

	char	*temp1 = "hello";
	char	*temp2;
	char	*temp3;

	temp2 = calloc(1, 6);
	temp3 = calloc(1, 6);
	memcpy(temp2, temp1, 6);
	ft_memcpy(temp3, temp1, 6);
	assert_memory_equal(temp2, temp3, 6);
}

static void	check_memmove(void **state)
{
  	(void)state;

	char	*temp1 = "hello";
	char	*temp2;
	char	*temp3;

	temp2 = calloc(1, 6);
	temp3 = calloc(1, 6);
	memmove(temp2, temp1, 6);
	ft_memmove(temp3, temp1, 6);
	assert_memory_equal(temp2, temp3, 6);
}

// Realloc is shitty don't use
void	check_realloc(void **state)
{
  	(void)state;

//	char	*temp1 = strdup("hello");
//	char	*temp2;
//	char	*temp3;
//
//	temp2 = realloc(temp1, 10);
//	temp3 = ft_realloc(temp1, 10);
//	assert_memory_equal(temp2, temp3, 10);
}

int main(void) {
	const struct CMUnitTest tests[] = {
			cmocka_unit_test(check_bzero),
			cmocka_unit_test(check_calloc),
			cmocka_unit_test(check_memchr),
			cmocka_unit_test(check_memcmp),
			cmocka_unit_test(check_memcpy),
			cmocka_unit_test(check_memmove),
			cmocka_unit_test(check_memset),
//			cmocka_unit_test(check_realloc),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}