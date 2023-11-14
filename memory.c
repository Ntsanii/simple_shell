#include "shell.h"

/**
 * myFree - frees a pointer and NULLs the address
 * @myPtr: address of the pointer to free
 *
 * Return: 1 if freed, otherwise 0.
 */
int myFree(void **myPtr)
{
    if (myPtr && *myPtr)
    {
        free(*myPtr);
        *myPtr = NULL;
        return (1);
    }
    return (0);
}
