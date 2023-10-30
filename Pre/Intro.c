#include<stdio.h>
void main()
{
    int a=5; //Value of a
    int *ptr; //Intialized pointer ptr
    ptr=&a; //referencing value of a
    printf("Value of a is %d %d",a,*ptr);// Value of a by De-Referencing
    printf("\nAddress of a is %d %d",ptr,&a);// Value of address of value
}