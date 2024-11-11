/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/20 17:35:21 by fparreir          #+#    #+#             */
/*   Updated: 2023/12/19 21:52:29 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <ft_string.h>

/**
 * @brief finds the length of a split starting from i.
 * @param s the source string
 * @param c the char we are looking
 * @param i the index position we are at
 * @return returns the length of the word, starting from i.
 */
static int	ft_get_word_length(const char *s, char c, int i)
{
	while (s[i] != c && s[i])
		i++;
	return (i);
}

/**
 * @brief counts how many words are inside str
 * @param str source string we are trying to split
 * @param c char we want to split at
 * @return the number of words inside str delimited by c.
 */
static int	ft_count_words(char const *str, char c)
{
	int	counter;

	counter = 0;
	while (*str)
	{
		while (*str == c)
			str++;
		if (*str != '\0' && *str)
			counter++;
		while (*str && *str != c)
			str++;
	}
	return (counter);
}

/**
 * @brief Recursive function that tries to read the string until it finds the
 * c char, if its able to it creates that string and returns it, otherwise it
 * returns the memory allocated char *.
 * @param str the source string we are trying to split
 * @param c the char we are splitting with.
 * @param pos a pointer to the position that was last split at.
 * @return returns NULL if malloc fails otherwise it returns a char * containing
 * a 'split' of src without the c char.
 */
static char	*ft_get_word(const char *str, char c, int *pos)
{
	int		k;
	int		i;
	int		word_length;
	char	*buffer;

	k = 0;
	i = 0;
	if (*pos > 0)
		i = *pos;
	word_length = ft_get_word_length(str, c, i) - i;
	if (word_length > 0)
	{
		buffer = (char *)malloc((word_length + 1) * sizeof(char));
		if (!buffer)
			return (0);
		while (i < *pos + word_length)
			buffer[k++] = str[i++];
		buffer[k] = 0;
		*pos = i;
	}
	else
		return (ft_get_word(str, c, ((*pos)++, pos)));
	return (buffer);
}

/**
 * @brief Splits the given s source in any occurrence of the c char and returns
 * an char ** array containing all the 'splits' of the original string.
 * @param s source string that we want to split.
 * @param c  char that we want to delimit our individual char * with
 * @return returns NULL is memory allocation fails otherwise it returns an
 * allocated char ** array.
 */
char	**ft_split(const char *s, char c)
{
	int		i;
	int		k;
	int		words;
	char	*word;
	char	**buffer;

	i = 0;
	k = 0;
	words = ft_count_words(s, c);
	buffer = (char **)malloc((words + 1) * sizeof(char *));
	if (!buffer)
		return (0);
	while (i < words)
	{
		if (k <= (int)ft_strlen(s))
		{
			word = ft_get_word(s, c, &k);
			buffer[i] = word;
		}
		i++;
	}
	buffer[i] = 0;
	return (buffer);
}
