/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   printf.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:11:18 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/11 15:40:27 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include "../include/libft.h"

// TODO: Finish writing tests
static void null_test_success(void **state) {
	(void) state;
}

static void null_test_fail(void **state) {
	assert_non_null(state[0]);
}

static void	check_memset(void **state)
{
	char temp1[10];
	char temp2[10];
	memset(temp2, '$', 10);
	ft_memset(temp1, '$', 10);
	assert_memory_equal(temp1, temp2, 10);
}

int main(void) {
	const struct CMUnitTest tests[] = {
			cmocka_unit_test(null_test_success),
			cmocka_unit_test(check_memset),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}