//gcc employeeMain.c employeeTable.c employeeOne.c
//gcc employeeMain.c employeeTable.c employeeTwo.

#include <string.h>
#include <stdlib.h>
#include "employee.h"

int main(void)
{
    //defined in in employeeOne.c or employeeTwo.c
    //function protoypes
    PtrToEmployee searchEmployeeByNumber(const Employee table[], int sizeTable, long numberToFind);
    PtrToEmployee searchEmployeeByName(const Employee table[], int sizeTable, char * nameToFind);

    //defined in employeeTable.c, extern -> these vars declared somewhere else
    extern Employee EmployeeTable[];
    extern const int EmployeeTableEntries;

    PtrToEmployee matchPtr; //Declaration, matchPtr is of type pointer
                                    //pointer to array                       employee id
    matchPtr = searchEmployeeByNumber(EmployeeTable,   EmployeeTableEntries,    4011);

    //Example not found
    if (matchPtr != NULL)
    {
        printf("employee id 4011 is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("employee id 4011 is NOT found in the record\n");
    }

    //example found
    matchPtr = searchEmployeeByName(EmployeeTable, EmployeeTableEntries, "Daphne Borromeo");
    if (matchPtr != NULL)
    {                                                           
        printf("employee Daphne Borromeo is in record %d\n", matchPtr - EmployeeTable);
    }
    else
    {
        printf("employee Daphne Borromeo is NOT found in the record\n");
    }
    EXIT_SUCCESS;
}