#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "funciones.h"
#include <windows.h>
#include <conio.h>

#define alertar 1
#define noAlertar 0


/* ---------------------------------------------------------  /
//
// Calculadora básica - Trabajo práctico 1 (UTN FRA)
//
// Alumno Juan Marcos Vallejo.
// Prof. Scarafilo German & Lic. Mauricio Dávila.
//
// --------------------------------------------------------- */
    // Variables de estado.
    char seguir='s';

    int caracter;

    // Operandos
    //char chequeoOperando[100];
    char opeChar[50];
    float primerOperando = 0;
    float segundoOperando = 0;
    float operacionRes = 0;
    char textoRes[50];

    // Variables de configuracion.
    char textoPorDefecto[100] = "Bienvenido, selecciona una opcion para comenzar.";
    char estiloPorDefecto[10] = "color 0B";
    int mensajeDefecto = 1;
    char textoNoRes[50] = "No hay resultado que mostrar.";
    char tituloDelPrograma[80] = "Calculador v0.4 - Universidad Tecnologica Nacional.";

int main()
{


    //Configuracion de la interface.
    system(estiloPorDefecto);
    SetConsoleTitle(tituloDelPrograma);

    while(seguir=='s')
    {
        if(mensajeDefecto==1)
        {
        mostrarAlerta(textoPorDefecto,primerOperando,segundoOperando,0,textoNoRes);
        }

        printf("1- INGRESE EL PRIMER OPERANDO (A=%.3f)\n",primerOperando);
        printf("2- INGRESE EL SEGUNDO OPERANDO (B=%.3f)\n",segundoOperando);
        printf("3- CALCULAR LA SUMA DE LOS DOS OPERANDOS (A+B)\n");
        printf("4- CALCULAR LA RESTA DE LOS DOS OPERANDOS (A-B)\n");
        printf("5- CALCULAR LA DIVISION (A/B)\n");
        printf("6- CALCULAR LA MULTIPLICACION (A*B)\n");
        printf("7- CALCULAR EL FACTORIAL (A!)\n");
        printf("8- CALCULAR TODAS LAS OPERACIONES\n");
        printf("9- SALIR\n");
        caracter = getch();
        printf("\nEl caracter inputado fue: %d\n", caracter);


        switch(caracter)
        {
            case 48: /* Al presionar el cero ... */

                        mensajeDefecto = 0; // Determina si se muestra el mensaje por defecto o no.
                        system("cls");
                        mostrarAlerta("Por favor selecciona una opcion valida.",primerOperando,segundoOperando,alertar,textoNoRes);

                break;
            case 49: /* Al presionar el uno */
                        mensajeDefecto = 1;

                        mostrarAlerta("Por favor ingresa el dato correspondiente al operando.",primerOperando,segundoOperando,noAlertar,textoNoRes);
                        primerOperando = inputOperator(opeChar,primerOperando,segundoOperando);

                        break;

            case 50: // Segundo operando.
                        mensajeDefecto = 1;

                        mostrarAlerta("Por favor ingresa el dato correspondiente al operando.",primerOperando,segundoOperando,noAlertar,textoNoRes);
                        segundoOperando = inputOperator(opeChar,primerOperando,segundoOperando);

                        break;
            case 51: // Suma de operandos..
                        mensajeDefecto = 0;
                        operacionRes = sumarOperandos(primerOperando, segundoOperando);
                        sprintf(textoRes, "%.3f",operacionRes);

                        mostrarAlerta("Operacion realizada correctamente.",primerOperando,segundoOperando,noAlertar,textoRes);
                        break;
            case 52: // Resta de operandos
                        mensajeDefecto = 0;
                        operacionRes = restarOperandos(primerOperando, segundoOperando);
                        sprintf(textoRes, "%.3f",operacionRes);

                        mostrarAlerta("Operacion realizada correctamente.",primerOperando,segundoOperando,noAlertar,textoRes);
                        break;
            case 53: // Division entre dos operandos.
                        mensajeDefecto = 0;
                         while(segundoOperando==0)
                        {

                            mostrarAlerta("Es imposible realizar una division con divisor 0.\nReingresa el segundo operando...",primerOperando,segundoOperando,noAlertar,"No hay resultado para mostrar");
                            printf("ERROR: Nada de caracteres raros, solo numeros, a lo sumo comas.\n"
                                   "ERROR: Ingresa nuevamente tu numero, esta vez distinto a cero: ");
                            segundoOperando = inputOperator(opeChar,primerOperando,segundoOperando);
                        }


                        operacionRes = realizarDivision(primerOperando,segundoOperando);
                        sprintf(textoRes,"%.3f",operacionRes);

                        mostrarAlerta("Operacion realizada correctamente.",primerOperando,segundoOperando,noAlertar,textoRes);



                        break;
            case 54: // Multiplicacion entre dos operandos
                        mensajeDefecto = 0;


                        operacionRes = realizarMultiplicacion(primerOperando,segundoOperando);
                        sprintf(textoRes,"%.3f",operacionRes);

                        mostrarAlerta("Operacion realizada correctamente.",primerOperando,segundoOperando,noAlertar,textoRes);
                        break;
            case 55: // Factorial del primer operando.
                        mensajeDefecto = 0;

                        while(esPositivo(primerOperando)==0)
                        {

                            mostrarAlerta("Es imposible realizar el fact() de un negativo.\nReingresa el primer operando...",primerOperando,segundoOperando,noAlertar,"No hay resultado para mostrar");
                            printf("ERROR: Nada de caracteres raros, solo numeros, a lo sumo comas.\n"
                                   "ERROR: Ingresa nuevamente tu numero, esta vez positivo: ");
                            primerOperando = inputOperator(opeChar,primerOperando,segundoOperando);
                        }

                        operacionRes = factorialDeNum(primerOperando);
                        sprintf(textoRes,"%.3f",operacionRes);
                        mostrarAlerta("Operacion realizada correctamente.",primerOperando,segundoOperando,noAlertar,textoRes);

                        break;
            case 56: // Calcular todas las operaciones.

                        mensajeDefecto = 1;

                        break;
            case 57:

                        seguir='n';

                        break;

            default:
                        mensajeDefecto = 0;

                        mostrarAlerta("Por favor selecciona una opcion valida.",primerOperando,segundoOperando,alertar,textoNoRes);
                        break;

        }

    }

    return 0;
}



