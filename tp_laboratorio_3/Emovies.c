/**
 *  Bibliotecas Trabajo Práctico III - Laboratorio I
 *  Alumno: Juan Marcos Vallejo - 1ro G. 01/11/2016
 *  Funciones entidad EMovies. - TP 3.
 */

 #include "Emovies.h"
 #include <string.h>
 #include <stdlib.h>
 #include "ArrayListJMV.h"
 #include <stdio.h>

/** \brief Asigna un espacio en memoria para una nueva película
 *
 * \return Retorna la dirección de memoria del espacio asignado.
 *
 */

 Emovies* movie_new(void)
 {
    Emovies *retornoMov;
    retornoMov = NULL;
    retornoMov = malloc(sizeof(Emovies));

    return retornoMov;
 }

/** \brief Libera el espacio de memoria asignado a una película.
 *
 * \param Dirección de memoria de la película a liberar.
 * \return [0] En caso de que la memoria sea liberada correctamente. [-1] En caso de error.
 *
 */

 int movie_del(Emovies* this)
 {
     int retorno = -1;
     if(this != NULL)
     {
        free(this);
        retorno = 0;
     } else
        {
            retorno = -1;
        }

     return retorno;
 }

/** \brief Devuelve el ID de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna el ID de la película o [-1] En caso de error
 *
 */

 int movie_GetId(Emovies* this)
 {
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->id;
    }
    return retorno;
 }

 /** \brief Devuelve el Estado de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna el Estado de la película o [-1] En caso de error
 *
 */

 int movie_GetIsEmpty(Emovies* this)
 {
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->isEmpty;
    }
    return retorno;
 }

/** \brief Devuelve el Puntaje de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna el Puntaje de la película o [-1] En caso de error
 *
 */

 float movie_GetPuntaje(Emovies* this)
 {
     float retorno = -1;
     if(this!=NULL)
     {
         retorno = this->puntaje;
     }
     return retorno;
 }

/** \brief Devuelve el Duracion de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna el Duracion de la película o [-1] En caso de error
 *
 */

 int movie_GetDuracion(Emovies* this)
 {
    int retorno = -1;
    if(this != NULL)
    {
        retorno = this->duracion;
    }
    return retorno;
 }

 /** \brief Modifica el ID de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return [0] Si todo salió bien o [-1] En caso de error
 *
 */

 int movie_SetId(Emovies* this, int idParaAsignar)
 {
    int retorno = -1;
    if(this != NULL && idParaAsignar > 0)
    {
        this->id = idParaAsignar;
        retorno = 0;
    }
    return retorno;
 }

/** \brief Modifica el Duracion de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return [0] Si todo salió bien o [-1] En caso de error
 *
 */

 int movie_SetDuracion(Emovies* this, int duracionParaAsignar)
 {
    int retorno = -1;
    if(this != NULL && duracionParaAsignar > 0)
    {
        this->duracion = duracionParaAsignar;
        retorno = 0;
    }
    return retorno;
 }

/** \brief Modifica el Puntaje de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return [0] Si todo salió bien o [-1] En caso de error
 *
 */

 int movie_SetPuntaje(Emovies* this, float puntajeParaAsignar)
 {
    int retorno = -1;
    if(this != NULL && puntajeParaAsignar >= 0 && puntajeParaAsignar <= 10)
    {
        this->puntaje = puntajeParaAsignar;
        retorno = 0;
    }
    return retorno;
 }

 /** \brief Modifica el Estado de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return [0] Si todo salió bien o [-1] En caso de error
 *
 */

 int movie_SetIsEmpty(Emovies* this, int estadoParaAsignar)
 {
    int retorno = -1;
    if(this != NULL && estadoParaAsignar >= 0 && estadoParaAsignar <= 1)
    {
        this->isEmpty = estadoParaAsignar;
        retorno = 0;
    }
    return retorno;
 }

 /** \brief Devuelve el Titulo de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna el Titulo de la película o NULL En caso de error
 *
 */

 char* movie_GetTitulo(Emovies* this)
 {
    char *direccion = NULL;
    if(this != NULL)
    {
        direccion = this->titulo;
    }
    return direccion;
 }
/** \brief Devuelve el Genero de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna el Genero de la película o NULL En caso de error
 *
 */

 char* movie_GetGenero(Emovies* this)
 {
    char *direccion = NULL;
    if(this != NULL)
    {
        direccion = this->genero;
    }
    return direccion;
 }

/** \brief Devuelve la descripcion de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna la descripcion de la película o NULL En caso de error
 *
 */

 char* movie_GetDescripcion(Emovies* this)
 {
    char *direccion = NULL;
    if(this != NULL)
    {
        direccion = this->descripcion;
    }
    return direccion;
 }

