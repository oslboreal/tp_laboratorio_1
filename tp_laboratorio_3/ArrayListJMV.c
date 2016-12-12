#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArrayListJMV.h"

// funciones privadas
int resizeUp(ArrayList* pList);
int expand(ArrayList* pList,int index);
int contract(ArrayList* pList,int index);

#define AL_INCREMENT      10
#define AL_INITIAL_VALUE  10
//___________________

/** \brief Allocate a new arrayList with AL_INITIAL_VALUE elements.
 * \param void
 * \return ArrayList* Return (NULL) if Error [if can't allocate memory]
 *                  - (pointer to new arrayList) if ok
 */
ArrayList* al_newArrayList(void)
{
    ArrayList* pList;
    ArrayList* returnAux = NULL;
    void* pElements;
    pList=(ArrayList *)malloc(sizeof(ArrayList));

    if(pList != NULL)
    {
        pElements = malloc(sizeof(void *)*AL_INITIAL_VALUE );
        if(pElements != NULL)
        {
            pList->size=0;
            pList->pElements=pElements;
            pList->reservedSize=AL_INITIAL_VALUE;
            returnAux = pList;
        }
        else
        {
            free(pList);
        }
    }

    return returnAux;
}


/** \brief  Add an element to arrayList and if is
 *          nessesary resize the array
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (0) if Ok
 *
 */
int al_add(ArrayList* pList,void* pElement)
{

    int returnAux = -1;

            if(resizeUp(pList) == -1) // Validamos que este todo bien con el espacio en memoria.
            {
                returnAux = -1;

            } else
                {
                    pList->pElements[pList->size] = pElement;
                    pList->size++;
                    returnAux = 0;
                }
return returnAux;
}

/** \brief  Delete arrayList
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Ok
 *
 */
int al_deleteArrayList(ArrayList* pList)
{
    int returnAux = -1;

    if(pList != NULL)
    {
        free(pList->pElements); // Libero memoria en función del constructor.
        free(pList);
        returnAux = 0;
    }

    return returnAux;
}

/** \brief  Array LEN.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return length of array or (-1) if Error [pList is NULL pointer]
 *
 */
int al_len(ArrayList* pList)
{
    int returnAux = -1;

    if(pList != NULL)
    {
        returnAux = pList->size;
    }

    return returnAux;
}


/** \brief  Get an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return void* Return (NULL) if Error [pList is NULL pointer or invalid index] - (Pointer to element) if Ok
 *
 */
void* al_get(ArrayList* pList , int index)
{
    void* returnAux = NULL;

    if(pList != NULL && (index < al_len(pList) && index >= 0))
    {
        if(index < pList->size && index >= 0) // Chequeamos que sea un elemento existente.
        {
            returnAux = pList->pElements[index];
        }
    }

    return returnAux;
}


/** \brief  Find if pList contains at least one element pElement
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer]
 *                  - ( 0) if Ok but not found a element
 *                  - ( 1) if this list contains at least one element pElement
 *
 */
int al_contains(ArrayList* pList, void* pElement)
{
    int returnAux = -1;
    int i;
    if(pList != NULL && pElement != NULL)
    {
        returnAux = 0;
        for(i=0; i < pList->size; i++)
        {
            if(pList->pElements[i] == pElement)
            {
                returnAux = 1;
                break;
            }
        }

    } else
        {
            returnAux = -1; // Error, el puntero no apunta a ningun lado.
        }

    return returnAux;
}


/** \brief  Set a element in pList at index position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 *
 */
int al_set(ArrayList* pList, int index,void* pElement)
{
    int returnAux = -1;

    if(pList != NULL && pElement != NULL && index >= 0)
    {
        if(index<pList->size)
        {
            pList->pElements[index] = pElement;
            returnAux = 0;

        } else
            {
                returnAux = -1;
            }
    }

    return returnAux;
}


/** \brief  Remove an element by index
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_remove(ArrayList* pList,int index)
{
    int returnAux = -1;
    int check;

    if(pList != NULL && index >= 0 && index < pList->size)
    {
            check = contract(pList, index);
            if(check == -1)
            {
                printf("[ERROR] Error al contraer.");
            } else
                {
                    returnAux = 0;
                }
    } else
        {
            returnAux = -1;
        }

    return returnAux;
}



/** \brief Removes all of the elements from this list
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer]
 *                  - ( 0) if Ok
 */
int al_clear(ArrayList* pList)
{
    int returnAux = 0;

    if(pList!=NULL)
    {
        pList->size = 0;
        // Llamar a resize DOWN. -> Vuelve a la posición inicial.
        returnAux = 0;
    } else
        {
            returnAux = -1;
        }

    return returnAux;
}



/** \brief Returns an array containing all of the elements in this list in proper sequence
 * \param pList ArrayList* Pointer to arrayList
 * \return ArrayList* Return  (NULL) if Error [pList is NULL pointer]
 *                          - (New array) if Ok
 */
