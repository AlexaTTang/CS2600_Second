#include <string.h>
#include "employee.h"
                                    //pointer to table i want to search               employee id number
PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr,           int tableSize, long targetNumber)
{
    //figuring out the end of the table, we know addr of the beginning of the table
    const PtrToConstEmployee endPtr = ptr + tableSize; // pointing to the end of the table, boundary
    for(; ptr < endPtr; ptr++)// search until end of the table
    {       // to number
        if (ptr -> number == targetNumber)//check if it equals the employee number
        {
            return(PtrToEmployee) ptr; //return the location of the number to callee
        }
    }
    return NULL; // will only happen if no Employee number matches in loop above
}

//essentially  the same functionality as above but comparing strings to check if equal
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int tableSize, char * targetName)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
                        //next "row" so think if int ptr, ptr++ would increment 4 bytes
    for(; ptr < endPtr;     ptr++   )// search until end of the table
    {       // to number
        if (strcmp(ptr -> name, targetName) == 0)//check if it equals the employee number
        {
            return(PtrToEmployee) ptr; //return the location of the number to callee
        }
    }
    return NULL; // will only happen if no Employee number matches in loop above
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int tableSize, char * targetPhone)
{
    const PtrToConstEmployee endPtr = ptr + tableSize;
                        //next "row" so think if int ptr, ptr++ would increment 4 bytes
    for(; ptr < endPtr;     ptr++   )// search until end of the table
    {       // to number
        if (strcmp(ptr -> phone, targetPhone) == 0)//check if it equals the employee phone number
        {
            return(PtrToEmployee) ptr; //return the location of the number to callee
        }
    }
    return NULL; // will only happen if no Employee phone matches in loop above
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr,           int tableSize, double targetSalary)
{
    //figuring out the end of the table, we know addr of the beginning of the table
    const PtrToConstEmployee endPtr = ptr + tableSize; // pointing to the end of the table, boundary
    for(; ptr < endPtr; ptr++)// search until end of the table
    {       // to number
        if (ptr -> salary == targetSalary)//check if it equals the employee number
        {
            return(PtrToEmployee) ptr; //return the location of the number to callee
        }
    }
    return NULL; // will only happen if no Employee number matches in loop above
}