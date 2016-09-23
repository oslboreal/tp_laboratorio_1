#include <stdlib.h>
#include <stdio.h>
#include <math.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "funciones.h"

/** \brief Indica cual es el primer registro vacio (Siendo vacío 0 por convencion).
* \param Dirección de memoria del arreglo de estructura.
* \return Ubicacion del registro vacio.
*
*/

int regOff(struct datosPersonas *p, int tam)
    {
        int i;
        int ubi;
        for(i = 0; i<tam; i++)
        {

            if(p[i].idEstado=='b') // Recorro el array buscando coincidencias.
            {
                ubi = i;           // Si encuentro una coincidencia retorno la direccion del array.
                break;

            } else // De lo contrario el valor a retornar será -1.
                {
                    ubi = -1;
                }

        }


return ubi;
    }

/** \brief Formulario de carga en el primer registro vacio.
* \param Dirección de memoria del arreglo de estructura.
*
*
*/

void loadPerson(struct datosPersonas *p, int tama)
{
    // DECLARACION.
    int pos = regOff(p, tama); // Esta funcion retorna la posicion del primer registro vacio.}
    int flag = 1;
    char bande;
    int i;

    // Utilizo 3 buffers en Vez de uno solo para realizar la asignación al FINAL una vez chequeados los estados.
    char bufferN[4000]; // Buffer nombres
    char bufferE[4000]; // Buffer edad
    char bufferD[4000]; // Buffer DNI

    int estN = 0; // Estados de validacion de los campos N=Nombre - E=Edad D=DNI.
    int estE = 0; // Codigos: 1= Cargado correctamente. 0= Sin cargar -1= Error en la validacion.
    int estD = 0;
    int estAuxA = 0;
    int estAuxB = 0;




// Nombre  ------------------

while(flag==1)
{
    system("cls");
printf("       ----PUNTO DE CARGA DE PERSONAS ----\n");
printf("         [ID %d] - Cargando actualmente....\n\n", pos+1);

    printf("[1/3]Ingrese el nombre de la persona a cargar: [MINIMO 4 CARACTERES] [MAX 49] ");
    fflush(stdin);
    gets(bufferN); // Recibo el nombre


    estAuxA = validateIsName(bufferN); // Valido que cumpla con la validacion de nombre.

    if(strlen(bufferN)>=4 && strlen(bufferN) <= 49) // Valido cantidad de caracteres.
    {
        estAuxB = 1;
    }

    if(estAuxA==1 && estAuxB==1)
    {
        estN = 1; // Si las dos validaciones son positivas el estado de validacion es 1.
    }

    if(estN==1) // En funcion de la validación...
    {
        break; // El estado queda registrado para asignar al final, así que simplemente salgo del primer while.
    } else
        {
            do
            {

            printf("\nNombre invalido, desea reingresar? (S/N) \n");
            bande = tolower(getch());
            if(bande=='n') // Si el usuario responde 'n' salgo de todas las estructuras.
            {
                flag = 0; // Sale de todos los while y va directo a la evaluacion de ESTADOS.
                estN = -1; // Indico que el nombre dio error.
            } else if(bande =='s')
                {

                }

            }while(bande != 'n' && bande != 's');
        }



} //


// Edad ------------------

while(flag==1)
{
        system("cls");
printf("       ----PUNTO DE CARGA DE PERSONAS ----\n");
printf("         [ID %d] - Cargando actualmente....\n\n", pos+1);

    printf("[2/3]Ingrese la edad de la persona a cargar: [DISTINTO A CERO] [MENOR A 120 ANIOS]");
    fflush(stdin);
    gets(bufferE); // Recibo la edad

    estAuxA = validateIsNum(bufferE, 2); //  Verifico que sea un numero.
    estAuxB = validateIsPos(atoi(bufferE)); // Verifico que sea positivo.

    if(estAuxA==1 && estAuxB==1)
    {
        if(validateIsNotZero(atoi(bufferE)) && atoi(bufferE) <= 120) // Valido que sea distinto de cero y menor de 120 años (Excepcion para el usuario de Mirtha Legrand)..
        {
            estE = 1; // Si las dos validaciones son positivas el estado de validacion es 1.
        }
    }

    if(estE==1) // En funcion de la validación...
    {
        break; // El estado queda registrado para asignar al final, así que simplemente salgo del segundo while.
    } else
        {
            do
            {

            printf("\nEdad invalida, desea reingresar? (S/N) \n");
            bande = tolower(getch());
            if(bande=='n') // Si el usuario responde 'n' salgo de todas las estructuras.
            {
                flag = 0; // Sale de todos los while y va directo a la evaluacion de ESTADOS.
                estE = -1; // Indico que el nombre dio error.
            } else if(bande =='s')
                {

                }

            }while(bande != 'n' && bande != 's');
        }



} //


// DNI  ------------------

while(flag==1)
{
         system("cls");
printf("       ----PUNTO DE CARGA DE PERSONAS ----\n");
printf("         [ID %d] - Cargando actualmente....\n\n", pos+1);

    printf("[3/3]Ingrese el DNI de la persona a cargar: [7 DIGITOS MIN] [9 MAX] ");
    fflush(stdin);
    gets(bufferD); // Recibo el DNI

    estAuxA = validateIsNum(bufferD,2); // Almaceno los estados de validacion.
    estAuxB = validateIsPos(atoi(bufferD));

    if(estAuxA==1 && estAuxB==1)
    {
        if(validateIsNotZero(atoi(bufferD)) == 1 && strlen(bufferD)>6) // Valido que sea distinto de cero y tenga mas de 6 caracteres..
        {
            estD = 1; // Si las dos validaciones son positivas el estado de validacion es 1.
        }
    }


    if(estD==1) // En funcion de la validación...
    {
        break; // El estado queda registrado para asignar al final, así que simplemente salgo del primer while.
    } else
        {
            do
            {

            printf("\nDNI invalido, desea reingresar? (S/N) \n");
            bande = tolower(getch());
            if(bande=='n') // Si el usuario responde 'n' salgo de todas las estructuras.
            {
                flag = 0; // Sale de todos los while y va directo a la evaluacion de ESTADOS.
                estD = -1; // Indico que el nombre dio error.
            } else if(bande =='s')
                {

                }

            }while(bande != 'n' && bande != 's');
        }



} //

// Hora de ver los estados para saber si realizar las asignaciones o devolver mensajes de error.

if(estD == 1 && estE == 1 && estN == 1)
{
     system("cls");
printf("       ----PUNTO DE CARGA DE PERSONAS ----\n");
printf("         [ID %d] - Cargando actualmente....\n\n", pos+1);
    printf("Todos los campos fueron rellenados correctamente.\n\n Se dio de alta al usuario %s de %s anios de edad con DNI: %s.\n", bufferN, bufferE, bufferD);

         // Asignación de estados por el usuario.


         strcpy(p[pos].nombre, bufferN);

         for(i=0;i<50;i++)
         {

             if(i==0)
             {
                 p[pos].nombre[i] = toupper(p[pos].nombre[i]);
             } else
                {
                    if(p[pos].nombre[i-1] != ' ')
                     {
                         p[pos].nombre[i] = tolower(p[pos].nombre[i]);
                     }
                }
             if(p[pos].nombre[i]==' ')
             {
                 p[pos].nombre[i+1] = toupper(p[pos].nombre[i+1]);
             }
         }



         p[pos].edad = atoi(bufferE);
         p[pos].dni = atoi(bufferD);

         // Asignacion de estados automáticos.
         p[pos].idEstado = 'a';
         p[pos].idGrupo = asignarGrupo(p[pos].edad);
         p[pos].id = pos+1;

} else
    {
         system("cls");
printf("       ----PUNTO DE CARGA DE PERSONAS ----\n");
printf("         [ID %d] - Cargando actualmente....\n\n", pos+1);

        // Corroboramos que campos dieron error.
        if(estD == -1)
        {
            printf("\n[ERROR] El DNI Se cargo incorrectamente.");
        }

        if(estE == -1)
        {
            printf("\n[ERROR] La edad se cargo incorrectamente.");
        }

        if( estN == -1)
        {
            printf("\n[ERROR] El nombre se cargo incorrectamente.");
        }
        // Corroboramos que campos quedaron vacios
        if(estD == 0)
        {
            printf("\n[ERROR] El DNI nunca fue cargado..");
        }

        if(estE == 0)
        {
            printf("\n[ERROR] La edad nunca fue cargada.");
        }

        if( estN == 0)
        {
            printf("\n[ERROR] El nombre nunca fue cargado.");
        }
        printf("\n");
    }







    }

