/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fd.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:11:35 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/11 19:05:06 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include "../include/libft.h"

static void	check_putendl(void **state)
{
	char temp[7];

	int fd = open("test1.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putendl_fd("hello", fd);
	close(fd);
	fd = open("test1.txt", O_RDONLY);
	read(fd, temp, 6);
	close(fd);
	assert_string_equal(temp, "hello\n");
}

static void	check_putstr(void **state)
{
	char temp[7];

	int fd = open("test2.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putstr_fd("hello\n", fd);
	close(fd);
	fd = open("test2.txt", O_RDONLY);
	read(fd, temp, 6);
	close(fd);
	assert_string_equal(temp, "hello\n");
}

static void	check_putchar(void **state)
{
	char temp[2];

	int fd = open("test3.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putchar_fd('a', fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	fd = open("test3.txt", O_RDONLY);
	read(fd, temp, 2);
	close(fd);
	assert_string_equal(temp, "a\n");
}

static void	check_putnbr(void **state)
{
	char temp[5];

	int fd = open("test4.txt", O_WRONLY | O_CREAT | O_TRUNC, 0644);
	ft_putnbr_fd(2000, fd);
	ft_putchar_fd('\n', fd);
	close(fd);
	fd = open("test4.txt", O_RDONLY);
	read(fd, temp, 5);
	close(fd);
	assert_string_equal(temp, "2000\n");
}

int main(void) {
	const struct CMUnitTest tests[] = {
			cmocka_unit_test(check_putendl),
			cmocka_unit_test(check_putstr),
			cmocka_unit_test(check_putchar),
			cmocka_unit_test(check_putnbr),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}