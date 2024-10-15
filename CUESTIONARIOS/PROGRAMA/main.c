/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:19:02 by usuario           #+#    #+#             */
/*   Updated: 2024/10/14 14:33:10 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/converter.h"

int	ft_extractlields(char *pdf_text, char fields[][MAX_FIELD_LENGTH], int max)
{
	regex_t		regex;
	regmatch_t	matches[3];
	const char	*pattern = "(Pregunta [0-9]+:)(.*)";
	const char	*p;
	int			count;
	int			len;

	if (regcomp(&regex, pattern, REG_EXTENDED))
	{
		write(1, "Error: Could not compile regular expression\n", 44);
		return (0);
	}
	count = 0;
	len = 0;
	p = pdf_text;
	while (!regexec(&regex, p, 3, matches, 0))
	{
		if (count >= max)
			break;
		int start = matches[2].rm_so;
        int end = matches[2].rm_eo;
        len = end - start;
        if (len >= MAX_FIELD_LENGTH) len = MAX_FIELD_LENGTH - 1;
        strncpy(fields[count], p + start, len);
        fields[count][len] = '\0';
        count++;
        p += matches[0].rm_eo;
	}
	regfree(&regex);
	return (count);
}

int	main(int argc, char **argv)
{
	char	fields[MAX_FIELDS][MAX_FIELD_LENGTH];
	char	*pdf_text;
	int		field_count;
	int		flag;

	pdf_text = NULL;
	flag = 0;
	if (argc != 2)
	{
		write(1, "Please insert .pdf file\n", 24);
		return (1);
	}
	if (ft_parsepdf(argv[1]) == -1)
	{
		write(1, "Error: File not found; insert .pdf file\n", 40);
		return (1);
	}
	/* pdf_text = ft_readpdffiles(argv[1]);
	if (!pdf_text)
		return (1); */
	ft_readpdffiles(argv[1], pdf_text, &flag);
	if (flag == -1)
		return (1);
	field_count = ft_extractlields(pdf_text, fields, MAX_FIELDS);
	free(pdf_text);
	if (field_count == 0)
	{
		write(1, "Error: No fields were found in the PDF.\n", 40);
		return (1);
	}
	// Generar JSON
	writeJSON("output.json", fields, field_count);
	// Generar CSV
	writeCSV("output.csv", fields, field_count);
	// Generar XLSX
	writeXLSX("output.xlsx", fields, field_count);
	write(1, "Successfully generated files: output.json, output.csv, output.xlsx\n", 67);
	return (0);
}
