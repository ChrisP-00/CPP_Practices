#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int dVar = 99;
    int* pVar = &dVar;

    printf("dVar pointer: %p \n pVar address: %p\n", &dVar, pVar);
    printf("dVar value %d \n pVar value %d", dVar, *pVar);


    return 0;
}