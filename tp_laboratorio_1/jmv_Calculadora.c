
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <strings.h>
#include "funciones.h"


/** \brief Realiza la suma entre dos operandos.
 *
 * \param Numero a sumar.
 * \param Segundo numero a sumar.
 * \return El resultado de la sumatoria entre los dos operandos.
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



     /** \brief Muestra la bitacora de mensajes de la calculadora, imprimiendo datos básicos y notificaciones al usuario.
      *
      * \param Mensaje a mostrarle al usuario.
      * \param Primer operando cargado actualmente en la calculadora.
      * \param Segundo operando cargado actualmente en la calculadora.
      * \param [1] Si el mensaje es importante - [0] Si el mensaje no es importante.
      * \param Cadena de caracteres con el resultado de la operación.
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


   /** \brief Retorna el factorial de un numero.
    *
    * \param Numero entero positivo a calcular.
    * \return El resultado de la operacion.
    */

    long factorialDeNum(int n)
            {
                long int acum = n;
                long int resultado;

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



/** \brief Pide una numero en cadena de caracteres, lo valida y luego retorna el valor flotante para poder operar con el.
*
* \param Cadena de carateres a validar - Debe ser un numero.
* \param Primer operando cargado actualmente en la calculadora.
* \param Segundo operando cargado actualmente en la calculadora.
* \return La cadena de caracteres convertida en flotante.
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


/** \brief Imprime el resultado de todas las operaciones que puede realizar nuestra  calculadora.
*
* \param Primer operando cargado actualmente en la calculadora.
* \param Segundo operanmdo cargado actualmente en la calculadora.
*
*/

void allOperations(float primerValor, float segundoValor)
{
    float valor;
    char resultado[100];


    // Primer operacion.
    valor = sumarOperandos(primerValor, segundoValor);
    sprintf(resultado,"%.3f",valor);
    printf("\nLa suma entre los operandos es %s\n",resultado);
    fflush(stdin);

    valor = realizarMultiplicacion(primerValor, segundoValor);
    sprintf(resultado,"%.3f",valor);
    printf("\nLa multiplicacion entre los operandos es %s\n",resultado);
    fflush(stdin);

    if(segundoValor==0)
    {
        printf("\nError: Imposible realizar la division por cero.\n");

    } else
        {
    valor = realizarDivision(primerValor, segundoValor);
    sprintf(resultado,"%.3f",valor);
    printf("\nLa division entre los operandos es %s\n",resultado);
    fflush(stdin);
        }


    valor = restarOperandos(primerValor, segundoValor);
    sprintf(resultado,"%.3f",valor);
    printf("\nLa resta entre los operandos es %s\n",resultado);
    fflush(stdin);

    valor = factorialDeNum(primerValor);
    sprintf(resultado,"%.3f",valor);
    printf("\nEl factorial del primer operando es %s\n\n",resultado);
    fflush(stdin);
}