/** \brief Imprime la descripcion del grupo segun su id.
* \param Dirección de memoria del array de estructura.
* \param group Numero de identificacion del grupo.
*
*/
void printGroup(int group)
{
    if(group==1)
    {
        printf("Grupo asignado: Menor de 18 anios.");
    }
    if(group==2)
    {
        printf("Grupo asignado: Entre 19 y 35 anios.");
    }
    if(group==3)
    {
        printf("Grupo asignado: Mayor de 35 anios.");
    }
}

/** \brief Inicializa todas las personas con mi codigo de baja.
* \param Dirección de memoria del array de estructura.
* \return La cantidad de registros que fueron inicializados..
*
*/
int inicializarRegistros(struct datosPersonas *p)
{

    int i;
    int retorno = 0;
    for(i = 0; i<20 ;i++) // Recorremos el campo inicializando en 0
    {
        p[i].idEstado = 'b';
        p[i].idGrupo = 0;
        p[i].edad = 0;
        p[i].dni = 0;
    }

    for(i = 0; i<20; i++) // Recorremos nuevamente comprobando cuantos fueron inicializados para luego retornar el valor.
    {
        if(p[i].idEstado== 'b')
        {
            retorno++;
        }
    }

    return retorno;

}

/** \brief Imprime una lista de usuarios con un estado determinado.
* \param Dirección de memoria del array de estructuras.
* \param Tamapo del array a recorrer.
* \return Cantidad de registros con estado de alta encontrados.
*
*/
int printPerson(struct datosPersonas *p, int tama)
{
int i;
int cant = 0;
    for(i = 0; i < tama; i++)
{
    if(p[i].idEstado=='a') // Si el usuario posee el estado ALTA.
    {                       // Lo imprimo....
    printf("\n_________________________________________________");
    printf("\n[ID:%d] Nombre: %s\n[ID:%d]Edad: %d\n", p[i].id, p[i].nombre, p[i].id, p[i].edad);
    printf("[ID:%d] DNI: %d\n", p[i].id,p[i].dni);
    printGroup(p[i].idGrupo);
    printf("\n");
    cant++; // Si encontré algo incremento la cantidad de registros encontrados.
    }
}
    if(cant==0) // Si no detectó ningun tipo de ALTA.
    {
        printf("\nERROR: Por favor al menos de ALTA a una Persona.\n");
    }



return cant; // Retorno la cantidad de elementos encontrados.
}
/** \brief Imprime una lista de usuarios con un estado determinado.
* \param Dirección de memoria del array de estructuras.
* \param Tamapo del array a recorrer.
* \return Cantidad de registros con estado de alta encontrados.
*
*/
void printOnePerson(struct datosPersonas *p, int tama, int id)
{


    if(p[id].idEstado=='a') // Si el usuario posee el estado ALTA.
    {                       // Lo imprimo....
    printf("\n_________________________________________________");
    printf("\n[ID:%d] Nombre: %s\n[ID:%d]Edad: %d\n", p[id].id, p[id].nombre, p[id].id, p[id].edad);
    printf("[ID:%d] DNI: %d\n", p[id].id,p[id].dni);
    printGroup(p[id].idGrupo);
    printf("\n");
    }


}

