#include <stdio.h>
#include <string.h>
#include <stdlib.h>

/** \brief Muestra el menu principal y pide una opcion
 *
 * \param void
 * \return int:Retorna una opcion
 *
 */
int UserMenue(void);
/** \brief Pide un numero flotante y lo valida
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param float: Minimo rango
 * \param float:Maximo rango
 * \return float:Entrega un flotante validado dentro de un rango
 *
 */
float GetFloat(char message[], char errorMessage[], float, float);
/** \brief Valida que el array ingresado sea un flotante
 *
 * \param charArray[] char
 * \return int:Retorna 1 si esta bien, 0 si esta mal
 *
 */
int IsAnfloatNumber(char charArray[]);
/** \brief Recibe una cadena de caracteres, solicita que los datos ingresados sean de este tipo y valida que todos sus caracteres sean letras y devuelve por referencia
 *
 * \param charArray[] char
 * \param message[] char
 * \param errorMessage[] char
 * \return void
 *
 */
void getString(char charArray[], char message[], char errorMessage[]);
/** \brief Valida que todos los caracteres sean letras
 *
 * \param charArray[] char
 * \return int: Retorna 1 si esta bien y 0 si esta mal
 *
 */
int IsAnAlphabetString(char charArray[]);
/** \brief Genera una identificacion agregando un contador y un valor constante
 *
 * \param constant int: Valor que marca el numero a partir del cual se genera identifiacion
 * \param counter int: Contador de ingresos que permite que esta identificacion sea unica
 * \return int:Retorna que devuelve la suma del numero constante y el contador
 *
 */
int GetId(int constant, int counter);
/** \brief Pido un numero y lo valido
 *
 * \param message[] char
 * \param errorMessage[] char
 * \param int:Minimo rango
 * \param int:Maximo rango
 * \return int: Entrega un entero validado y dentro de un rango
 *
 */
int GetInt(char message[], char errorMessage[], int,int);
/** \brief Valida que el array ingresado sea un numero entero
 *
 * \param charArray[] char
 * \return int: Retorna 1 si esta bien y 0 si esta mal
 *
 */
int IsAnIntNumber(char charArray[]);
/** \brief Pide un numero y valida que sea un numero entero
 *
 * \param message[] char
 * \param errorMessage[] char
 * \return int:Entrega un numero validado
 *
 */
int GetUnsignedInt(char message[], char errorMessage[]);
/** \brief Valida que sea un numero entero
 *
 * \param charArray[] char
 * \return int:Retorna 1 si esta bien y 0 si esta mal
 *
 */
int IsAnUnsignedIntNumber(char charArray[]);
