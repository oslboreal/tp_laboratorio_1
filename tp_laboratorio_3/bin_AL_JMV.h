#ifndef BIN_H_INCLUDED
#define BIN_H_INCLUDED

#include "ArrayListJMV.h"
#include <stdlib.h>
// Cabeceras de manejo de archivos binarios.

int file_saveArrayList(ArrayList *pList, char* fileName, size_t tamanioEntidad);
int file_loadArrayList(ArrayList* pList, char* fileName, size_t tamanioEntidad);

#endif // BIN_H_INCLUDED
