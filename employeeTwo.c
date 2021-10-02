#include <string.h>
#include "employee.h"

//NOTE: 5 functions have been defined below 
//ptr - points to table to be searched 
//tableSize - size of the table 
//targetPtr - points to value that will be searched for in table 
//functionPtr - points to a comparison function below and will perform the associated check 

 
//What does setting a function to static do??  this function can only be used in this file, keeping everything private
//functionPtr is the address of the function just use the name 
//()(The second set of parentheses is the arguments of the function call) 
                                                                                //generic type, can point to any type of data
static PtrToEmployee searchEmployeeTable(PtrToConstEmployee ptr, int tableSize, const void *targetPtr,
                                //the function to be called   the arguments of function to be called
                                        int (*functionPtr)   (const void *, PtrToConstEmployee))
{
    PtrToConstEmployee endPtr = ptr + tableSize;
    for(; ptr < endPtr; ptr++)
    {       
        if((*functionPtr)(targetPtr, ptr) == 0) // compareEmployeeNumber(&1045, TableRow)
        {
            return (PtrToEmployee) ptr;
        }
        return NULL;
    }
}

//the functionPtr will point to one of these comparison functions to perfom a check
static int compareEmployeeNumber(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return * (long *) targetPtr != tableValuePtr -> number; // const void *targetPtr ==> typecast as long pointer then dereference
}

static int compareEmployeeName(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr -> name); //const void *targetPtr ==> typecast as char pointer then pass into strcmp()
}

static int compareEmployeePhone(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return strcmp((char *) targetPtr, tableValuePtr -> phone); //const void *targetPtr ==> typecast as char pointer then pass into strcmp()
}

static int compareEmployeeSalary(const void *targetPtr, PtrToConstEmployee tableValuePtr)
{
    return * (double *) targetPtr != tableValuePtr -> salary; // const void *targetPtr ==> typecast as long pointer then dereference
}

PtrToEmployee searchEmployeeByNumber(PtrToConstEmployee ptr, int size, long number)
{                                      // passsing the addr of number since target is a poitner
    return searchEmployeeTable(ptr, size,                    &number,                       compareEmployeeNumber);
}
                                                                    // already an address
PtrToEmployee searchEmployeeByName(PtrToConstEmployee ptr, int size, char* name)
{
    return searchEmployeeTable(ptr, size, name, compareEmployeeName);
}

PtrToEmployee searchEmployeeByPhone(PtrToConstEmployee ptr, int size, char* phone)
{
    return searchEmployeeTable(ptr, size, phone, compareEmployeePhone);
}

PtrToEmployee searchEmployeeBySalary(PtrToConstEmployee ptr, int size, double salary)
{
    return searchEmployeeTable(ptr, size, &salary, compareEmployeeSalary);
}