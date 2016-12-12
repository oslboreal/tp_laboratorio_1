#include "abml.h"
#include "Validaciones.h"
#include "defines.h"
#include "Emovies.h"
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>


/**
 *  Bibliotecas Trabajo Práctico III - Laboratorio I
 *  Alumno: Juan Marcos Vallejo - 1ro G. 01/11/2016
 * - Funciones alta, baja, mod, listar - ABML TP 3.
 */

/** \brief Inicializa todos los registros como vacios. (Estado 1 por convencion).
 *
 * \param Emovies puntero del arreglo a inicializar.
 * \param int Tamaño del arreglo
 * \return int [0] En caso de que este todo bien - int [-1] En caso de que exista un error
 *
 */

 int inicializarPeliculas(Emovies *p, int cantidadRegistros)
 {
    int retorno = -1;
    int i;


    if(p!=NULL)
    {
        for(i=0; i<cantidadRegistros; i++)
        {
            p[i].isEmpty = 1;
        }
        retorno = 0;

    }

    return retorno;
 }


/** \brief Indica cual es el primer id vacio
* \param EMovies Dirección de memoria del arreglo de estructura.
* \param int Tamaño del arreglo pasado como primer argumento
* \return  int NRO de ID a Asignar..
*
*/

int siguienteId(Emovies *p, int cantidadDeRegistros)
    {
        int i;
        int ubi;
        for(i = 0; i<cantidadDeRegistros; i++)
        {

            if(p[i].isEmpty==1) // Recorro el array buscando coincidencias.
            {
                ubi = i+1;           // Si encuentro una coincidencia retorno la direccion del array.
                break;

            } else // De lo contrario el valor a retornar será -1.
                {
                    ubi = -1;
                }

        }


return ubi;
    }


/** \brief Indica cual es el primer registro vacio (Siendo vacío 1 por convencion).
* \param EMovies Dirección de memoria del arreglo de estructura.
* \param int Tamaño del arreglo pasado como primer argumento
* \return  int Lugar vacio en el array..
*
*/

int regOff(Emovies *p, int cantidadDeRegistros)
    {
        int i;
        int ubi;
        for(i = 0; i<cantidadDeRegistros; i++)
        {

            if(p[i].isEmpty==1) // Recorro el array buscando coincidencias.
            {
                ubi = i;           // Si encuentro una coincidencia retorno la direccion del array.
                break;

            } else // De lo contrario el valor a retornar será -1.
                {
                    ubi = -1;
                }

        }


return ubi;
    }

