#ifndef ABML_H_INCLUDED
#define ABML_H_INCLUDED

#include "Emovies.h"


/**
 *  Bibliotecas Trabajo Práctico III - Laboratorio I
 *  Alumno: Juan Marcos Vallejo - 1ro G. 01/11/2016
 *
 */

int siguienteId(Emovies *p, int cantidadDeRegistros);
void altaPelicula(ArrayList *pList);
void bajaPelicula(ArrayList *pList);
void modificarPelicula(ArrayList *pList);
int inicializarPeliculas(Emovies *p, int cantidadRegistros);
int regOff(Emovies *p, int cantidadDeRegistros);

#endif // ABML_H_INCLUDED
