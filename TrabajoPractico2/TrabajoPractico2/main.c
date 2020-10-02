#include <stdlib.h>
#define L 1000
#include "ArrayEmployees.h"

int main()
{
    sEmployee employee[L];
    int menueOption;
    int counter=0;
    char confirmation[40];
    InitEmployees(employee, L);

    do{
        menueOption=UserMenue();
        switch(menueOption){
            case 1:
                counter++;
                counter=EmployeesCaseOne(counter, employee, L);
                break;
            case 2:
                EmployeesCaseTwo(counter, employee, L);
                break;
            case 3:
                EmployeesCaseThree(counter, employee, L);
                break;
            case 4:
                EmployeesCaseFour(counter, employee, L);
                break;
            case 5:
                getString(confirmation, "¿Desea realmente salir? ", "ERROR! ¿Desea realmente salir? ");
                if(stricmp(confirmation,"si")==0){
                    menueOption=6;
                }
                break;
        }
    system("pause");
    system("cls");

    }while(menueOption!=6);
    return 0;
}