ArrayList* al_clone(ArrayList* pList)
{
    ArrayList* returnAux = NULL;
    int i;
    void *auxiliar;

    if(pList != NULL)
    {
        returnAux = al_newArrayList();
        for(i=0; i < pList->size; i++)
        {
            auxiliar = al_get(pList, i);
            al_add(returnAux, auxiliar);
        }
    }

    return returnAux;
}




/** \brief Inserts the element at the specified position
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int al_push(ArrayList* pList, int index, void* pElement)
{
    int returnAux = -1;
    if(pList != NULL && pElement != NULL && index >= 0 && index <= pList->size) // Validamos los punteros.
    {
        if(index==pList->size) // Chequeamos si realmente es necesario expandir.
        {
            pList->pElements[index] = pElement;
            pList->size = pList->size + 1;
            returnAux = 0;
        } else // Sino.
            {
                if(expand(pList, index) == 0) // Si logramos expandir.
                { // Asignamos.
                pList->pElements[index] = pElement;
                pList->size = pList->size + 1;
                returnAux = 0;
                }
            }
    }
    return returnAux;
}



/** \brief Returns the index of the first occurrence of the specified element
 * \param pList ArrayList* Pointer to arrayList
 * \param pElement void* Pointer to element
 * \return int Return (-1) if Error [pList or pElement are NULL pointer] - (index to element) if Ok
 */
int al_indexOf(ArrayList* pList, void* pElement)
{
    int i ;
    int returnAux = -1;
    if(pList != NULL && pElement != NULL)
    {
        for(i=0; i<pList->size; i++)
        {
            if(pList->pElements[i] == pElement)
            {
                returnAux = i;
                break;
            }
        }
    }

    return returnAux;
}



/** \brief Returns true if this list contains no elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer] - (0) if Not Empty - (1) if is Empty
 */
int al_isEmpty(ArrayList* pList)
{
    int returnAux = -1;

    if(pList!=NULL) // Si no es nulo
    {// Evaluamos
        if(pList->size == 0) // Si es igual a 0 retornamos un uno.
        {
            returnAux = 1;
        } else // Sino un cero.
            {
                returnAux = 0;
            }
    }

    return returnAux;
}




/** \brief Remove the item at the given position in the list, and return it.
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid index]
 *                  - ( element pointer) if Ok
 */
void* al_pop(ArrayList* pList,int index)
{
    void* returnAux = NULL;

    if(pList!=NULL && index >= 0 && index <= pList->size) // Valido.
    {
        returnAux = pList->pElements[index]; // Devuelvo la direccion de memoria.
        al_remove(pList, index);
    }

    return returnAux;
}


/** \brief Returns a new arrayList with a portion of pList between the specified
 *         fromIndex, inclusive, and toIndex, exclusive.
 * \param pList ArrayList* Pointer to arrayList
 * \param from int Initial index of the element (inclusive)
 * \param to int Final index of the element (exclusive)
 * \return int Return (NULL) if Error [pList is NULL pointer or invalid 'from' or invalid 'to']
 *                  - ( pointer to new array) if Ok
 */
ArrayList* al_subList(ArrayList* pList,int from,int to)
{
    ArrayList* returnAux = NULL;
    int i;
    if(pList != NULL && from >= 0 && from <= pList->size && to >= 0 && to <= pList->size)
    {
        if(!(from > to)) // Si from no es mayor que tu
        {
            returnAux = al_newArrayList();
            for(i=from; i<to; i++)
            {
                al_add(returnAux, pList->pElements[i]);
            }
        }else
            {
                returnAux = NULL;
            }
    }


    return returnAux ;
}





/** \brief Returns true if pList list contains all of the elements of pList2
 * \param pList ArrayList* Pointer to arrayList
 * \param pList2 ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList or pList2 are NULL pointer]
 *                  - (0) if Not contains All - (1) if is contains All
 */
int al_containsAll(ArrayList* pList,ArrayList* pList2)
{
    int returnAux = -1;
    int i;
    int coinciden = 0;
    if(pList2 != NULL && pList != NULL)
    {
        returnAux = 0;
        if(al_len(pList) >= al_len(pList2)) // Chequeamos que el segundo Al no sea mayor que el primero, de modo que se puedan contener todos.
        {
            for(i = 0; i < pList->size; i++)
            {
                if(al_contains(pList, pList2->pElements[i]))
                {
                    coinciden = coinciden +1;
                }
            }

            if(coinciden == al_len(pList2))
            {
                returnAux = 1;
            }
        }

    }

    return returnAux;
}

/** \brief Sorts objects of list, use compare pFunc
 * \param pList ArrayList* Pointer to arrayList
 * \param pFunc (*pFunc) Pointer to fuction to compare elements of arrayList
 * \param order int  [1] indicate UP - [0] indicate DOWN
 * \return int Return (-1) if Error [pList or pFunc are NULL pointer]
 *                  - (0) if ok
 */
