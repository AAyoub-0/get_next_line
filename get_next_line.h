/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.h                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:33:35 by aayoub            #+#    #+#             */
/*   Updated: 2024/12/12 17:03:29 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef GET_NEXT_LINE_H
# define GET_NEXT_LINE_H

# include <fcntl.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <unistd.h>

# ifndef BUFFER_SIZE
#  define BUFFER_SIZE 10
# endif

int		ft_strchr(char *s, int c);
char	*ft_strjoin(char *buffer, char *result, char c);
size_t	ft_strlen(char *str, char c);
void	*ft_calloc(size_t nmemb, size_t size);
char	*get_next_line(int fd);

#endif
