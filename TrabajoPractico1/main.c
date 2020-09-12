#include <stdio.h>
#include <stdlib.h>
#include "Funciones.h"


int main()
{
    float A= 0;
    float B= 0;
    char seguir = 's';
    int opcion=0;


    while (seguir == 's')
    {
    	printf ("\n 1 - Ingresar primer operando: (A=%.2f) ", A);
    	printf ("\n 2 - Ingresar segundo operando: (B=%.2f) ",B);
    	printf ("\n 3 - Calcular la suma (A=%.2f + B=%.2f) ",A,B);
    	printf ("\n 4 - Calcular la resta (A=%.2f - B=%.2f) ",A,B);
    	printf ("\n 5 - Calcular la division (A=%.2f / B=%2.f) ",A,B);
    	printf ("\n 6 - Calcular la multiplicacion(A=%.2f * B=%2.f) ",A,B);
    	printf ("\n 7 - Calcular factorial (A=%.2f) ",A);
    	printf ("\n 8 - Calcular todas las operaciones ");
    	printf ("\n 9 - Salir \n");

    	scanf ("%d", &opcion);

    	switch (opcion)
    	{
    		case 1: printf ("Ingresar primer operando: \n");
    		        scanf ("%f", &A);
    		break;
    		case 2: printf ("Ingresar segundo operando: \n");
				    scanf ("%f", &B);
			break;
			case 3:	sumarOperandos (A,B);
			break;
			case 4: restarOperandos (A,B);
			break;
			case 5: dividirOperandos (A,B);
			break;
			case 6: multiplicarOperandos (A,B);
			break;
			case 7: calcularFactorial (A);
			break;
			case 8: sumarOperandos (A,B);
			        restarOperandos (A,B);
			        dividirOperandos (A,B);
			        multiplicarOperandos(A,B);
			        calcularFactorial (A);
			break;
			case 9: seguir = 'n';
			break;


    	}
    }
    return 0;


}
