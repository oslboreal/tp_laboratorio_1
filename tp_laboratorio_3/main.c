#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#include "defines.h"
#include "Emovies.h"
#include "abml.h"
#include "bin_AL_JMV.h"

#include <windows.h>

int main()
{
    ArrayList *peliculasRegistradas = al_newArrayList(); // Asigno un espacio en memoria a nuestro AL.
    file_loadArrayList(peliculasRegistradas, "data.dat", sizeof(Emovies));
    int opcion;
    char seguir = 's';
    while(seguir == 's')
    {
        system("cls");
        printf("\t\t\t-- Cantidad de peliculas agregadas: %d --\n\n", peliculasRegistradas->size);
        printf("\t\t\t[1]. Agregar pelicula.\n");
        printf("\n");
        printf("\t\t\t[2]. Borrar pelicula.\n");
        printf("\n");
        printf("\t\t\t[3]. Modificar pelicula.\n");
        printf("\n");
        printf("\t\t\t[4]. Generar sitio web.\n");
        printf("\n");
        printf("\t\t\t[5]. Salir y guardar.\n\n");
        if(al_isEmpty(peliculasRegistradas) == 1)
        {
            printf("\t\t\t El array list se encuentra vacio\n\n");
        } else
            {
                printf("\t\t\t-- Espacio reservado: %d --\n", peliculasRegistradas->reservedSize);
            }
        printf("\t\t\t-- Cantidad de bytes en Memoria: %d Bytes --\n\n", al_reservedBytes(peliculasRegistradas));
        printf("\n\t\t\tOPCION: ");
        scanf("%d", &opcion);

        switch(opcion)
        {
        case 1: // Agregar una nueva pelicula.
            altaPelicula(peliculasRegistradas); // Funcion que incluye formulario para el alta de una nueva entidad.
            system("pause");
            break;
        case 2: // Borrar una pelicula.
            bajaPelicula(peliculasRegistradas);
            system("pause");
            break;
        case 3:// Modificar una película.
            modificarPelicula(peliculasRegistradas);

            break;
        case 4: // Generar sitio web de peliculas.
            if(file_generarWeb(peliculasRegistradas, "PaginaWeb.html", sizeof(Emovies)) == 0)
            {
            system("cls");
            printf("Informe web generado correctamente.\n");
            system("pause");
            }
            break;
        case 5:
            file_saveArrayList(peliculasRegistradas, "data.dat", sizeof(Emovies));
            exit(1);
            break;


        };


    }

    return 0;
}
