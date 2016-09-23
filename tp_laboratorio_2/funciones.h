#ifndef FUNCIONES_H_INCLUDED
#define FUNCIONES_H_INCLUDED
#define CANTPERS 20

struct datosPersonas{

    int id;
    char nombre[50];
    int edad;
    char idEstado;
    int dni;
    int idGrupo;

};


/**
 * Obtiene el primer indice libre del array.
 * @param lista el array se pasa como parametro.
 * @return el primer indice disponible
 */
        int regOff(struct datosPersonas *p, int tam);



/**
 * Formulario de carga de persona.
  * @param Arreglo de la estructura a trabajar..
   * @param Tamaño del arreglo de estructura.
 */

    void loadPerson(struct datosPersonas *p, int tama);

/**
 * Muestra según el Id ingresado el grupo correspondiente.
  * @param Id del grupo.
 */

    void printGroup(int group);

/**
 * Inicializa todos los estados de las personas en "BAJA" y ademas limpia algunos campos.
 * @param Variable de la estructura a trabajar..
 * @return Retorna en tipo entero la cantidad de registros inicializados.
 */

    int inicializarRegistros(struct datosPersonas *p);

/** \brief Imprime una lista de usuarios con estado ALTA
* \param Dirección de memoria del array de estructuras.
* \param Tamapo del array a recorrer.
* \return Cantidad de registros con estado de alta encontrados.
*
*/
    int printPerson(struct datosPersonas *p, int tama);

/** \brief Realiza una baja dentro de la el arreglo de estructuras
* \param Arreglo a modificar
* \param Id del usuario a borrar.
* \param Tamaño del arreglo
* \return
*
*/
    int suprPerson(struct datosPersonas *p,int id, int tam);
/** \brief Indica la cantidad de registros de baja.
* \param Dirección de memoria del arreglo de estructura.
* \param Tamaño del array de estructura.
* \return Cantidad de registros..
*
*/
    int regCantOff(struct datosPersonas *p, int tam);
/** \brief Imprime la lista de usuarios según el estado ingresado como segundo parametro.
* \param Arreglo de la estructura.
* \param Caractere que identifica el estado..
* \return La cantidad de registros encontrados con el criterio indicado.
*
*/
    int printActiveUssersNameList(struct datosPersonas *p, char estado);
/** \brief Sirve para validar si una cadena de caracteres cumple con las condiciones para ser un nombre.
 *
 * \param Un array de caracteres
 * \return Return [1] Si es un nombre valido o [0] Si no es un nombre valido.
 *
 */
    int validateIsName(char name[]);
/** \brief Valida mediante cadena de caracteres si el numero ingresado es numero y si es entero o flotante.
 *
 * \param Numero a evaluar en cadena de caracteres.
 * \param Tipo de dato [1] Flotante [2] Entero.
 * \return [1] Si la cadena ingresada es un numero del tipo especificado - [0] Si la cadena ingresada no es un numero del tipo especificado.
 *
 */
    int validateIsNum(char num[], int tipo);
/** \brief Indica si un numero entero es positivo.
*
* \param Entero a evaluar
* \return 1 Si el entero es positivo. - 0 Si el numero es negativo.
*
*/
int validateIsPos(int x);
 /** \brief Retorna el valor del ID del grupo que corresponde según la edad ingresada
* \param Edad de la persona
* \return ID del grupo [<18 = 1 | 19><35 = 2 | >35 = 3]
*
*/
int asignarGrupo(int edadIngre);

/** \brief Formulario para borrar un usuario.
* \param Arreglo de la estructura.
*
*/

    void deleteUsser(struct datosPersonas *p);

/** \brief Ordena alfabeticamente variables de estructura según un campo de cadena de caracteres...
 *
 * \param Estructura a trabajar.
 * \param Tamaño del array de estructuras.
 * \return Retornará: [1] Si todo salió correctamente - [0] De lo contrario.
 *
 */

     int orderPerByName(struct datosPersonas *p, int tama);

 /** \brief Valida mediante un entero que el numero sea distinto de cero
 *
 * \param Entero a evaluar.

 * \return [1] Si el numero no es cero - [0] Si el numero es cero.
 *
 */

    int validateIsNotZero(int x);

/** \brief Imprime una lista de usuarios con un estado determinado.
* \param Dirección de memoria del array de estructuras.
* \param Tamapo del array a recorrer.
* \return Cantidad de registros con estado de alta encontrados.
*
*/
    void printOnePerson(struct datosPersonas *p, int tama, int id);

/** \brief Genera un grafico estadistico de los Grupos en funcion de la cantidad de usuarios activos.
 *
 * \param Estructura a trabajar.
 * \param Tamaño del array de estructuras.
 */

     void groupGraph(struct datosPersonas *p, int tama);

#endif // FUNCIONES_H_INCLUDED
