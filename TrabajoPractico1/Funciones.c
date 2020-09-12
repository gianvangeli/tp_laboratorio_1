#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"

float sumarOperandos (float x, float y)
{
	float suma;
	suma = x + y;
	printf ("\nLa suma de %.2f y %.2f es %.2f \n",x,y,suma);
	return 0;
}
float restarOperandos (float x, float y)
{
	float resta;
	resta = x - y;
	printf ("\nLa resta de %.2f y %.2f es %.2f \n",x,y,resta);
	return 0;
}

float dividirOperandos (float x, float y)
{
	float division;
	if (y==0)
	{
		printf ("\nLa division por el numero 0 no es posible\n ");
	}
	else
	{
		division = x / y;
		printf ("\nLa division de %.2f y %.2f es %.2f \n",x,y,division);

	}
	return 0;
}

float multiplicarOperandos (float x, float y)
{
	float multiplicacion;
	multiplicacion = x * y;
	printf ("\nLa multiplicacion de %.2f y %.2f es %.2f \n",x,y,multiplicacion);
	return 0;
}
int calcularFactorial(int x) //* BUSCAR COMO HACER FACTORIAL DE FLOAT
{
    int i;
    int aux=1;
    for(i=1;i<x+1;i++)
    {
        aux=aux*i;
    }
    printf("\nEl factorial de %d es igual a %d.\n",x,aux);
    return aux;
}




