#include <stdarg.h>
#include <stddef.h>
#include <stdint.h>
#include <setjmp.h>
#include <cmocka.h>
#include <string.h>
#include "../include/libft.h"

// TODO: Finish writing tests

static void check_strchr(void** state)
{
	(void)state;

	const char* original = "Hello$world";

	char* temp1 = ft_strchr(original, '$');
	char* temp2 = strchr(original, '$');

	assert_string_equal(temp1, temp2);
	temp1 = ft_strchr(original, '-');
	temp2 = strchr(original, '-');
	assert_null(temp1);
	assert_null(temp2);
}

static void check_strrchr(void** state)
{
	(void)state;

	const char* original = "Hello$world";

	char* temp1 = ft_strrchr(original, '$');
	char* temp2 = strrchr(original, '$');

	assert_string_equal(temp1, temp2);
	temp1 = ft_strrchr(original, '-');
	temp2 = strrchr(original, '-');
	assert_null(temp1);
	assert_null(temp2);
}

static void check_strdup(void** state)
{
	(void)state;
	const char* original = "Hello$world";

	char* temp1 = ft_strdup(original);
	char* temp2 = strdup(original);
	assert_string_equal(temp1, original);
	assert_string_equal(temp2, original);
	assert_memory_equal(temp1, original, strlen(original));
	assert_memory_equal(temp2, original, strlen(original));
	free(temp1);
	free(temp2);
}

static void check_strjoin(void** state)
{
	(void)state;
	const char* s1 = "Hello";
	const char* s2 = " world!";

	const char* temp1 = ft_strjoin(s1, s2);
	assert_string_equal(temp1, "Hello world!");
	assert_memory_equal(temp1, "Hello world!", 12);
}

static void check_strlcat(void** state)
{
	(void)state;
	const char* s1 = " World!";
	char res1[32];
	char res2[32];

	memset(res1, 0, 32);
	memset(res2, 0,32);
	strcpy(res1, "Hello");
	strcpy(res2, "Hello");
	const int ret1 = (int)ft_strlcat(res1, s1, 13);
	const int ret2 = (int)strlcat(res2, s1, 13);
	assert_int_equal(ret1, 12);
	assert_int_equal(ret2, 12);
	assert_memory_equal(res1, "Hello World!", 13);
	assert_memory_equal(res2, "Hello World!", 13);
	assert_string_equal(res1, res2);
	assert_string_equal(res1, "Hello World!");
	assert_string_equal(res2, "Hello World!");
}

static void check_strlen(void **state)
{
	(void)state;

	assert_int_equal(ft_strlen("Hello world!"), strlen("Hello world!"));
	assert_int_equal(ft_strlen(""), strlen(""));
	assert_int_equal(ft_strlen(0), 0);
}

int main(void)
{
	const struct CMUnitTest tests[] = {
		cmocka_unit_test(check_strchr),
		cmocka_unit_test(check_strrchr),
		cmocka_unit_test(check_strdup),
		cmocka_unit_test(check_strjoin),
		cmocka_unit_test(check_strlcat),
		cmocka_unit_test(check_strlen),
	};

	return cmocka_run_group_tests(tests, NULL, NULL);
}
