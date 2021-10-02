#include <stdio.h>
#include <stddef.h>

//structure of the employee table
typedef struct 
{
    /* data */
    long number; //four bytes
    char *name; //four bytes
    char *phone; //four bytes
    double salary; //eight bytes
} Employee, *PtrToEmployee; // two variable names

//      once initialized, cant be changed    pointer of type Employee 
typedef       const                          Employee *PtrToConstEmployee;
