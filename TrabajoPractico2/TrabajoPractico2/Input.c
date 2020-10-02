
#include "Input.h"

int UserMenue(void)
{
    int option;

    printf("|ALTAS, BAJAS Y MODIFICACIONES DE EMPLEADOS|\n");
    printf("Menu de opciones:\n");
    printf("1. Dar de alta un empleado\n");
    printf("2. Modificar datos de un empleado\n");
    printf("3. Dar de baja un empleado por ID\n");
    printf("4. Informar listado de los empleados ordenados alfabéticamente por apellido y sector, total , promedio de los salarios y cantidad de empleados que superan el salario promedio.\n");
    printf("5. Salir\n");

    option=GetInt("Ingrese una opcion: ","No es una opción valida, reingrese la opción: ",1,5);

    return option;
}

float GetFloat(char message[], char errorMessage[], float min, float max)
{
    float floatNumber;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';

    floatNumber=atof(stringNum);

    while(IsAnfloatNumber(stringNum)!=1|| floatNumber<min || floatNumber>max)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';

        floatNumber=atof(stringNum);
    }
    return floatNumber;
}
int IsAnfloatNumber(char charArray[])//no funciona
{
    int i=0;
    int ret=1;
    int dotsCounter=0;

    if(charArray[0]=='\0'||charArray[0]=='.'||charArray[strlen(charArray)-1]=='.'){
        ret=0;
    }
    else{
        if(charArray[0]=='-'){
         i=1;
        }
    }
    for( ;charArray[i]!='\0' ;i++)
    {
         if(charArray[i]<'0'||charArray[i]>'9')
        {
            if(charArray[i]!= '.'||dotsCounter!=0)
            {
               ret=0;
               break;
            }
            else{
                dotsCounter++;
            }
        }
    }
    return ret;
}

void getString(char charArray[], char message[], char errorMessage[])
{
    printf("%s", message);
    fflush(stdin);
    //__fpurge(stdin);
    fgets(charArray, 51, stdin);

    charArray[strlen(charArray)-1] = '\0';

    while(IsAnAlphabetString(charArray)==1)
    {
        printf("%s", errorMessage);
        fflush(stdin);
        //__fpurge(stdin);
        fgets(charArray, 51, stdin);
        charArray[strlen(charArray)-1] = '\0';
    }

}
int IsAnAlphabetString(char charArray[])
{
    int i;
    int flag=0;

    for(i=0; charArray[i]!='\0'; i++)
    {
        if((charArray[i]<'a' || charArray[i]>'z') && (charArray[i]<'A' || charArray[i]>'Z'))
        {
            flag=1;
            break;
        }
    }
    return flag;
}

int GetId(int constant, int counter)
{
    return constant+counter;
}

int GetInt(char message[], char errorMessage[], int min, int max)
{
    int num;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';
    //convierto a stringNum a un numero int
    num=atoi(stringNum);
    //si la funcion IsAnumber es distinto a 1 omito las siguentescondiciones porque no es un numero
    //si pasa la primer condicion es porque es un numero y el la variable 'num' tiene un valor numerico valido
    //valida si esta en el rango y de no ser asi entra en el while para repetir el proceso
    while(IsAnIntNumber(stringNum)!=1|| num<min || num>max)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';

        num=atoi(stringNum);
    }
    return num;

}
int IsAnIntNumber(char charArray[])
{
    int i=0;
    int ret=1;

     if(charArray[0]=='-'){
        i=1;
    }
    for( ; charArray[i]!='\0' ;i++)
    {
        if(charArray[i]<'0'||charArray[i]>'9')
        {
            ret=0;
            break;
        }
    }

    return ret;
}
int GetUnsignedInt(char message[], char errorMessage[])
{
    int num;
    char stringNum[200];
    //pido datos
    printf("%s", message);
    //__fpurge(stdin);
    fflush(stdin);
    fgets(stringNum,200,stdin);
    stringNum[strlen(stringNum)-1]='\0';

    //si la funcion IsAnumber es distinto a 1 omito no es un numero

    while(IsAnUnsignedIntNumber(stringNum)!=1)
    {
        printf("%s", errorMessage);
        //__fpurge(stdin);
        fflush(stdin);
        fgets(stringNum,200,stdin);
        stringNum[strlen(stringNum)-1]='\0';
    }
     //convierto a stringNum a un numero int
     num=atoi(stringNum);

    return num;



}
int IsAnUnsignedIntNumber(char charArray[])
{
    int i;
    int ret=1;

    if(charArray[0]=='\0')
    {
        ret=0;
    }

    for(i=0 ; charArray[i]!='\0' ;i++)
    {
        if(charArray[i]<'0'||charArray[i]>'9')
        {
            ret=0;
            break;
        }
    }
    return ret;
}
