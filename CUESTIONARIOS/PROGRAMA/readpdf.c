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
	GError *error = NULL;
	PopplerDocument *document = poppler_document_new_from_file(pdf, NULL, &error);
	if (!document){
		printf("%s\n", "no se pudo abrir el pdf");
		return NULL;
	}
	int num_pag = poppler_document_get_n_pages(document);

	char *text;
	for (int i = 0; i < num_pag; i++){
		PopplerPage *page = poppler_document_get_page(document, i);
		if (!page){
			printf("No se pudo obtener la pagina %d\n", i);
			continue;
		}
		text = poppler_page_get_text(page);
		if (text){
			printf("Pagina %d\n %s \n", i + 1, text);
		} else {
			printf("nose pudo obtener el texto de la pagina %d\n", i);
		}
	}
	return (text);
}

void	ft_readpdffiles(char *prontf, gchar **pdf_text, int *flag)
{
	*pdf_text = ft_extrattextpdf(prontf);
	if (!pdf_text)
	{
		*flag = -1;
	}
}
