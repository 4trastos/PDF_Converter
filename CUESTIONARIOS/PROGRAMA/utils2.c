/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:42:02 by usuario           #+#    #+#             */
/*   Updated: 2024/10/15 12:12:09 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/converter.h"

char	*get_absolute_path(const char *pdf)
{
	char	*absolute_path;

    absolute_path = realpath(pdf, NULL);
    if (!absolute_path)
    {
		write(1, "Error obteniendo la ruta absoluta del PDF\n", 42);
		return (NULL);
    }
    return (absolute_path);
}

char	*get_file_uri(const char *path)
{
    GError	*error;
    char	*uri;

    error = NULL;
    uri = g_filename_from_uri(path, NULL, &error);
    if (!uri)
    {
		write(1, "Error al convertir la ruta a URI:\n", 37);
        return (NULL);
    }
    return (uri);
}