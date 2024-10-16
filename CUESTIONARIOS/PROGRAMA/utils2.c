/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils2.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/15 11:42:02 by usuario           #+#    #+#             */
/*   Updated: 2024/10/16 17:50:54 by usuario          ###   ########.fr       */
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
	printf("path : => %s\n", path);
    uri = g_filename_to_uri(path, NULL, &error);
    if (!uri)
    {
		printf("Error %s\n", error->message);
		write(1, "Error al convertir la ruta a URI:\n", 34);
        return (NULL);
    }
	printf("Ruta URI: => %s", uri);
    return (uri);
}