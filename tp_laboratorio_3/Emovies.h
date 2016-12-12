#ifndef EMOVIES_H_INCLUDED
#define EMOVIES_H_INCLUDED

#include "ArrayListJMV.h"
#include <stdio.h>

/**
 *  Bibliotecas Trabajo Práctico III - Laboratorio I
 *  Alumno: Juan Marcos Vallejo - 1ro G. 01/11/2016
 *
 */

typedef struct{
int id;
int isEmpty;
char titulo[50];
char genero[50];
int duracion;
char descripcion[300];
float puntaje;
char linkImg[150];
}Emovies;

// Constructor y destructor
Emovies* movie_new(void);
int movie_del(Emovies* this);

// Match.
int movie_searchNewId(ArrayList *pList);
int movie_SearchIndexById(ArrayList *pList, int idParaBuscar);

// Getters.
int movie_GetId(Emovies* this);
int movie_GetIsEmpty(Emovies* this);
float movie_GetPuntaje(Emovies* this);
int movie_GetDuracion(Emovies* this);
char* movie_GetTitulo(Emovies* this);
char* movie_GetLinkImg(Emovies* this);
char* movie_GetDescripcion(Emovies* this);
char* movie_GetGenero(Emovies* this);

// Setters
int movie_SetId(Emovies* this, int idParaAsignar);
int movie_SetDuracion(Emovies* this, int duracionParaAsignar);
int movie_SetPuntaje(Emovies* this, float puntajeParaAsignar);
int movie_SetIsEmpty(Emovies* this, int estadoParaAsignar);
int movie_SetLinkImg(Emovies* this, char* textoParaAsignar);
int movie_SetDescripcion(Emovies* this, char* textoParaAsignar);
int movie_SetGenero(Emovies* this, char* textoParaAsignar);
int movie_SetTitulo(Emovies* this, char* textoParaAsignar);

// Informe
void movie_printMovie(Emovies * this);
int file_generarWeb(ArrayList *pList, char* OutputFileName, size_t tamanioEntidad);

#endif // EMOVIES_H_INCLUDED
