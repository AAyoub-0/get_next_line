/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aayoub <aayoub@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:33:23 by aayoub            #+#    #+#             */
/*   Updated: 2024/12/07 15:23:06 by aayoub           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"

size_t	ft_strlen(char *str, char c)
{
	size_t	size;

	size = 0;
	if (str == NULL)
		return (0);
	while (str[size] != '\0' && str[size] != c)
		size++;
	if (str[size] != '\0' && str[size] == c)
		size++;
	return (size);
}

int	ft_strrchr(char *s, int c)
{
	ssize_t	size;

	size = ft_strlen(s, '\0');
	if (!s || size <= 0)
		return (0);
	while (size >= 0 && s[size] != c)
		size--;
	if (size == -1)
		return (0);
	return (1);
}

int	ft_strchr(char *s, int c)
{
	size_t	i;

	i = 0;
	if (!s)
		return (0);
	while (s[i] != '\0' && s[i] != c)
		i++;
	if (s[i] == c)
		return (1);
	return (0);
}

char	*ft_strjoin(char *buffer, char *result, char c)
{
	char	*temp;
	size_t	size;
	int		i;
	int		j;

	size = ft_strlen(buffer, '\n') + ft_strlen(result, '\0') + 1;
	temp = (char *)ft_calloc(size, sizeof(char));
	if (!temp)
		return (NULL);
	i = 0;
	j = 0;
	while (result && result[i])
	{
		temp[i] = result[i];
		i++;
	}
	while (buffer[j] && buffer[j] != c)
	{
		temp[i + j] = buffer[j];
		j++;
	}
	if (buffer[j] == c)
		temp[i + j] = c;
	free(result);
	return (temp);
}

void	*ft_calloc(size_t nmemb, size_t size)
{
	unsigned char	*result;
	size_t			i;

	if (!size && nmemb > SIZE_MAX / size)
		return (NULL);
	if (nmemb == 0 || size == 0)
		return (malloc(0));
	result = malloc(nmemb * size);
	if (!result)
		return (NULL);
	i = 0;
	while (i < nmemb * size)
	{
		result[i] = 0;
		i++;
	}
	return ((void *)result);
}
