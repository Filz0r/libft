/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 14:31:48 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 14:50:49 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <get_next_line.h>
#include <gnl_utils.h>

char	*ft_get_line(char *buffer)
{
	char	*line;
	int		i;

	i = 0;
	if (!ft_strlenc(buffer))
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	line = malloc(sizeof(char) * i + 1);
	if (!line)
		return (NULL);
	line[i] = '\0';
	while (i--)
		line[i] = buffer[i];
	return (line);
}

char	*ft_del_line(char *buffer)
{
	int		i;
	int		k;
	char	*result;

	i = 0;
	if (!buffer)
		return (NULL);
	while (buffer[i] && buffer[i] != '\n')
		i++;
	if (buffer[i] == '\n')
		i++;
	if (!buffer[i])
	{
		free(buffer);
		return (NULL);
	}
	result = malloc((ft_strlenc(buffer) - i + 1) * sizeof(char));
	if (!result)
		return (NULL);
	k = 0;
	while (buffer[i])
		result[k++] = buffer[i++];
	result[k] = '\0';
	free(buffer);
	return (result);
}

char	*ft_get_buffer(char *buffer, int fd)
{
	char		*temp;
	int			b;

	temp = (char *)malloc(BUFFER_SIZE + 1 * sizeof(char));
	if (!temp)
		return (NULL);
	b = 1;
	while (!(ft_strchrc(buffer, '\n')) && b != 0)
	{
		b = read(fd, temp, BUFFER_SIZE);
		if (b == -1)
		{
			free(temp);
			free(buffer);
			return (NULL);
		}
		temp[b] = '\0';
		buffer = ft_strjoinc(buffer, temp);
	}
	free(temp);
	return (buffer);
}
