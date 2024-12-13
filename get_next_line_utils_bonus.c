/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils_bonus.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aboumall <aboumall@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/07 02:33:23 by aayoub            #+#    #+#             */
/*   Updated: 2024/12/13 13:54:55 by aboumall         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line_bonus.h"

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

void	join_str(char *temp, char *buffer, char *result, char c)
{
	int	i;
	int	j;

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
}

char	*ft_strjoin(char *buffer, char *result, char c)
{
	char	*temp;
	size_t	size;

	size = ft_strlen(buffer, '\n') + ft_strlen(result, '\0') + 1;
	temp = (char *)ft_calloc(size, sizeof(char));
	if (!temp)
	{
		free(result);
		return (NULL);
	}
	join_str(temp, buffer, result, c);
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
