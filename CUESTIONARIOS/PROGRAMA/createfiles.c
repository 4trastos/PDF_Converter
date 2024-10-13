/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   createfiles.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: usuario <usuario@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/10/13 18:57:59 by usuario           #+#    #+#             */
/*   Updated: 2024/10/13 19:02:23 by usuario          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "incl/converter.h"

void writeJSON(const char* filename, char fields[][MAX_FIELD_LENGTH], int count)
{
    cJSON *root = cJSON_CreateObject();
    cJSON *preguntas = cJSON_CreateArray();

    for (int i = 0; i < count; ++i) {
        cJSON_AddItemToArray(preguntas, cJSON_CreateString(fields[i]));
    }

    cJSON_AddItemToObject(root, "preguntas", preguntas);

    char *json_string = cJSON_Print(root);
    FILE *file = fopen(filename, "w");
    if (file) {
        fprintf(file, "%s", json_string);
        fclose(file);
    } else {
        perror("No se pudo abrir el archivo JSON");
    }

    free(json_string);
    cJSON_Delete(root);
}

void writeCSV(const char* filename, char fields[][MAX_FIELD_LENGTH], int count)
{
    FILE* file = fopen(filename, "w");
    if (!file) {
        perror("No se pudo abrir el archivo CSV");
        return;
    }
    for (int i = 0; i < count; ++i) {
        fprintf(file, "\"%s\"", fields[i]);
        if (i < count - 1) fprintf(file, ",");
        fprintf(file, "\n");
    }
    fclose(file);
}

void writeXLSX(const char* filename, char fields[][MAX_FIELD_LENGTH], int count)
{
    lxw_workbook  *workbook  = workbook_new(filename);
    lxw_worksheet *worksheet = workbook_add_worksheet(workbook, NULL);

    for (int i = 0; i < count; ++i) {
        worksheet_write_string(worksheet, i, 0, fields[i], NULL);
    }

    workbook_close(workbook);
}
