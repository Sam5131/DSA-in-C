//Write a program to delete an element in an array. Write separate functions for reading the array.
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
void delete()
{
    int a[100];
    int ele,pos,n;
    printf("enter the size of the array: ");
    scanf("%d",&n);
    readArray(a,n);
    printf("enter the position to delete the element: ");
    scanf("%d",&pos);
    for(int i=pos-1;i<n;i++){
        a[i]=a[i+1];
    }
    n--;
    displayArray(a, n);
}
int main()
{
    delete();
    return 0;
}
//Output:
// enter the size of the array: 5
// enter the elements:1 2 3 4 5
// enter the position to delete the element: 3
// 1 2 4 5
//