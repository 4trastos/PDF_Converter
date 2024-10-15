/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   converter.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 14:26:18 by usuario           #+#    #+#             */
/*   Updated: 2024/10/15 11:44:25 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CONVERTER_H
# define CONVERTER_H

# include <string.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>
# include <poppler/glib/poppler.h>
# include <cjson/cJSON.h>
# include <xlsxwriter.h>
# include <regex.h>
# include <sys/stat.h>

# define MAX_FIELDS 1000
# define MAX_FIELD_LENGTH 256

//*** MAIN ***//

int		main(int argc, char **argv);

//*** PARSE ***//

int		ft_parsepdf(char *str);
int     file_exists(const char* filename);
char    *get_absolute_path(const char *pdf);

//*** READ PDF ***//

void	ft_readpdffiles(char *prontf, char *pdf_text, int *flag);
char	*ft_extrattextpdf(const char *pdf);
int		ft_extractlields(char *pdf_text, char fields[][MAX_FIELD_LENGTH], int max);

//*** UTILS ***//

size_t	ft_strlen(char *str);
char	*ft_strchr(char *str, int c);
char	*ft_strjoin(char *str, char *cat);

//*** CREATE FIELDS ***//

void    writeJSON(const char* filename, char fields[][MAX_FIELD_LENGTH], int count);
void    writeCSV(const char* filename, char fields[][MAX_FIELD_LENGTH], int count);
void    writeXLSX(const char* filename, char fields[][MAX_FIELD_LENGTH], int count);

#endif