#include "ArrayEmployees.h"

int EmployeesCaseOne(int counter, sEmployee employee[], int len)
{
    int ret;

    ret=SearchFree(employee, len);

    switch(ret){
        case -1:
            printf("\nNo hay espacio disponible.\n");
            counter--;
            break;
        default:
            AddEmployeeData(employee, len, counter);
    }

    return counter;
}

void EmployeesCaseTwo(int counter, sEmployee employee[], int len)
{
    int ret;

    if(counter!=0)
    {
        ret=ModifyEmployee(employee, len);
        switch(ret){
        case 1:
            printf("Empleado modificado.\n");
            break;
        case -1:
            printf("No existe el empleado.\n");
            break;
        case 0:
            printf("Accion cancelada.\n");
            break;
        }
    }else{
        printf("Primero debe ingresar empleados\n");
    }
}

void EmployeesCaseThree(int counter, sEmployee employee[], int len)
{
   int id;
   int ret;

   if(counter!=0)
    {
       PrintEmployees(employee, len);
       id=GetUnsignedInt("Ingrese ID a buscar: ","No valor disponible. Ingrese ID a buscar: ");
       ret=RemoveEmployee(employee, len, id);

       switch(ret){
            case 0:
                printf("Empleado eliminado.\n");
            break;
            case -1:
                printf("No existe el empleado.\n");
            break;
            case 1:
                printf("Accion cancelada.\n");
            break;
        }
    }
    else
    {
        printf("Primero debe ingresar empleados\n");
    }

}

void EmployeesCaseFour(int counter, sEmployee employee[], int len)
{
    int sortOption;
    float average;
    int aboveAverageSalary;
    float acc;
    int employeesCounter;

    if(counter!=0)
    {
        sortOption=GetInt("Opciones de ordenamiento\n 1.Creciente \n 0.Decreciente\nIngrese una opcion: ", "No es una opcion valida, reingrese la opcion: ", 0,1 );
        SortEmployees(employee, len, sortOption);
        PrintEmployees(employee, len);


        acc=AccEmployeesSalary(employee, len);
        employeesCounter=CounterEmployess(employee, len);

        average=AverageEmployeesSalary(acc, employeesCounter);
        aboveAverageSalary=AboveAverageSalary(employee, len, average);

        printf("La sumatoria de los salarios es %.2f.\nEl promedio de los salarios es %.2f.\nLa cantidad de empleados que superan el salario promedio es %d.\n",acc ,average, aboveAverageSalary);

    }else{
        printf("Primero debe ingresar empleados\n");
    }
}

int InitEmployees(sEmployee employee[], int len)
{
    int i;
    for(i=0; i<len; i++)
    {
        employee[i].isEmpty=EMPTY;
    }
    return 0;
}

int SearchFree(sEmployee employee[], int len)
{
    int index=-1;
    int i;

    for(i=0;i<len;i++)
    {
        if (employee[i].isEmpty==EMPTY)
        {
            index=i;
            break;
        }
    }

    return index;
}

void AddEmployeeData(sEmployee employee[], int len, int counter)
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int ret;

    id=GetId(1000, counter);
    getString(name, "Ingrese nombre del empleado: ", "El nombre debe poseer solo letras, reingrese el nombre del empleado: ");
    getString(lastName, "Ingrese apellido del empleado: ", "El apellido debe poseer solo letras, reingrese el apellido del empleado: ");
    salary=GetFloat("Ingrese salario: ", "No es un salario disponible, reingrese salario: ", 1000, 100000);
    sector=GetInt("Ingrese sector: ","No es un sector disponible, reingrese sector: ",1,10);

    ret=AddEmployee(employee, len, id, name, lastName, salary, sector);
    switch (ret){
    case 0:
        printf("\nSe ha realizado el alta de forma efectiva.\n");
        break;
    }

}

int AddEmployee(sEmployee employee[], int len, int id, char name[],char lastName[],float salary,int sector)
{
    int index;
    int joined=-1;
    index= SearchFree(employee, len);

    if (index!=-1)
    {
        employee[index].id=id;
        printf("Su ID es: %d", employee[index].id);
        strcpy(employee[index].name,name);
        strcpy(employee[index].lastName,lastName);
        employee[index].salary=salary;
        employee[index].sector=sector;

        employee[index].isEmpty=FULL;
        joined=0;

    }

    return joined;
}

int FindEmployeeById(sEmployee employee[], int len, int id)
{
    int i;
    int index=-1;

    for (i=0; i<len; i++)
    {
        if (employee[i].isEmpty==FULL && id==employee[i].id)
        {
            index=i;
        }
    }

    return index;
}

