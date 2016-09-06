#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include "funciones.h"

/*
/   Bibliotecas de validación - Juan Marcos Vallejo
/   Universidad Nacional Tenológica.
*/


/** \brief Valida mediante cadena de caracteres si el numero ingresado es numero y si es entero o flotante.
 *
 * \param Numero a evaluar en cadena de caracteres.
 * \param Tipo de dato [1] Flotante [2] Entero.
 * \return [1] Si la cadena ingresada es un numero del tipo especificado - [0] Si la cadena ingresada no es un numero del tipo especificado.
 *
 */
        int validateIsNum(char num[100], int tipo)
        {
                    char tipoElegido;
                    int operacion;
                    int i;
                    int acumNum = 0;
                    int longitd = 0;

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


                    for(i = 0;i!=longitd;i++)
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
                        if(acumNum!=longitd)
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


/** \brief Indica si un numero entero es positivo.
*
* \param Entero a evaluar
* \return 1 Si el entero es positivo. - 0 Si el numero es negativo.
*
*/

        int esPositivo(int x)
        {
           int positivo;
           positivo = 0;
            if(x>=0)
            {
                 positivo = 1;
            }
            return positivo;

        }