/** \brief Indica cual la cantidad de registros de baja.
* \param Dirección de memoria del arreglo de estructura.
* \param Tamaño del array de estructura.
* \return Cantidad de registros..
*
*/

int regCantOff(struct datosPersonas *p, int tam)
    {
        int i;
        int ret = 0;

        for(i = 0; i<20; i++)
        {
            if(p[i].idEstado=='b') // Si al recorrer el array hay un registro vacio
            {
                ret++; // Aumenta la cant de registros vacios en 1

            }

        }


        return ret; // Retorna la cantidad.
    }

/** \brief
* \param
* \return
*
*/

int suprPerson(struct datosPersonas *p,int id, int tam)
{
    int comprobA;
    int comprobB;
    int ret = 0;
    comprobA = regCantOff(p, tam); // Cantidad de registros antes.
    p[id].idEstado = 'b';
    comprobB = regCantOff(p, tam); // Cantidad de registros despues.


    // Comprobamos si se realizó una baja. ( Antes - Despues =! 0)
    if(comprobA-comprobB!=0)
    {
        // De ser asi retorno 1.
        ret = 1;
    }

        return ret;

}

/** \brief Imprime un listado de usuarios que coincidan con un estado determinado.
* \param Array de estructuras a analizar.
* \param Caracter del estado a encontrar - Por ejemplo: 'a'
* \return Retorna la cantidad de registros encontrados - [-1] Si no encontró coincidencias.
*
*/

int printActiveUssersNameList(struct datosPersonas *p, char estado)
    {
        int i;
        int ret = 0;
        int cant = 0;

        for(i=0; i<20; i++) // Recorro el array para ver si encuentro un registro que coincida con mi estado.
        {
            if(p[i].idEstado==estado)
            {
                cant++;
                printf("[ID = %d] Nombre: %s | Edad: %d | Dni: %d\n",p[i].id,p[i].nombre,p[i].edad,p[i].dni);
            }

        }


        if(cant>0) // Si se encontró algun registro se retornará la cantidad
        {
            ret = cant;
        } else // Sino se retornará cero.
            {
                ret = cant;
            }

            return ret;
    }

/** \brief Devuelve el ID de Grupo correspondiente según el rango de edad.
* \param Int Edad a evaluar
* \return Retorna un INT con el ID del grupo.
*
*/

