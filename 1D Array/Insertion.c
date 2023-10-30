/*•	Write a program to insert an element in an array.
Write separate functions for reading the array, inserting element and displaying the resulting array.*/
#include<stdio.h>
#include<stdlib.h>
void read(int a[], int n)
{
    printf("Enter the elements of the array: ");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[], int n)
{
    printf("The elements of the array are: ");
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void insert()
{
    int a[100],n,ele,pos;
    printf("Enter the size of the array: ");
    scanf("%d",&n);
    read(a,n);
    printf("Enter the position to insert the element: ");
    scanf("%d",&pos);
    printf("Enter the element to be inserted: ");
    scanf("%d",&ele);
    for(int i=n;i>pos-1;i--)
    {
        a[i]=a[i-1];
    }
    a[pos-1]=ele;
    n++;
    display(a,n);
}
int main()
{
    insert();
    return 0;
}
//Output:
// Enter the size of the array: 5
// Enter the elements of the array: 1 2 3 4 5
// Enter the position to insert the element: 3
// Enter the element to be inserted: 6
// The elements of the array are: 1 2 6 3 4 5
//