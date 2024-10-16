/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readpdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:41:41 by usuario           #+#    #+#             */
/*   Updated: 2024/10/16 17:59:19 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/converter.h"

char	*ft_extrattextpdf(const gchar *pdf)
{
	PopplerDocument	*document;
	PopplerPage		*page;
	GError			*error;
	gchar			*path;
	gchar			*full_text;
	gchar    		*text;
	int				pages;
	int				i;
	size_t			len;

	error = NULL;
	pages = 0;
	len = 0;
	if (!file_exists(pdf)) {
		write(1, "Error: El archivo PDF no existe.\n", 33);
		return (NULL);
	}
	path = get_absolute_path(pdf);
	if (!path)
		return (NULL);
	path = get_file_uri(path);
	if (!path)
		return (NULL);
	document = poppler_document_new_from_file(path, NULL, &error);
	g_free(path);
	if (!document)
	{
		if (error) {
            fprintf(stderr, "Error al abrir el PDF: %s\n", error->message);
            g_error_free(error);
        } else {
            fprintf(stderr, "Error: No se pudo abrir el PDF.\n");
        }
        return NULL;
		/* write(1, "Error: Could not extract text from PDF.\n", 40);
		return (NULL); */
	}
	pages = poppler_document_get_n_pages(document);
	full_text = malloc(1);
	if (!full_text)
		return (NULL);
	full_text[0] = '\0';
	i = 0;
	while (i < pages)
	{
		page = poppler_document_get_page(document, i);
		if (page)
		{
			text = poppler_page_get_text(page);
			if (text)
			{
				len += ft_strlen(text);
				full_text = realloc(full_text, len + 1);
				ft_strjoin(full_text, text);
				free(text);
			}
		}
		i++;
	}
	return (full_text);
}

void	ft_readpdffiles(char *prontf, gchar **pdf_text, int *flag)
{
	*pdf_text = ft_extrattextpdf(prontf);
	if (!pdf_text)
	{
		*flag = -1;
	}
}