int ModifyEmployee(sEmployee employee[], int len)
{
    int i;
    int choice;
    char confirmation[20];
    int id;
    int ret=1;
    sEmployee auxEmployee;


    PrintEmployees(employee, len);
    id=GetUnsignedInt("Ingrese ID a buscar: ","No es un ID. Ingrese ID a buscar: ");
    i=FindEmployeeById(employee, len, id);

    if (i!=-1)
    {
        strcpy(auxEmployee.name, employee[i].name);
        strcpy(auxEmployee.lastName, employee[i].lastName);
        auxEmployee.salary=employee[i].salary;
        auxEmployee.sector=employee[i].sector;
        do{
           choice=GetInt("Opciones a modificar:\n 1.NOMBRE\n 2.APELLIDO\n 3.SALARIO\n 4.SECTOR\n 5.EXIT \n Ingrese una opcion: ", "no es una opcion disponible, reingrese la opcion: ",1,5);
            switch(choice)
               {
                   case 1:
                        getString(auxEmployee.name, "Ingrese nuevo nombre: ", "El nombre debe poseer solo letras, reingrese el nuevo nombre del empleado: ");
                        break;
                   case 2:
                        getString(auxEmployee.lastName, "Ingrese nuevo apellido: ", "El apellido debe poseer solo letras, reingrese el nuevo apellido del empleado: ");
                        break;
                   case 3:
                        auxEmployee.salary=GetFloat("Ingrese nuevo salario: ", "No es un salario disponible, reingrese salario: ", 0, 100000);
                        break;
                   case 4:
                        auxEmployee.sector=GetInt("Ingrese sector: ","No es un sector disponible, reingrese sector: ",1,10);
                        break;
                   case 5:
                        getString(confirmation,"¿Realmente desea modificar los datos del empleado? ","ERROR! ¿Realmente desea modificar los datos del empleado?");

                       if(stricmp(confirmation, "si")==0){
                            strcpy(employee[i].name, auxEmployee.name);
                            strcpy(employee[i].lastName, auxEmployee.lastName);
                            employee[i].salary= auxEmployee.salary;
                            employee[i].sector=auxEmployee.sector;
                        }
                        else{
                            ret=0;
                        }
                        break;
               }

        }while(choice!=5);

    }
    else{
        ret=-1;
    }

    return ret;
}

int RemoveEmployee(sEmployee employee[], int len, int id)
{
    int i;
    char confirmation[20];
    int ret=0;

    i=FindEmployeeById(employee, len, id);

    if (i==-1){
        ret=-1;
    }
    else
    {
        PrintOneEmployee(employee, i);
        getString(confirmation,"¿Realmente desea dar de baja este empleado?","ERROR! ¿Realmente desea dar de baja este empleado?");

        if(stricmp(confirmation, "si")==0){

            employee[i].isEmpty = EMPTY;
        }
        else{
            ret=1;
        }
    }

    return ret;
}

void PrintOneEmployee(sEmployee employee[], int index)
{
 printf("%8d %25s %25s\t%10.2f %10d \n",employee[index].id,
                                      employee[index].name,
                                      employee[index].lastName,
                                      employee[index].salary,
                                      employee[index].sector);

}
int SortEmployees(sEmployee employee[], int len, int order)
{

    switch (order){
        case 1:
            SortGrowingEmployees(employee,len);
            break;

        case 0:
            SortDecreasingEmployees (employee,len);
            break;
        }
    return 0;
}

void SortDecreasingEmployees (sEmployee employee[], int len)
{
    int i;
    int j;
    sEmployee auxEmployee;

    for (i=0; i<len-1; i++)
    {
        if(employee[i].isEmpty!=FULL){
            continue;
        }
        for (j=i+1; j<len; j++)
        {
            if(employee[j].isEmpty!=FULL){
            continue;
            }

            if(stricmp(employee[i].lastName, employee[j].lastName)<0 || (stricmp(employee[i].lastName, employee[j].lastName)== 0  && employee[i].sector < employee[j].sector))
            {
                auxEmployee=employee[i];
                employee[i]=employee[j];
                employee[j]=auxEmployee;
            }
        }
    }
}

void SortGrowingEmployees (sEmployee employee[], int len)
{
    int i;
    int j;
    sEmployee auxEmployee;

    for (i=0; i<len-1; i++)
    {
        if(employee[i].isEmpty!=FULL){
            continue;
        }
        for (j=i+1; j<len; j++)
        {
            if(employee[j].isEmpty!=FULL){
            continue;
            }

            if(stricmp(employee[i].lastName, employee[j].lastName)>0 || (stricmp(employee[i].lastName, employee[j].lastName)== 0  && employee[i].sector > employee[j].sector))
            {
                auxEmployee=employee[i];
                employee[i]=employee[j];
                employee[j]=auxEmployee;
            }
        }
    }
}

float AccEmployeesSalary (sEmployee employee[], int len)
{
    float accSalary=0;
    int i;

    for (i=0; i<len; i++)
    {
        if(employee[i].isEmpty==FULL)
        {
            accSalary+=employee[i].salary;
        }
    }
    return accSalary;
}

int CounterEmployess(sEmployee employee[], int len)
{
    int counter=0;
    int i;

    for (i=0; i<len; i++)
    {
        if(employee[i].isEmpty==FULL)
        {
            counter++;
        }
    }
    return counter;
}

float AverageEmployeesSalary(float acc, int counter)
{
    return acc/counter;;
}

int AboveAverageSalary(sEmployee employee[], int len, float average)
{
    int i;
    int counter=0;

    for (i=0; i<len; i++)
    {
        if(employee[i].isEmpty==FULL && employee[i].salary > average)
        {
            counter++;
        }
    }
    return counter;
}

int PrintEmployees(sEmployee employee[], int len)
{
    int i;

    printf("***** ID ****************** NOMBRE **************** APELLIDO ***** SALARIO *** SECTOR\n");
    for(i=0;i<len;i++)
    {
        if(employee[i].isEmpty==FULL)
        {
            PrintOneEmployee(employee, i);
        }
    }
    printf("*************************************************************************************\n");

    return 0;
}

