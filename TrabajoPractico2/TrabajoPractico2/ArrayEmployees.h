#include "Input.h"
#define FULL 0
#define EMPTY 1

typedef struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
}sEmployee;

/** \brief Funcion que guarda la logica del case 1
 *
 * \param counter int: Es un contador que se utiliza para generar identificacion unica
 * \param employee[] sEmployee:Array de empleados
 * \param len int: Largo del array
 * \return int Devuelve el contador o el contador disminuye en 1 si habia, sin espacio libre para no perder valores en el id
 *
 */
int EmployeesCaseOne(int counter, sEmployee employee[], int len);
/** \brief Funcion que guarda la logica del case 2
 *
 * \param counter int: Recibe el contador de registro de empleados para usarlo como bandera y validar al menos un empleado
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \return void
 *
 */
void EmployeesCaseTwo(int counter, sEmployee employee[], int len);
/** \brief Funcion que guarda la logica del case 3
 *
 * \param counter int:Recibe el contador de registro de empleados para usarlo como bandera y validar al menos un empleado
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \return void
 *
 */
void EmployeesCaseThree(int counter, sEmployee employee[], int len);
/** \brief Funcion que guarda la logica del case 4
 *
 * \param counter int:Recibe el contador de registro de empleados para usarlo como bandera y validar al menos un empleado
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \return void
 *
 */
void EmployeesCaseFour(int counter, sEmployee employee[], int len);
/** \brief Indica que las posiciones del array esten vacias, esta funcion pone la bandera en verdadero a todos.
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \return int: Retorna 0 si esta bien
 *
 */
int InitEmployees(sEmployee employee[], int len);
/** \brief Encuentra la primera posicion libre del array
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \return int: Retorna -1 si no hay una posicion libre en el array o un indice de posicion libre
 *
 */
int SearchFree(sEmployee employee[], int len);
/** \brief Solicita la entrada de los datos de los empleados como parametro a la funcion addEmployee
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \param counter int: Usa el contador para generar el id
 * \return void
 *
 */
void AddEmployeeData(sEmployee employee[], int len, int counter);
/** \brief Agrega en una lista existente de empleados los valores recibidos como parametros en la posicion vacia
 *
 * \param employee[] sEmployee
 * \param len int:
 * \param id int
 * \param name[] char
 * \param lastName[] char
 * \param salary float
 * \param sector int
 * \return int: Retorna -1 si esta mal y 0 si esta bien
 *
 */
int AddEmployee(sEmployee employee[], int len, int id, char name[],char lastName[],float salary,int sector);
/** \brief Devulve la posicion del indice de la matriz
 *
 * \param employee[] sEmployee: Array de empleado
 * \param len int: Largo de empleado
 * \param id int
 * \return int: Retorna la posicion del indice de empleado o -1 si no encuentra empleado
 *
 */
int FindEmployeeById(sEmployee employee[], int len, int id);
/** \brief Pide una identificacion,muestra un menu de modificacion y el usuario que quiere modificar
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \return int: Devuelve -1 si no encuentra un empleado, 1 si esta bien y 0 si la accion se cancela
 *
 */
int ModifyEmployee(sEmployee employee[], int len);
/** \brief Elimina un empleado por ID(pone la bandera isEmpty en 1)
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \param id int
 * \return int: Retorna -1 si esta mal y 0 si esta bien
 *
 */
int RemoveEmployee(sEmployee employee[], int len, int id);
/** \brief Imprime el contenido de un empleado
 *
 * \param employee[] sEmployee: Array de empleado
 * \param index int: Recibe el indice del empleado
 * \return void
 *
 */
void PrintOneEmployee(sEmployee employee[], int index);
/** \brief Ordena los elementos del array de empleados, el orden de los argumentos indican el orden arriba o abajo
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \param order int: 1 indica arriba,0 indica abajo
 * \return int: 0 si esta bien
 *
 */
int SortEmployees(sEmployee employee[], int len, int order);
/** \brief Ordena los elementos del array en orden decreciente por apellido y sector
 *
 * \param employee[] sEmployee: Array de empleado
 * \param len int: Largo del array
 * \return void
 *
 */
void SortDecreasingEmployees (sEmployee employee[], int len);
/** \brief Ordena los elementos del array en orden creciente por apellido y sector
 *
 * \param employee[] sEmployee
 * \param len int
 * \return void
 *
 */
void SortGrowingEmployees (sEmployee employee[], int len);
/** \brief Acumula el salario de todos los empleados
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \return float: Retorna el valor acumulado
 *
 */
float AccEmployeesSalary (sEmployee employee[], int len);
/** \brief Esta funcion cuenta el numero de empleados
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \return int:Retorna el valor del contador
 *
 */
int CounterEmployess(sEmployee employee[], int len);
/** \brief Recibe un contador y acumulador y promedia
 *
 * \param acc float: Cuenta de salario
 * \param counter int: Contador de empleados
 * \return float: Retorna el promedio
 *
 */
float AverageEmployeesSalary(float acc, int counter);
/** \brief Esta funcion cuenta los empleados que superan el salario medio
 *
 * \param employee[] sEmployee: Array de empleados
 * \param len int: Largo del array
 * \param average float: Salario promedio
 * \return int Contador para empleados que exceden el salario promedio
 *
 */
int AboveAverageSalary(sEmployee employee[], int len, float average);
/** \brief Imprime el contenido del array empleados
 *
 * \param employee[] sEmployee:Array de empleados
 * \param len int: Largo del array
 * \return int
 *
 */
int PrintEmployees(sEmployee employee[], int len);