/** \brief Formulario de alta de una nueva pelicula.
 *
 * \return Void.
 *
 */

 void altaPelicula(ArrayList *pList)
 {
    char buffer[6][1024]; // Declaración de los Buffers utilizados para validar los campos a cargar.
    int continuar = 1; // Indica si se debe continuar cargando campos.
    int chequeo[6] = {0,0,0,0,0}; //
    char respuesta[6];
    int campoEnCarga = 0;
    int nuevoId;
    Emovies *aux = movie_new();
    nuevoId = movie_searchNewId(pList);
    system("cls");

    // Titulo de la pelicula.
    while(continuar == 1)
    {
    if(campoEnCarga == 0)
    {
    system("cls");
    printf("[ID: %d] Ingrese el titulo de la pelicula:\n", nuevoId);
    fflush(stdin);
    gets(buffer[0]);
    printf("%s", buffer[0]);
    chequeo[0] = validateField(buffer[0], 1024, NOMBRE, 1, 50); // Si se detecta error al validar retorna un 0.
    printf("%s", buffer[0]);
    if(chequeo[0] == 0) // Detectamos un error en la validación.
    {
        while(respuesta[0] != 's' || respuesta[0] != 'n') // Preguntamos reingreso
        {
        system("cls");
        printf("[ERROR] Los datos fueron ingresados incorrectamente.\n");
        printf("[ERROR] Te gustaria volver a ingresarlos? (S/N)");
        respuesta[0] = getchar();
        respuesta[0] = (char)tolower(respuesta[0]);

            if(respuesta[0] == 's') // Si responde que sí simplemente salimos de la estructura así vuelve a preguntar el nombre.
                break;

            if(respuesta[0] == 'n') // Si responde que no salimos de la estructura pero el flag continuar es 0
            {
                chequeo[0] = -1; // Indicamos que en la instancia 0 del chequeo ocurrió un error.
                continuar = 0; // Hacemos que el while deje de iterar.
                break;
            }
        }
        continue;
    }

    if(chequeo[0] == -1) // El usuario decide no continuar.
    {
        break;
    }
    if(chequeo[0] == 1) // Si todo sale bien.
    {
        movie_SetTitulo(aux, buffer[0]);
        campoEnCarga = 1;
    }
    }
    // Genero de la pelicula.
    if(campoEnCarga == 1)
    {
    system("cls");
    printf("[ID: %d] Ingrese el genero de la pelicula:\n", nuevoId);
    fflush(stdin);
    gets(buffer[1]);
    chequeo[1] = validateField(buffer[1], 1024, NOMBRE, 1, 50);

    if(chequeo[1] == 0) // Detectamos un error en la validación.
    {
        while(respuesta[1] != 's' || respuesta[1] != 'n')
        {
        system("cls");
        printf("[ERROR] Los datos fueron ingresados incorrectamente.\n");
        printf("[ERROR] Te gustaria volver a ingresarlos? (S/N)");
        respuesta[1] = getchar();
        respuesta[1] = (char)tolower(respuesta[1]);

            if(respuesta[1] == 's')
                break;

            if(respuesta[1] == 'n')
            {
                chequeo[1] = -1; // Registramos el error.
                continuar = 0; // Dejamos de iterar
                break;
            }
        }
        continue;
    }
    if(chequeo[1] == -1) // El usuario decide no continuar.
    {
        break;
    }
    if(chequeo[1] == 1) // Si todo salió bien.
    {
        movie_SetGenero(aux, buffer[1]); // Asigno el genero.
        campoEnCarga = 2;
    }
    }
    // Descripcion
    if(campoEnCarga == 2)
    {
        system("cls");
        printf("[ID: %d] Ingrese la descripcion de la pelicula:\n", nuevoId);
        fflush(stdin);
        gets(buffer[2]);
        chequeo[2] = validateField(buffer[2], 1024, NOMBRE, 1, 299);

    if(chequeo[2] == 0) // Detectamos un error en la validación.
    {
        while(respuesta[2] != 's' || respuesta[2] != 'n')
        {
        system("cls");
        printf("[ERROR] Los datos fueron ingresados incorrectamente.\n");
        printf("[ERROR] Te gustaria volver a ingresarlos? (S/N)");
        respuesta[2] = getchar();
        respuesta[2] = (char)tolower(respuesta[1]);

            if(respuesta[2] == 's')
                break;

            if(respuesta[2] == 'n')
            {
                chequeo[2] = -1;// Registramos el error.
                continuar = 0; // Dejamos de iterar
                break;
            }
        }
        continue;
    }

    if(chequeo[2] == -1) // El usuario decide no continuar.
    {
        break;
    }
    if(chequeo[2] == 1)
    {
        movie_SetDescripcion(aux, buffer[2]);
        campoEnCarga = 3; // Asigno como siguiente campo a cargar la "Duracion"
    }
    }
    // Duracion
    if(campoEnCarga == 3)
    {
        system("cls");
        printf("[ID: %d] Ingrese la cantidad de minutos que dura la pelicula:\n", nuevoId);
        fflush(stdin);
        gets(buffer[3]);
        chequeo[3] = validateField(buffer[3], 1024, NUMERO, 1, 299);

    if(chequeo[3] == 0) // Detectamos un error en la validación.
    {
        while(respuesta[3] != 's' || respuesta[3] != 'n')
        {
            system("cls");
            printf("[ERROR] Los datos fueron ingresados incorrectamente.\n");
            printf("[ERROR] Te gustaria volver a ingresarlos? (S/N)");
            respuesta[3] = getchar();
            respuesta[3] = (char)tolower(respuesta[3]);

            if(respuesta[3] == 's')
                break;

            if(respuesta[3] == 'n')
            {
                chequeo[3] = -1;
                continuar = 0;
                break;
            }
        }
        continue;
    }

    if(chequeo[3] == -1) // El usuario decide no continuar.
    {
        break;
    }
    if(chequeo[3] == 1)
    {
        movie_SetDuracion(aux, atoi(buffer[3]));
        campoEnCarga = 4;
    }
    }
    // Link de la imagen
    if(campoEnCarga == 4)
    {
        system("cls");
        printf("[ID: %d] Ingrese el directorio de la imagen:\n", nuevoId);
        fflush(stdin);
        gets(buffer[4]);
        chequeo[4] = validateField(buffer[4], 1024, 3, 1, 299);

    if(chequeo[4] == 0) // Detectamos un error en la validación.
    {
        while(respuesta[4] != 's' || respuesta[4] != 'n')
        {
            system("cls");
            printf("[ERROR] Los datos fueron ingresados incorrectamente.\n");
            printf("[ERROR] Te gustaria volver a ingresarlos? (S/N)");
            respuesta[4] = getchar();
            respuesta[4] = (char)tolower(respuesta[4]);

            if(respuesta[4] == 's')
                break;

            if(respuesta[4] == 'n')
            {
                chequeo[4] = -1;
                continuar = 0;
                break;
            }
        }
        continue;
    }

    if(chequeo[4] == -1) // El usuario decide no continuar.
    {
        break;
    }
    if(chequeo[4] == 1)
    {
        movie_SetLinkImg(aux, buffer[4]);
        campoEnCarga = 5;
    }
    }
    // PUNTAJE
    if(campoEnCarga == 5)
    {
        system("cls");
        printf("[ID: %d] Ingrese el puntaje de la pelicula:\n", nuevoId);
        fflush(stdin);
        gets(buffer[5]);
        chequeo[5] = validateField(buffer[5], 1024, NUMERO, 1, 299);

    if(chequeo[5] == 0) // Detectamos un error en la validación.
    {
        while(respuesta[5] != 's' || respuesta[5] != 'n')
        {
            system("cls");
            printf("[ERROR] Los datos fueron ingresados incorrectamente.\n");
            printf("[ERROR] Te gustaria volver a ingresarlos? (S/N)");
            respuesta[5] = getchar();
            respuesta[5] = (char)tolower(respuesta[5]);

            if(respuesta[5] == 's')
                break;

            if(respuesta[5] == 'n')
            {
                chequeo[5] = -1;
                continuar = 0;
                break;
            }
        }
        continue;


    }

    if(chequeo[5] == -1) // El usuario decide no continuar.
    {
        break;
    }
    if(chequeo[5] == 1)
    {
        movie_SetPuntaje(aux, atoi(buffer[5]));
        campoEnCarga = 6;
    }
    }

    // Asignación.
    if(campoEnCarga == 6) // Si se llegó al final.
    {
        movie_SetId(aux, nuevoId); // Set del ID
        movie_SetIsEmpty(aux, ACTIVO); // Set el estado.

        system("cls");
        printf("Datos ingresados correctamente.\n");
        printf("Titulo: %s - Descripcion: %s - Genero: %s\n", movie_GetTitulo(aux), movie_GetDescripcion(aux), movie_GetGenero(aux));
        printf("Puntaje: %.2f - Duracion: %d\n", movie_GetPuntaje(aux), movie_GetDuracion(aux));
        printf("ENLACE: %s\n", movie_GetLinkImg(aux));
        printf("ID:%d --", movie_GetId(aux));

     // Agregar el elemento al array list.
    if(pList!=NULL)
    {
        al_add(pList, aux);
        printf("\n-- Pelicula agregada correctamente - ID:%d --", movie_GetId(aux));
    } else
        {
            printf("[ERROR] Surgio un problema. a la hora de almacenar en la Array List.\n");
        }


    }

    break;
 }// While


 }

 /** \brief Formulario de baja de una película.
  *
  *
  */

