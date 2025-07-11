/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 15:36:16 by usuario           #+#    #+#             */
/*   Updated: 2024/10/21 13:44:56 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/converter.h"

int	file_exists(const char* filename)
{
	struct stat buffer;
	return (stat(filename, &buffer) == 0);
}

char	*ft_strjoin(char *str, char *cat)
{
	char	*new;
	int		i;
	int		j;

	i = 0;
	new = malloc(ft_strlen(str) + ft_strlen(cat) + 1);
	if (!new)
		return (NULL);
	while (str[i] != '\0')
	{
		new[i] = str[i];
		i++;
	}
	j = 0;
	while (cat[j] != '\0')
	{
		new[i] = cat[j];
		i++;
		j++;
	}
	new[i] = '\0';
	return (new);
}

size_t	ft_strlen(char *str)
{
	size_t	i;

	i = 0;
	while (str[i] != '\0')
		i++;
	return (i);
}

char	*ft_strchr(char *str, int c)
{
	int	i;

	i = 0;
	while (str[i] != '\0')
	{
		if (str[i] == (unsigned char)c)
			return ((char *)&str[i]);
		i++;
	}
	if ((char)c == '\0')
		return ((char *)&str[i]);
	return (NULL);
}

int	ft_parsepdf(char *str)
{
	char	*point;

	point = ft_strchr(str, '.');
	if (!point)
		return (-1);
	if (ft_strcmp(point, ".pdf") == -1)
		return (-1);
	return (0);
}
