#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

// //
// Bibliotecas de validaciones.
// Juan Marcos Vallejo
// //

/** \brief Indica si una cadena de caracteres cumple con los requisitos para ser una edad.
 *
 * \param Cadena de caracteres que contiene la edad ingresada.
 * \return [1] Si la cadena ingresada cumple con los requisitos - [0] Si la cadena ingresada la edad no es válida.
 *
 */
        int validateIsAge(char num[])
        {

                    int operacion;
                    int edad;
                    int i;
                    int acumNum = 0;
                    int longitd = 0;


                    longitd = strlen(num);

                    for(i = 0;i!=longitd;i++)
                    {


                        if(num[i]=='1' || num[i]=='2' || num[i]=='3' || num[i]=='4'
                           || num[i]=='5'  || num[i]=='6'  || num[i]=='7'  || num[i]=='8'  || num[i]=='9'  || num[i]=='0')
                        {
                            acumNum ++;
                        }
                     }
                     edad = atoi(num);
                        if(acumNum!=longitd) // Chequeo que la cantidad de caracteres acumulados sea igual a la long del arreglo
                        {                      // Tengase en cuenta que solo registrará caracteres que sean números.
                            operacion = 0;      // Por lo tanto si hay alguna diferencia es por que algún caracter no es numero
                        } else                     // De modo que retornará cero.
                        {
                            if(edad<=0 || edad>= 130)
                                {
                                operacion = 0;
                                } else
                                    {
                                        operacion = 1;
                                    }

                        }


                        /* Retornado 1 todos los caracteres son numeros */
                        /* Retornado 0 no todos los caracteres son numeros. . */
                        return operacion;


       }

/** \brief Sirve para validar si una cadena de caracteres cumple con las condiciones para ser un nombre.
 *
 * \param Un array de caracteres
 * \return Return [1] Si es un nombre valido o [0] Si no es un nombre valido.
 *
 */

 int validateIsName(char name[])
     {

                    int operacion;
                    int i;
                    int longitd = 0;
                    int acumNum = 0;


                    // Calculo el tamaño del arreglo.
                    longitd = strlen(name);


                    // Recorro el arreglo.
                    for(i = 0;i!=longitd;i++)
                    {

                        // Chequeo minusculas.
                        if(name[i]==' ' || name[i]=='a' || name[i]=='b' || name[i]=='c' || name[i]=='d'  || name[i]=='e' || name[i]=='f'  || name[i]=='g' || name[i]=='h'
                            || name[i]=='i' || name[i]=='j' || name[i]=='k' || name[i]=='l' || name[i]=='m' || name[i]=='n' || name[i]=='o' || name[i]=='p' || name[i]=='q' || name[i]=='r' || name[i]=='s' || name[i]=='t'
                             || name[i]=='u' || name[i]=='v' || name[i]=='w' || name[i]=='x' || name[i]=='y' || name[i]=='z' || name[i]=='ñ')
                        {
                            acumNum ++; // Si coincido incremento para luego comprar.
                        }

                        // Chequeo mayusculas.
                        if(name[i]=='A' || name[i]=='B' || name[i]=='C' || name[i]=='D'  || name[i]=='E' || name[i]=='F'  || name[i]=='G' || name[i]=='H'
                            || name[i]=='I' || name[i]=='J' || name[i]=='K' || name[i]=='L' || name[i]=='M' || name[i]=='N' || name[i]=='O' || name[i]=='P' || name[i]=='Q' || name[i]=='R' || name[i]=='S' || name[i]=='T'
                             || name[i]=='U' || name[i]=='V' || name[i]=='W' || name[i]=='X' || name[i]=='Y' || name[i]=='Z' || name[i]=='Ñ')
                        {
                            acumNum ++; // Si coincide incremento para luego comprar.
                        }
                     }


                        // Si el acumulador es distinto a la longitud es por que en alguno de los indices del array
                        // no se cumplieron las condiciones de arriba, ´por lo tanto no son letras o los caracteres permitidos
                        // por lo tanto no es un nombre.

                        if(acumNum!=longitd)
                        {
                            operacion = 0;
                        } else
                        {
                            operacion = 1;
                        }


        return operacion;
     }

