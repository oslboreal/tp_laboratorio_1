#include "bin.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListJMV.h"

// Manejo de archivos binarios.
// Libreria desarrollada por Marcos Vallejo.
// oslboreal@gmail.com - Tw. Boreal_Arg
//

/** \brief Genera un archivo binario conteniendo una array list completa.
 *
 * \param Arraylist a almacenar.
 * \param char * - Nombre del archivo.
 * \return 0 - En caso de guardar los datos correctamente .. -1 En caso de error.
 *
 */

 int file_saveArrayList(ArrayList *pList, char* fileName, size_t tamanioEntidad)
 {
     int ret = -1;
     int cantidad = al_len(pList); // Almacenamos la cantidad de elementos registrados.
     int escritos;
     int total = 0;
     void *auxiliar;
     int i;
     if(pList != NULL && fileName != NULL)
     {
         FILE *fp = fopen(fileName, "wb");
         if(fp != NULL) // Corroboramos existencia del archivo.
         {
            for(i=0; i < cantidad; i++)
            {
                auxiliar = al_get(pList, i); // Traemos el proximo elemento del array list.
                escritos = fwrite(auxiliar, tamanioEntidad, 1, fp); // Almacenamos el elemento en nuestro fichero.
                total = total + escritos;
            }
            printf("[LOG] Se escribieron %d elementos.", total);
            ret = 0;
            fclose(fp);
         } else
            {
                printf("[ERROR] Error al abrir el archivo.");
            }
     }

     return ret;
 }

 /** \brief Carga desde un archivo binario el contenido a una array list completa.
 *
 * \param Arraylist a almacenar.
 * \param char * - Nombre del archivo.
 * \param int - Tamaño de la estructura a leer.
 * \return 0 - En caso de cargar los datos correctamente .. -1 En caso de error.
 *
 */

 int file_loadArrayList(ArrayList* pList, char* fileName, size_t tamanioEntidad)
 {
    int ret = -1;
    int cantidadNueva = 0;
    int cantidadTotal = 0;
    if(pList!=NULL && fileName != NULL)
    {
        FILE* fr = fopen(fileName, "rb"); // Abrimos el archivo.
        if(fr != NULL)
        {
            rewind(fr);
            while(!feof(fr)) // Mientras no lleguemos al final del archivo.
            {
                void *auxiliar = malloc(tamanioEntidad);
                cantidadNueva = fread(auxiliar, tamanioEntidad, 1, fr); // Leemos el archivo y procedemos a almacenar la cantidad de bytes.
                if(cantidadNueva == 1)
                {
                    al_add(pList, auxiliar);
                }
                cantidadTotal = cantidadTotal + cantidadNueva; // Acumulamos para luego imprimir.
                cantidadNueva = 0; // Reiniciamos.
            }
            printf("\n[LOG] Cargados correctamente %d Bytes.\n", cantidadTotal);
            fclose(fr);
            ret = 0;
        }else
            {
                printf("[LOG] El archivo %s no existe\n[LOG] Este puede ser su primer ingreso o ocurrio un error.\n\n", fileName);
            }

    }
    return ret;
 }

