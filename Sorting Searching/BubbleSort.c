/*•	Write a program to sort an array of N integers using bubble sort technique. 
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
    int i,j,temp;
    for(i=0;i<n-1;i++)
    {
        for(j=0;j<n-1;j++)
        {
            if(a[j+1]<a[j])
            {
                temp=a[j+1];
                a[j+1]=a[j];
                a[j]=temp;
            }
        }
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
3
2
1
The elements of the array are
1	2	3	4	5	*/