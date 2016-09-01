
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include "funciones.h"


/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

float sumarOperandos(float x,float y)
{

    float resultado = x + y;
    return resultado;
}
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

float restarOperandos(float x, float y)
    {
        float resultado = x - y;
        return resultado;
    }
/** \brief
 *
 * \param
 * \param
 * \return
 *
 */

float realizarDivision(float primerValor, float segundoValor)
    {
        float resultado = primerValor / segundoValor;


        return resultado;

    }

    /** \brief
     *
     * \param
     * \param
     * \return
     *
     */
float realizarMultiplicacion(float primerValor, float segundoValor)
    {
        float result = primerValor*segundoValor;
        return result;
    }



     /** \brief
      *
      * \param
      * \param
      * \return
      *
      */


    void mostrarAlerta(char mensaje[100],float primerValor, float segundoValor,int importante, char resultado[100])
        {
            system("cls");
            if(importante==0)
            {
                printf("______________________CONSOLA DE INFORMACION____________________\n\n");
                printf(mensaje);
                printf("\n\nPrimer operando:%.3f\n",primerValor);
                printf("Segun. operando:%.3f\n",segundoValor);
                if(resultado)
            {
                printf("\nEl resultado es: %s", resultado);
            }
                printf("\n________________________________________________________________\n\n");
            } else if(importante==1)
                {
                printf("______________________CONSOLA DE INFORMACION____________________\n\nATENCION: ");
                printf(mensaje);
                printf("\n\nPrimer operando:%.3f\n",primerValor);
                printf("Segun. operando:%.3f\n",segundoValor);
                if(resultado)
            {
                printf("\nEl resultado es: %s", resultado);
            }
                printf("\n________________________________________________________________\n\n\a");
                }





        }


   /** \brief
    *
    * \param
    * \param
    * \return
    *
    */


    float factorialDeNum(int n)
            {
                float acum = n;
                int resultado;

                int i;
                if(n==0)
                {
                  resultado = 1;
                }
                else if(n<0)
                {
                    resultado = -1;
                } else
                    {
                        for(i = n-1;i!=0;i--)
                    {
                        acum = acum * i;


                    }
                    resultado = acum;
                    }

                    return resultado;

                }



/** \brief
 *
 * \param
 * \param
 * \return
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

/** \brief
                 *
* \param
* \param
* \return
*
*/

                float inputOperator(char operandoValidar[50], float primerOperandoActual, float segundoOperandoActual)
                {
                     float operando;
                     scanf("%s",operandoValidar);

                        while(validateIsNum(operandoValidar,1)==0)
                        {

                            system("cls");
                             mostrarAlerta("Por favor ingresa el dato correspondiente al operando.",primerOperandoActual,segundoOperandoActual,1,"No hay resultado para mostrar.");

                            printf("ERROR: Nada de caracteres raros, solo numeros, a lo sumo comas.\n"
                                   "ERROR: Ingresa nuevamente tu numero: ");

                            scanf("%s",operandoValidar);
                        }
                        operando = atof(operandoValidar);
                        return operando;
                }


/** \brief
*
* \param
* \param
* \return
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


