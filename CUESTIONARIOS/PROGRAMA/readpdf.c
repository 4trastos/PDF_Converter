/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   readpdf.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 16:41:41 by usuario           #+#    #+#             */
/*   Updated: 2024/10/14 14:33:33 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/converter.h"

char	*ft_extrattextpdf(const char *pdf)
{
	PopplerDocument	*document;
	PopplerPage		*page;
	GError			*error;
	char			*full_text;
	char    		*text;
	int				pages;
	int				i;
	size_t			len;

	error = NULL;
	pages = 0;
	len = 0;
	document = poppler_document_new_from_file(pdf, NULL, &error);
	if (!document)
	{
		write(1, "Error: Could not extract text from PDF.\n", 40);
		return (NULL);
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
		printf("HOLLLLLLLLLLLAAAA %s\n", (char *)page);
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

void	ft_readpdffiles(char *prontf, char *pdf_text, int *flag)
{
	pdf_text = ft_extrattextpdf(prontf);
	if (!pdf_text)
	{
		*flag = -1;
	}
}
