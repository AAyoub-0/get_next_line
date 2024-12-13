/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_bonus.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:33:30 by aayoub            #+#    #+#             */
/*   Updated: 2024/12/13 14:35:23 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

char	*get_left(char *buffer, size_t size)
{
	char	*temp;
	size_t	j;

	temp = ft_calloc((BUFFER_SIZE + ft_strchr(buffer + size, '\n') + 1),
			sizeof(char));
	if (!temp)
	{
		free(buffer);
		buffer = NULL;
		return (NULL);
	}
	j = 0;
	while (buffer[size + j])
	{
		temp[j] = buffer[size + j];
		j++;
	}
	if (buffer[size + j] == '\n')
		temp[j++] = '\n';
	buffer[j] = '\0';
	free(buffer);
	return (temp);
}

char	*read_line(int fd, char *buffer, char *result, int *nb_read)
{
	while (*nb_read != 0)
	{
		*nb_read = read(fd, buffer, BUFFER_SIZE);
		if (*nb_read == -1)
		{
			free(result);
			return (NULL);
		}
		buffer[*nb_read] = '\0';
		result = ft_strjoin(buffer, result, '\n');
		if (ft_strchr(result, '\n'))
			return (result);
	}
	return (result);
}

char	*read_file(int fd, char *buffer)
{
	int		nb_read;
	char	*result;

	nb_read = -1;
	result = NULL;
	if (buffer && buffer[0] != '\0')
		result = ft_strjoin(buffer, result, '\n');
	if (ft_strchr(result, '\n'))
		return (result);
	result = read_line(fd, buffer, result, &nb_read);
	if (!result)
		return (NULL);
	if (result && result[0] != '\0' && nb_read == 0)
		return (result);
	if (buffer && buffer[0] == '\0' && nb_read == 0)
	{
		free(result);
		return (NULL);
	}
	return (result);
}

char	*get_next_line(int fd)
{
	char		*line;
	static char	**buffer;
	int	i;
		
	i = 0;
	if (fd < 0 || BUFFER_SIZE <= 0 || fd >= MAX_FD)
	{
		return (NULL);
	}
	if (!buffer)
	{
		buffer = ft_calloc(MAX_FD, sizeof(char *));
		if (!buffer)
			return (NULL);
	}
        if (!buffer[fd])
        {
		buffer[fd] = ft_calloc(BUFFER_SIZE + 1, sizeof(char));
		if (!buffer[fd])
			return (NULL);
        }
	line = read_file(fd, buffer[fd]);
	if (line == NULL)
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
		return (line);
	}
	buffer[fd] = get_left(buffer[fd], ft_strlen(buffer[fd], '\n'));
	if (!buffer[fd][0])
	{
		free(buffer[fd]);
		buffer[fd] = NULL;
	}
	return (line);
}

// int	main(void)
// {
// 	int			fd;
// 	int			fd_bible;
// 	char		*result;
// 	char		*resultb;

// 	fd = open("test.txt", O_RDONLY);
// 	fd_bible = open("bible.txt", O_RDONLY);
// 	for (int i = 0; i < 2; i++)
// 	{
// 		resultb = get_next_line(fd_bible);
// 		result = get_next_line(fd);
// 		printf("%s", resultb);
// 		printf("%s", result);
// 		free(result);
// 		free(resultb);
// 	}
// 	close(fd);
// 	close(fd_bible);
// 	return (0);
// }
