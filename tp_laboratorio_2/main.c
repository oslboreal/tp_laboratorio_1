#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <windows.h>
#include "funciones.h"


// //
//
// Trabajo practico 2 - Juan Marcos Vallejo
// Universidad Tecnológica Nacional
// Prof. Lic. Mauricio Dávila y Scarafilo Germán.
//
// //

int main()
{

    // Configuracion de interface.
    system("color 4b");
    SetConsoleTitle("Sistema de administracion de personas.");
    // Variables de estado y contadores.
    char seguir='s';
    int opcion=0;
    struct datosPersonas pers[20];

    // Inicializa todos los estados en "vacio".
    inicializarRegistros(pers); // Ademas limpia algunos campos.


    /* Harcodeo de Usuarios para que puedan realizar las pruebas sin tardar 20 años (Sacan el asterisco del principio y listo.).
    //

    strcpy(pers[0].nombre, "Gonzalo Rodriguez");
    pers[0].idEstado = 'a';
    pers[0].id = 1;
    pers[0].idGrupo = 1;
    pers[0].edad = 8;
    pers[0].dni = 38589601;

    strcpy(pers[1].nombre, "Uranio Tecnoctro Nacho");
    pers[1].idEstado = 'a';
    pers[1].id = 2;
    pers[1].idGrupo = 1;
    pers[1].edad = 8;
    pers[1].dni = 23589601;

    strcpy(pers[2].nombre, "Ufalo Teranio Nacionol");
    pers[2].idEstado = 'a';
    pers[2].id = 3;
    pers[2].idGrupo = 2;
    pers[2].edad = 19;
    pers[2].dni = 34589601;

    strcpy(pers[3].nombre, "Devora Meltrozo");
    pers[3].idEstado = 'a';
    pers[3].id = 4;
    pers[3].idGrupo = 3;
    pers[3].edad = 65;
    pers[3].dni = 23589601;

    strcpy(pers[4].nombre, "Juan Carlos Peloduro");
    pers[4].idEstado = 'a';
    pers[4].id = 5;
    pers[4].idGrupo = 1;
    pers[4].edad = 8;
    pers[4].dni = 58589601;

    //
    //////////////////////////////////////////////////////////////////////////////////*/



    // Estructura repetitiva del menú esperando que el flag cambie.
    while(seguir=='s')
    {
        system("cls");
        printf("1- Agregar persona\n");
        printf("2- Borrar persona\n");
        printf("3- Imprimir lista ordenada por  nombre\n");
        printf("4- Imprimir grafico de edades\n");
        printf("5- Salir \n");


        printf("\nOpcion: ");
        scanf("%d",&opcion);
        fflush(stdin);

        switch(opcion)
        {
            case 1:
                    loadPerson(pers,20); // Funcion para dar el alta a una nueva persona.
                    system("pause");     // Argumentos puntero del array de la estructura y tamaño del array.

                    break;

            case 2:
                    deleteUsser(pers);// Muestra una lista de usuarios con determinado estado. (ACTIVOS)
                    system("pause");  // Y solicita el ingreso del ID para realizar la baja.
                    break;

            case 3:
                    system("cls");
                    orderPerByName(pers, CANTPERS); // Ordeno a las personas por nombre
                    system("pause");

                    printPerson(pers, CANTPERS); // Imprimo las funciones.


                    system("pause");
                    break;

            case 4:
                 groupGraph(pers, CANTPERS); // Funcion que genera un gráfico estadistio.
                 system("pause");
                    break;

            case 5:
                    seguir = 'n';

        }
    }

    return 0;
}