int asignarGrupo(int edadIngre)
{
    int ret;
    // Dependiendo de la edad de la persona asigno el grupo correspondiente.
    if(edadIngre<=18)
    {
        ret = 1; // Menores de 18 y 18 inclusive..
    } else
        {
            if(edadIngre>=19&&edadIngre<=35)
            {
                ret = 2; // Entre 19 y 35
            } else
                {
                    if(edadIngre>35)
                    {
                        ret = 3; // Mayores de 35
                    }
                }
        }

return ret; // Retorno el id correspondiente.
}

/** \brief Formulario para borrar un usuario.
* \param Arreglo de la estructura.
*
*/

void deleteUsser(struct datosPersonas *p)
    {
        int subOpcion=0;
        char flag = 'n';
        int acum = 0;
        int cantidad;

        cantidad = printActiveUssersNameList(p, 'a'); // Imprimo y obtengo todos los usuarios que tengan el estado 'a'
        printf("Cantidad de usuarios activos: %d\n", cantidad);
        if(cantidad >= 1) // Si hay usuarios activos.
                    {

                            printf("\n\nIngrese el ID de la persona a Borrar (Ingresa 0 para cancelar):");
                            fflush(stdin);
                            scanf("%d",&subOpcion); // Ingreso del ID a Borrar

                            if(p[subOpcion-1].idEstado == 'a') // Valido que el estado de la opcion elegida sea ACTIVO.
                            {
                                system("cls");
                                printOnePerson(p, 20, subOpcion-1); // Mostramos nuevamente la persona a borrar.

                                printf("Realmente te gustaria borrar a esta persona? S/N");
                                fflush(stdin);
                                flag = tolower(getch());


                            }

                            if(flag == 's')
                            {
                                acum = suprPerson(p, subOpcion-1, CANTPERS); // Si responde que quiere borrar, le damos la baja.
                            }


                            } else
                                {
                                    printf("No hay usuarios activos.\n");
                                }


                        if(acum==1) // Si suprPerson retorno uno, todo salió bien.
                        {
                            printf("\nRegistro borrado correctamente.\n");
                        } else // Si todo esta mal puede ser por dos razones (No hay personas activas o el dato es invalido).
                            {
                                if(cantidad==0) // Si no hay personas ACTIVAS.
                                {
                                    printf("\nPrimero asegurate de tener Personas cargadas.\n");
                                } else
                                    {
                                        printf("\nLa operacion fue cancelada..\n");
                                    }

                            }


    }

/** \brief Ordena alfabeticamente variables de estructura según un campo de cadena de caracteres...
 *
 * \param Estructura a trabajar.
 * \param Tamaño del array de estructuras.
 * \return Retornará: [1] Si todo salió correctamente - [0] De lo contrario.
 *
 */

 int orderPerByName(struct datosPersonas *p, int tama)
    {
        struct datosPersonas aux; // Declaro la variable de estructura aux.

        int i;
        int j;



        // Recorro una por una todas las variables comparando su campo nombre.

        for(i = 0; i < tama-1; i++) // Recorro el array
        {

            for(j=i+1; j < tama; j++) // Recorro el array pero una posición mas adelante, uso estas dos posiciones para comparar la
            {                         // Anterior con la actual (i con j).
                if(p[i].idEstado == 'a' && p[j].idEstado == 'a') // Se recorre solo si ambos campos a evaluarse son activos.
                {
                    if(strcmp(p[i].nombre, p[j].nombre)>0) // Criterio a utilizar.
                    {
                        aux = p[i]; // Swap de estructuras.
                        p[i] = p[j];
                        p[j] = aux;
                    }
                }
            }

        }


        // Asigno para comparar despues antes de swapear.



        return 1;
    }

/** \brief Genera un grafico estadistico de los Grupos en funcion de la cantidad de usuarios activos.
 *
 * \param Estructura a trabajar.
 * \param Tamaño del array de estructuras.
 */

 void groupGraph(struct datosPersonas *p, int tama)
 {
     int primerG = 0; // Arrays paralelos que cuentan la cantidad de personas que hay por cada  grupo.
     int segunG = 0;
     int tercerG = 0;
int i; // Contador




     for(i = 0; i < tama; i++) // Chequea la cantidad de personas que tiene asignada cada grupo.
     {
         if(p[i].idGrupo==1)
         {
             primerG++;
         }
         if(p[i].idGrupo==2)
         {
             segunG++;
         }
         if(p[i].idGrupo==3)
         {
             tercerG++;
         }
     }
printf("_______________ Grafico estadistico ________________");
        for(i = 20; i > 0; i--)
        {
            if(primerG>=i)
            {
                printf(" * ");
                printf("  ");
            }

            if(segunG>=i)
            {
                printf(" * ");
                printf("  ");
            }

            if(tercerG>=i)
            {
                printf(" * ");
                printf("  ");
            }
            printf("\n");
        }
        printf("<18 19-35 >35\n");



 }
