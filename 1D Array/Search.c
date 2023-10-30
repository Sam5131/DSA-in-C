//•	Write a program to search an element in an array using linear search technique. 
//Write separate functions for reading the array, and for searching the element in the array
#include<stdio.h>
void readArray(int a[],int n){
  printf("enter the elements:");
  for(int i=0;i<n;i++){
    scanf("%d",&a[i]);
  }
}
void displayArray(int a[], int n){
  for(int i=0;i<n;i++){
    printf("%d ",a[i]);
  }
  printf("\n");
}
void search()
{
    int a[100];
    int ele,pos,n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    readArray(a,n);
    printf("enter the element to search: ");
    scanf("%d",&ele);
    for(int i=0;i<n;i++){
        if(a[i]==ele){
            pos=i+1;
            break;
        }
    }
    printf("the element is found at position %d\n",pos);
}
int main()
{
    search();
    return 0;
}
//Output:
// enter the size of the array: 5
// enter the elements:1 2 3 4 5
// enter the element to search: 3
// the element is found at position 3
//