int al_sort(ArrayList* pList, int (*pFunc)(void* ,void*), int order)
{
    int returnAux = -1;
    void *aux;
    aux = malloc(sizeof(void *));
    int i,j;

    if(pList != NULL && pFunc != NULL)
    {
        if(order == 1 || order == 0)
        {
                for(i=0; i < pList->size-1; i++)
                {
                    for(j=i+1; j < pList->size; j++)
                    {

                        if(order == 1)
                        {
                            if(pFunc(pList->pElements[i], pList->pElements[j]) == 1) // Evaluamos si es mayor.
                            {
                                aux = pList->pElements[i];
                                pList->pElements[i] = pList->pElements[j];
                                pList->pElements[j] = aux;
                            }

                        }
                        if(order == 0)
                        {
                            if(pFunc(pList->pElements[i], pList->pElements[j]) == -1) // Evaluamos si es menor.
                            {
                                aux = pList->pElements[i];
                                pList->pElements[i] = pList->pElements[j];
                                pList->pElements[j] = aux;

                        }
                        // Si es igual a cero son iguales, de modo que no hacemos nada.

                        }
                        returnAux = 0;
                }


        }
    }



}
return returnAux;
}


/** \brief Increment the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeUp(ArrayList* pList)
{
    int returnAux = -1;
    void* pAux;

    if(pList!=NULL)
    {
        if(pList->size == pList->reservedSize)
        {
            pAux = realloc(pList->pElements, sizeof(void *)*(pList->size + AL_INCREMENT));
            if(pAux != NULL)
            {
                pList->reservedSize = pList->reservedSize + AL_INCREMENT;
                pList->pElements = pAux;
                returnAux = 0;

            }
        } else
            {
                returnAux = 0;
            }




         // Libero la memoria de el puntero auxiiar.
    }

    return returnAux;

}

/** \brief Decrement the number of elements in pList in AL_INCREMENT elements.
 * \param pList ArrayList* Pointer to arrayList
 * \return int Return (-1) if Error [pList is NULL pointer or if can't allocate memory]
 *                  - (0) if ok
 */
int resizeDown(ArrayList* pList)
{
    int returnAux = -1;
    void* pAux;

    if(pList!=NULL) // Confirmamos que el puntero apunte a algún lado.
    {
        if(pList->size < pList->reservedSize - AL_INCREMENT) // Si el tamaño es menor a el tamaño reservado menos AL_INCREMENT, Restamos ese espacio.
        {
            pAux = realloc(pList->pElements, (sizeof(void *)* pList->reservedSize) - (sizeof(void*) * AL_INCREMENT));
            if(pAux != NULL)
            {

                pList->pElements = pAux; // Asigno el nuevo espacio en memoria.
                pList->reservedSize = pList->reservedSize - AL_INCREMENT;
                returnAux = 0;

            }
        } else
            {
                returnAux = 0;
            }




         // Libero la memoria de el puntero auxiiar.
    }

    return returnAux;

}


/** \brief  Expand an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int expand(ArrayList* pList,int index)
{
    int i;
    int returnAux = -1;
if(pList != NULL && index >= 0 && index <= pList->size) // Chequeamos que los siguientes punteros apunten a un espacio en memoria.
{
    if(resizeUp(pList) != -1) // Nos aseguramos de disponer de espacio de memoria antes de expandir.
    {
            for(i=pList->size; i >= index; i--)
            {
                pList->pElements[i+1] = pList->pElements[i];
            }
            returnAux = 0;
    }
}

    return returnAux;
}

/** \brief  Contract an array list
 * \param pList ArrayList* Pointer to arrayList
 * \param index int Index of the element
 * \return int Return (-1) if Error [pList is NULL pointer or invalid index]
 *                  - ( 0) if Ok
 */
int contract(ArrayList* pList,int index)
{
    int returnAux = -1;

    int i;

    if(pList != NULL && index >= 0 && index < pList->size) // Chequeamos que los siguientes punteros apunten a un espacio en memoria.
    {
            for(i=index + 1; i < pList->size; i++)
            {
                pList->pElements[i-1] = pList->pElements[i];
            }
            // Luego de realizar el algoritmo contract chequeamos si podemos liberar algo de memoria.
            pList->size--;
            resizeDown(pList);
            returnAux = 0;
    }
    return returnAux;
}

/** \brief Retorna el espacio reservado en memoria.
 *
 * \param ArrayList* puntero a el array list a retornar el espacio.
 * \return int Cantidad de bytes reservado en memoria. - [-1] En caso de error.
 *
 */

 int al_reservedBytes(ArrayList* pList)
 {
     int returnAux = -1;
     if(pList != NULL)
     {
        returnAux = sizeof(void *) * pList->reservedSize;
     }

     return returnAux;
 }

