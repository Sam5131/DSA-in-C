/*•	Write a program to sort an array of N integers using selection sort technique. 
Write separate functions for reading the array, sorting the array and to display the elements of the array.*/
#include<stdio.h>
void read(int a[],int n)
{
    int i;
    printf("Enter the elements of the array\n");
    for(i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void display(int a[],int n)
{
    int i;
    printf("The elements of the array are\n");
    for(i=0;i<n;i++)
    {
        printf("%d\t",a[i]);
    }
}
void sort(int a[],int n)
{
    int i,j,temp,min;
    for(i=0;i<n-1;i++)
    {
        min=i;
        for(j=i+1;j<n;j++)
        {
            if(a[min]>a[j])
            {
                min=j;
            }
        }
        temp=a[min];
        a[min]=a[i];
        a[i]=temp;
    }
}
int main()
{
    int a[100],n;
    printf("Enter the size of the array\n");
    scanf("%d",&n);
    read(a,n);
    sort(a,n);
    display(a,n);
    return 0;
}
/*Output:
Enter the size of the array
5
Enter the elements of the array
5
4
12
3
89
The elements of the array are
3	4	5	12	89	*/