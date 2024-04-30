/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:11:35 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/11 19:40:29 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include "../include/libft.h"

static void	check_strchr(void **state)
{
	char *original = "Hello$world";
	char	*temp1;
	char	*temp2;

	temp1 = ft_strchr(original, '$');
	temp2 = strchr(original, '$');
	assert_string_equal(temp1, temp2);
	temp1 = ft_strchr(original, '-');
	temp2 = strchr(original, '-');
	assert_null(temp1);
	assert_null(temp2);
}

static void	check_strdup(void **state)
{
	char *original = "Hello$world";
	char	*temp1;
	char	*temp2;

	temp1 = ft_strdup(original);
	temp2 = strdup(original);
	assert_string_equal(temp1, original);
	assert_string_equal(temp2, original);
	assert_memory_equal(temp1, original, strlen(original));
	assert_memory_equal(temp2, original, strlen(original));
}

static void	check_strjoin(void **state)
{
	char *s1 = "Hello";
	char *s2 = " world!";
	char	*temp1;

	temp1 = ft_strjoin(s1, s2);
	assert_string_equal(temp1, "Hello world!");
	assert_memory_equal(temp1, "Hello world!", 12);
}

static void	check_strlcat(void **state)
{
	char *s1 = "Hello";
	char	res1[12]="hello";
	char	res2[12]="hello";
	int		ret1;
	int		ret2;

	ret1 = (int)ft_strlcat(res1, s1, 10);
	ret2 = (int)strlcat(res2, s1, 10);
	assert_int_equal(ret1, 10);
	assert_int_equal(ret2, 10);
	assert_memory_equal(res1, s1, 10);
	assert_memory_equal(res2, s1, 10);
	assert_string_equal(res1, res2);
	assert_string_equal(res1, s1);
}

int main(void) {
	const struct CMUnitTest tests[] = {
			cmocka_unit_test(check_strchr),
			cmocka_unit_test(check_strdup),
			cmocka_unit_test(check_strjoin),
			cmocka_unit_test(check_strlcat),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}