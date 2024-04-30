/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gnl_utils.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: fparreir <fparreir@student.42lisboa.com>   +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/03/05 12:38:12 by fparreir          #+#    #+#             */
/*   Updated: 2024/03/05 13:08:58 by fparreir         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GNL_UTILS_H
# define GNL_UTILS_H

# include <stdlib.h>
# include <unistd.h>

int		ft_strlenc(char *str);
char	*ft_strjoinc(char *s1, char *s2);
char	*ft_get_line(char *buffer);
char	*ft_del_line(char *buffer);
char	*ft_strchrc(char *str, char c);
char	*ft_get_buffer(char *buffer, int fd);

#endif //UTILS_H
