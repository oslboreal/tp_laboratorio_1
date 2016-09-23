#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

// //
// Bibliotecas de ordenamiento de datos.
// Juan Marcos Vallejo
// //


/** \brief Intercambia dos enteros
 *
 * \param Primer entero a intercambiar.
 * \param Segundo entero con el que se realizará el intercambio.
 * \return Retornará: [1] Si se intercambió correctamente - [0] Si no se logró realizar el intercambio.
 *
 */

 int swapInt(int *a, int *b)
     {
         int iniA = *a;
         int iniB = *b;
         int fin = 0;
         int temporal;

         temporal = *a;
         *a = *b;
         *b = temporal;

         if(iniA!=*a&&iniB!=*b)
         {
             fin = 1;
         }

         return fin;
     }

/** \brief Intercambia dos caracteres.
 *
 * \param Primer caracter a intercambiar.
 * \param Segundo caracter con el que se realizará el intercambio.
 * \return Retornará: [1] Si se intercambió correctamente - [0] Si no se logró realizar el intercambio.
 *
 */

 int swapChar(char *a, char *b)
     {
         char iniA = *a;
         char iniB = *b;
         int fin = 0;
         char temporal;

         temporal = *a;
         *a = *b;
         *b = temporal;

         if(iniA!=*a&&iniB!=*b)
         {
             fin = 1;
         }

         return fin;
     }


/** \brief Intercambia dos flotantes.
 *
 * \param Primer flotante a intercambiar.
 * \param Segundo flotante con el que se realizará el intercambio.
 * \return Retornará: [1] Si se intercambió correctamente - [0] Si no se logró realizar el intercambio.
 *
 */

 int swapFloat(float *a, float *b)
     {
         float iniA = *a;
         float iniB = *b;
         int fin = 0;
         float temporal;

         temporal = *a;
         *a = *b;
         *b = temporal;

         if(iniA!=*a&&iniB!=*b)
         {
             fin = 1;
         }

         return fin;
     }

/** \brief Intercambia dos arrays de caracteres con el mismo sub indice..
 *
 * \param Primer array a intercambiar.
 * \param Segundo array a intercambiar.
 * \return Retornará: [1] Si se intercambió correctamente - [0] Si no se logró realizar el intercambio.
 *
 */

 int swapString(char *a, char *b, int tama)
    {
        int comproA;
        int comproB;
        int ret;

        char auxA[tama];
        char auxB[tama];

        char temporal[tama];

        // Asigno para comparar despues antes de swapear.
        strcpy(auxA, a);
        strcpy(auxB, b);

        strcpy(temporal, a); // SWAP
        strcpy(a, b);
        strcpy(b, temporal);

        comproA = strcmp(auxA, b); // Almaceno el retorno de STRCMP para corroborar que se hayan hecho los cambios.
        comproB = strcmp(auxB, a);

        if(comproA == 0 && comproB == 0) // Comprueba que se haya realizado el cambio correctamente.
        {
            ret = 1; // En caso de que comproA se corresponda con B (Ex A) y viceversa, retorno 1.
        } else
            {
                ret = 0; // De lo contrario 0.
            }
        return ret;
    }
