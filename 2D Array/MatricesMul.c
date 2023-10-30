//Write a program to find the multiplication of two matrices. 
//Write separate functions for reading the matrix, 
//displaying the matrix and to find the multiplication of the matrices.
// Don't use pointers
#include<stdio.h>
#include<stdlib.h>
void readArray(int rows, int col, int a[rows][col])
{
    int i,j;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
}
void displayArray(int rows, int col, int a[rows][col])
{
    int i,j;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            printf("%d ",a[i][j]);
        }
        printf("\n");
    }
}
void mulArray(int rows, int col, int a[rows][col], int b[rows][col], int c[rows][col])
{
    int i,j,k;
    for(int i=0;i<rows;i++)
    {
        for(int j=0;j<col;j++)
        {
            c[i][j]=0;
            for(int k=0;k<col;k++)
            {
                c[i][j]+=a[i][k]*b[k][j];
            }
        }
    }
}
int main()
{
    int rows,col;
    printf("Enter the number of rows and columns: ");
    scanf("%d%d",&rows,&col);
    int a[rows][col],b[rows][col],c[rows][col];
    printf("Enter the elements of first matrix: ");
    readArray(rows,col,a);
    printf("Enter the elements of second matrix: ");
    readArray(rows,col,b);
    printf("The first matrix is: \n");
    displayArray(rows,col,a);
    printf("The second matrix is: \n");
    displayArray(rows,col,b);
    mulArray(rows,col,a,b,c);
    printf("The multiplication of the two matrices is: \n");
    displayArray(rows,col,c);
    return 0;
}
//Output:
// Enter the number of rows and columns: 2 2
// Enter the elements of first matrix: 1 2 3 4
// Enter the elements of second matrix: 5 6 7 8
// The first matrix is:
// 1 2
// 3 4
// The second matrix is:
// 5 6
// 7 8
// The multiplication of the two matrices is:
// 19 22
// 43 50