/** \brief Devuelve el link de imagen de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna el link de imagen de la película o NULL En caso de error
 *
 */

 char* movie_GetLinkImg(Emovies* this)
 {
    char *direccion = NULL;
    if(this != NULL)
    {
        direccion = this->linkImg;
    }
    return direccion;
 }

 /** \brief Modifica el link de imagen de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna [0] Si todo está bien o [-1] En caso de error.
 *
 */

 int movie_SetLinkImg(Emovies* this, char* textoParaAsignar)
 {
    int retorno = -1;
    int check = strlen(textoParaAsignar);

    if(this != NULL && check <= 149)
    {
        strcpy(this->linkImg, textoParaAsignar);
        retorno = 0;
    }
    return retorno;
 }

 /** \brief Modifica el Titulo de imagen de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna [0] Si todo está bien o [-1] En caso de error.
 *
 */

 int movie_SetTitulo(Emovies* this, char* textoParaAsignar)
 {
    int retorno = -1;
    int check = strlen(textoParaAsignar);

    if(this != NULL && check <= 49)
    {
        strcpy(this->titulo, textoParaAsignar);
        retorno = 0;
    }
    return retorno;
 }

  /** \brief Modifica el Genero de imagen de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna [0] Si todo está bien o [-1] En caso de error.
 *
 */

 int movie_SetGenero(Emovies* this, char* textoParaAsignar)
 {
    int retorno = -1;
    int check = strlen(textoParaAsignar);

    if(this != NULL && check <= 49)
    {
        strcpy(this->genero, textoParaAsignar);
        retorno = 0;
    }
    return retorno;
 }

/** \brief Modifica la Descripcion de imagen de una película.
 *
 * \param Puntero a la dirección de memoria de la película.
 * \return Retorna [0] Si todo está bien o [-1] En caso de error.
 *
 */

 int movie_SetDescripcion(Emovies* this, char* textoParaAsignar)
 {
    int retorno = -1;
    int check = strlen(textoParaAsignar);

    if(this != NULL && check <= 299)
    {
        strcpy(this->descripcion, textoParaAsignar);
        retorno = 0;
    }
    return retorno;
 }

/** \brief Funcion que busca dentro del array list de peliculas el próximo ID a Asignar a la entidad película
 *
 * \param Array List en cuestion.
 * \return int Retorna el id próximo o -1 en caso de error.
 *
 */

 int movie_searchNewId(ArrayList *pList)
 {
    int ret = -1;
    int mayor = 0; // Acumulador.
    int i; // Contador
    Emovies *aux = movie_new();

    if(pList!=NULL)
    {
        if(al_isEmpty(pList) == 1) // If the array list is empty.
        {
            ret = 1; // In this case the first ID will be 1.
        }
        else
            {
                printf("Espacio utilizado. [%d / %d]\n", al_len(pList), pList->reservedSize);
                for(i=0; i < al_len(pList); i++) //
                {
                        aux = al_get(pList, i);
                        if(movie_GetId(aux) >= mayor)
                        {
                            mayor = movie_GetId(aux);
                        }
                }
                    ret = mayor;
                    ret++;
            }
    }
    //movie_del(aux); // Free space in memory.
    return ret;

 }

 /** \brief Obtain the index of the movie in the array list by ID.
  *
  * \param Pointer to arrayList.
  * \param int Id to search in the AL.
  * \return Returns the index of the element or -1 in case of error.
  *
  */

  int movie_SearchIndexById(ArrayList *pList, int idParaBuscar)
  {
    int ret = -1;
    int i; // Contador.
    Emovies *aux = movie_new();

        for(i=0; i < al_len(pList); i++)
        {
            aux = al_get(pList, i);
            if(movie_GetId(aux) == idParaBuscar)
            {
                ret = i;
                break;
            }
        }

    return ret;

  }

/** \brief Muestra todos los campos de una pelicula.
 *
 * \param Puntero Emovie a la pelicula a mostrar.
 *
 */

 void movie_printMovie(Emovies * this)
 {
     if(this != NULL)
     {
         printf("[ID: %d] Titulo: %s - Puntaje: %f.\n", movie_GetId(this), movie_GetTitulo(this), movie_GetPuntaje(this));
     } else
        {
            printf("No hay datos para mostrar.\n");
        }
 }

 /** \brief Genera un fp binario conteniendo una array list completa.
 *
 * \param Arraylist a almacenar.
 * \param char * - Nombre del fp.
 * \return 0 - En caso de guardar los datos correctamente .. -1 En caso de error.
 *
 */

 int file_generarWeb(ArrayList *pList, char* OutputFileName, size_t tamanioEntidad)
 {
     int ret = -1;
     int cantidad = al_len(pList); // Almacenamos la cantidad de elementos registrados.
     int total = 0;
     void *auxiliar;
     int i;
     if(pList != NULL && OutputFileName != NULL)
     {
         FILE *fp = fopen(OutputFileName, "wb");
         if(fp != NULL) // Corroboramos existencia del fp.
         {
            fprintf(fp,"<!DOCTYPE html>\n<html>\n<head>\n<title>Trabajo Practico Nº3</title>\n</head>\n<body><article class='col-md-4 article-intro'>");

            for(i=0; i < cantidad; i++)
            {
            auxiliar = al_get(pList, i); // Traemos el proximo elemento del array list.
            fprintf(fp,"<a href='#'><h3>%s</h3></a>",movie_GetTitulo(auxiliar));
            fprintf(fp,"<img class='img-responsive img-rounded' src='%s'alt=''>",movie_GetLinkImg(auxiliar));
            fprintf(fp,"<ul><li>Genero:%s</li>",movie_GetGenero(auxiliar));
            fprintf(fp,"<li>Puntaje:%.1f</li>",movie_GetPuntaje(auxiliar));
            fprintf(fp,"<li>Duracion:%d minutos</li></ul>",movie_GetDuracion(auxiliar));
            fprintf(fp,"<p>%s</p>",movie_GetDescripcion(auxiliar));
            }
            fprintf(fp,"</article></body></html>");



            }
            printf("[LOG] Se escribieron %d elementos.", total);
            ret = 0;
            fclose(fp);
         } else
            {
                printf("[ERROR] Error al abrir el fp.");
            }

     return ret;
 }