/** \brief Indica si una cadena de caracteres cumple con los requisitos para ser un telefono.
 *
 * \param Numero a evaluar en cadena de caracteres.
 * \param Cadena de caracteres.
 * \return [1] Si la cadena ingresada cumple con los requisitos - [0] Si la cadena ingresada no puede es un teléfono válido.
 *
 */
        int validateIsTel(char num[])
        {

                    int operacion;
                    int i;
                    int acumNum = 0;
                    int longitd = 0;


                    longitd = strlen(num);

                    for(i = 0;i!=longitd;i++)
                    {


                        if(num[i]=='#'  || num[i]=='*'  || num[i]=='+'  || num[i]=='-' || num[i]=='.' || num[i]=='1' || num[i]=='2' || num[i]=='3' || num[i]=='4'
                           || num[i]=='5'  || num[i]=='6'  || num[i]=='7'  || num[i]=='8'  || num[i]=='9'  || num[i]=='0')
                        {
                            acumNum ++; // Si coincide incremento par luego comparar.
                        } else
                            {
                                acumNum--; // Si no coincide resto para generar una diferencia.
                            }
                     }
                        if(acumNum!=longitd) // COmparo la cantidad de caracteres registrados con la longitud.
                        {                   // Si no coinciden es por que se generó una diferencia, por lo tanto no cumplica con
                            operacion = 0;  // Las condiciones de arriba, por lo tanto no es un teléfono válido.
                        } else
                        {
                            operacion = 1;
                        }


                        /* Retornado 1 todos los caracteres son numeros de telefono*/
                        /* Retornado 0 no todos los caracteres son numeros de telefono.. . */
                        return operacion;


       }

/** \brief Indica si un numero entero es positivo.
*
* \param Entero a evaluar
* \return 1 Si el entero es positivo. - 0 Si el numero es negativo.
*
*/

        int validateIsPos(int x)
        {
           int positivo;
           positivo = 0;
            if(x>=0) // Si x es mayor o igual que cero es positivo.
            {
                 positivo = 1;
            }
            return positivo; // Retorno 1 si se cumple la condicion.

        }

/** \brief Valida mediante cadena de caracteres si el numero ingresado es numero y si es entero o flotante.
 *
 * \param Numero a evaluar en cadena de caracteres.
 * \param Tipo de dato [1] Flotante [2] Entero.
 * \return [1] Si la cadena ingresada es un numero del tipo especificado - [0] Si la cadena ingresada no es un numero del tipo especificado.
 *
 */
        int validateIsNum(char num[], int tipo)
        {

                    char tipoElegido;
                    int operacion;
                    int i;
                    int acumNum = 0;
                    int longitd = 0;
                    // Indico el tipo de numero que voy a evaluar. (Tener en cuenta que los flotantes usan coma decimal)
                    if(tipo==1) // FLOAT
                    {
                        tipoElegido = 'F';
                    } else if(tipo==2) // INTEGER
                    {
                        tipoElegido = 'I';
                    } else // En el caso de que el tipo sea incorrecto.
                        {
                            return -1;
                        }

                    longitd = strlen(num);

        if(tipoElegido == 'F')
        {


                    for(i = 0;i!=longitd;i++) // Recorro todas las posiciones del array comparando para ver si todos son numeros
                    {


                        if(num[i]=='-' || num[i]=='.' || num[i]=='1' || num[i]=='2' || num[i]=='3' || num[i]=='4'
                           || num[i]=='5'  || num[i]=='6'  || num[i]=='7'  || num[i]=='8'  || num[i]=='9'  || num[i]=='0')
                        {
                            acumNum ++;
                        }
                     }
                        if(acumNum!=longitd)
                        {
                            operacion = 0;
                        } else
                        {
                            operacion = 1;
                        }

        }

        if(tipoElegido == 'I') // Lo mismo pero no permite coma decimal.
        {
            for(i = 0;i!=longitd;i++)
                    {


                        if(num[i]=='-' || num[i]=='1' || num[i]=='2' || num[i]=='3' || num[i]=='4'
                           || num[i]=='5'  || num[i]=='6'  || num[i]=='7'  || num[i]=='8'  || num[i]=='9'  || num[i]=='0')
                        {
                            acumNum ++;
                        }
                     }
                        if(acumNum!=longitd) // Si la cantidad de numeros validados coincide con la cant de caracteres
                        {                      // Significa que todos los numeros ingresados son válidos.
                            operacion = 0;
                        } else
                        {
                            operacion = 1;
                        }
        }

                        /* Retornado 1 todos los caracteres son numeros */
                        /* Retornado 0 no todos los caracteres son numeros. . */
                        return operacion;


       }


/** \brief Valida mediante un entero que el numero sea distinto de cero
 *
 * \param Entero a evaluar.

 * \return [1] Si el numero no es cero - [0] Si el numero es cero.
 *
 */

         int validateIsNotZero(int x)
        {
           int positivo;
           positivo = 0;
            if(x!=0) // Si x es distinto de cero retorno uno.
            {
                 positivo = 1;
            }
            return positivo;

        }
