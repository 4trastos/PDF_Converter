# Conversor de PDF a JSON, CSV y XLSX en C

## Descripción

Este proyecto tiene como objetivo desarrollar una aplicación en **C** que permita abrir archivos PDF (exámenes para una web) y transformarlos en formatos estructurados como **JSON**, **CSV** o **XLSX**. Este proceso facilitará la gestión y análisis de los datos contenidos en los exámenes, permitiendo su integración en plataformas web y sistemas de análisis de datos.

## Características

- **Lectura de Archivos PDF:** Abre y lee archivos PDF para extraer su contenido.
- **Extracción de Campos Específicos:** Identifica y extrae campos específicos de los exámenes contenidos en los PDFs.
- **Generación de Archivos Estructurados:** Convierte los datos extraídos a formatos JSON, CSV o XLSX.
- **Manejo de Errores:** Gestiona adecuadamente errores como archivos corruptos, campos no encontrados o problemas en la generación de archivos de salida.
- **Compatibilidad con C++98:** Utiliza solo características compatibles con el estándar C++98.

## Herramientas y Bibliotecas Recomendadas

Para llevar a cabo este proyecto de manera eficiente, es fundamental utilizar bibliotecas que faciliten la manipulación de archivos PDF y la generación de archivos JSON, CSV o XLSX. A continuación, se detallan las herramientas y bibliotecas recomendadas:

### 1. Lectura y Extracción de Datos del PDF

#### **Poppler (poppler-glib)**
- **Descripción:** Poppler es una biblioteca de código abierto para la manipulación de archivos PDF. `poppler-glib` proporciona una interfaz en C para Poppler, facilitando la integración en proyectos en C.
- **Características:**
  - Extrae texto, imágenes y metadatos de PDFs.
  - Soporta lectura de múltiples páginas.
- **Instalación:**
  - En sistemas basados en Debian/Ubuntu:
    ```bash
    sudo apt-get install libpoppler-glib-dev
    ```
- **Enlace:** [Poppler PDF Rendering Library](https://poppler.freedesktop.org/)

### 2. Generación de Archivos JSON, CSV y XLSX

#### **cJSON**
- **Descripción:** cJSON es una biblioteca ligera en C para manejar JSON.
- **Características:**
  - Parsing y escritura de JSON.
  - Fácil de integrar y usar.
- **Instalación:**
  - Puedes clonar el repositorio y compilarlo:
    ```bash
    git clone https://github.com/DaveGamble/cJSON.git
    cd cJSON
    mkdir build
    cd build
    cmake ..
    make
    sudo make install
    ```
- **Enlace:** [cJSON GitHub](https://github.com/DaveGamble/cJSON)

#### **libxlsxwriter**
- **Descripción:** libxlsxwriter es una biblioteca en C para crear archivos XLSX.
- **Características:**
  - Soporta la creación de hojas de cálculo complejas.
  - Ligera y eficiente.
- **Instalación:**
  - Puedes descargarla desde su [sitio oficial](https://libxlsxwriter.github.io/) y seguir las instrucciones de instalación.
    ```bash
    git clone https://github.com/jmcnamara/libxlsxwriter.git
    cd libxlsxwriter
    make
    sudo make install
    ```
- **Enlace:** [libxlsxwriter GitHub](https://github.com/jmcnamara/libxlsxwriter)

#### **Generación de CSV**
- **Descripción:** El formato CSV es sencillo y puede ser generado manualmente utilizando operaciones de escritura estándar en C.
- **Características:**
  - Fácil de implementar sin necesidad de bibliotecas externas.
- **Ejemplo de Escritura en C:**
  ```c
  #include <stdio.h>
  #include <stdlib.h>

  void writeCSV(const char* filename, char*** data, int rows, int cols) {
      FILE* file = fopen(filename, "w");
      if (!file) {
          perror("No se pudo abrir el archivo CSV");
          return;
      }
      for (int i = 0; i < rows; ++i) {
          for (int j = 0; j < cols; ++j) {
              fprintf(file, "%s", data[i][j]);
              if (j < cols - 1) fprintf(file, ",");
          }
          fprintf(file, "\n");
      }
      fclose(file);
  }
