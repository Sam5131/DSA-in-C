//Write a program to search an element in an array using binary search technique.
// Write separate functions for reading the array, and for searching the element in the array.
#include<stdio.h>
#include<stdlib.h>
void readArray(int a[],int n)
{
    printf("enter the elements:");
    for(int i=0;i<n;i++)
    {
        scanf("%d",&a[i]);
    }
}
void displayArray(int a[], int n)
{
    for(int i=0;i<n;i++)
    {
        printf("%d ",a[i]);
    }
    printf("\n");
}
void binarySearch(int a[],int n,int ele)
{
    int low=0,high=n-1,mid;
    while(low<=high)
    {
        mid=(low+high)/2;
        if(a[mid]==ele)
        {
            printf("the element is found at position %d\n",mid+1);
            return;
        }
        else if(a[mid]<ele)
        {
            low=mid+1;
        }
        else
        {
            high=mid-1;
        }
    }
    printf("the element is not found\n");
}
int main()
{
    int a[100];
    int ele,n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    readArray(a,n);
    printf("enter the element to search: ");
    scanf("%d",&ele);
    binarySearch(a,n,ele);
    return 0;
}
//Output:
// enter the size of the array: 5
// enter the elements:1 2 3 4 5
// enter the element to search: 3
// the element is found at position 3
//