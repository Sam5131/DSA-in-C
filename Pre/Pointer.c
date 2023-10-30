#include<stdio.h>
//& gives us the address
//* gives us the value
void main()
{
    int a=20;
    int *ptr;
    ptr=&a;//Address of a
    printf("Address of a: %d",ptr);
    printf("\nValue of a: %d",*ptr);
    *ptr=12;
    printf("Value of at ptr: %d",*ptr);
}