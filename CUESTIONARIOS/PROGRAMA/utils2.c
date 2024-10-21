/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:42:02 by usuario           #+#    #+#             */
/*   Updated: 2024/10/21 13:55:58 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/converter.h"

char	*get_absolute_path(const gchar *pdf)
{
	gchar	*absolute_path;

    absolute_path = g_canonicalize_filename(pdf, NULL);
    if (!absolute_path)
    {
		write(1, "Error obteniendo la ruta absoluta del PDF\n", 42);
		return (NULL);
    }
    return (absolute_path);
}

char	*get_file_uri(const gchar *path)
{
    GError	*error;
    char	*uri;

    error = NULL;
    uri = g_filename_to_uri(path, NULL, &error);
    if (!uri)
    {
		printf("Error %s\n", error->message);
		write(1, "Error al convertir la ruta a URI:\n", 34);
        return (NULL);
    }
    return (uri);
}

int	ft_strcmp(char *str, char* target)
{
	int i = ft_strlen(str);
	int j = ft_strlen(target);
	if (i == j)
	{
		i = 0;
		while(str[i] != '\0' && j > 0)
		{
			if (str[i] != target[i])
				return (-1);
			i++;
			j--;	
		}
		return (0);
	}
	else
		return (-1);	
}