void bajaPelicula(ArrayList *pList)
{
    char buffer[1024];
    int indice, ingreso;
    printf("Ingrese el ID de la pelicula que desea dar la baja:");
    fflush(stdin);
    gets(buffer);
    ingreso = atoi(buffer);
    if(ingreso > 0 && pList != NULL)
    {
        // Buscamos el indice.
        indice = movie_SearchIndexById(pList, ingreso);
        if(indice >= 0 && indice < al_len(pList))
        {
            al_remove(pList, indice);
            printf("La pelicula se borro correctamente.\n\n");
        }
    }
    // Si se detecta error se manifiesta.
    if(indice == -1)
    {
        printf("[ERROR] El ID Ingresado es inexistente.\n");
    }
}

/** \brief Formulario de modificación de una pelicula.
 *
 * \param
 *
 */

 void modificarPelicula(ArrayList *pList)
 {
    if(pList!=NULL)
    {

    char ingreso[1024];
    Emovies * auxiliar = movie_new(); // Construimos el elemento.
    system("cls");
    printf("- Modificacion de pelicula - \n");
    printf("Ingresa el ID Del usuario a modificar: ");
    fflush(stdin);
    scanf("%s", ingreso);
    if(validateIsNum(ingreso, 1) == 1 && atoi(ingreso) <= al_len(pList))
    {
        auxiliar = al_get(pList, movie_SearchIndexById(pList, atoi(ingreso)));
        movie_printMovie(auxiliar);
        char buffer[5][1024];
        printf("Ingrese el nuevo titulo: [ALFANUMERICOS]");
        fflush(stdin);
        scanf("%s",buffer[0]);
        printf("Ingrese la nueva descripcion: [ALFANUMERICOS]");
        fflush(stdin);
        scanf("%s",buffer[1]);
        printf("Ingrese la duracion: [NUMERICOS]");
        fflush(stdin);
        scanf("%s",buffer[2]);
        printf("Ingrese el enlace: [ALFANUMERICOS + ESPECIALES]");
        fflush(stdin);
        scanf("%s",buffer[3]);
        printf("Ingrese el puntaje: [NUMERICOS]");
        fflush(stdin);
        scanf("%s",buffer[4]);

        // Validaciones.
        if(validateIsPos(atoi(buffer[2])) == 1 && validateIsPos(atoi(buffer[4])))
        {
             if(validateIsNum(buffer[2],2) == 1 && validateIsNum(buffer[4],2))
            {
                auxiliar = al_pop(pList, movie_SearchIndexById(pList, atoi(ingreso)));
                movie_SetDescripcion(auxiliar, buffer[1]);
                movie_SetDuracion(auxiliar, atoi(buffer[2]));
                movie_SetTitulo(auxiliar, buffer[0]);
                movie_SetPuntaje(auxiliar, atoi(buffer[4]));
                movie_SetLinkImg(auxiliar, buffer[3]);

                al_add(pList, auxiliar);
                movie_printMovie(auxiliar);
            }
        }
    } else
        {
            printf("El id ingresado es invalido.");
        }



    system("pause");

    }
 }
