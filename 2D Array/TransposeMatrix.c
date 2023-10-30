/*•	Write a program to find the transpose of a matrix.
Write separate functions for reading, displaying and
to find the transpose of the matrix.*/
#include <stdio.h>
#define MAX 10

void read_matrix(int m, int n, int mat[m][n]) {
    printf("Enter the elements of the matrix: ");
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            scanf("%d", &mat[i][j]);
}

void display_matrix(int m, int n, int mat[m][n]) {
    printf("The matrix is:\n");
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++)
            printf("%d ", mat[i][j]);
        printf("\n");
    }
}

void transpose_matrix(int m, int n, int mat[m][n], int trans[n][m]) {
    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            trans[j][i] = mat[i][j];
}

int main() {
    int m, n;
    printf("Enter the number of rows and columns of the matrix: ");
    scanf("%d %d", &m, &n);
    int mat[MAX][MAX], trans[MAX][MAX];
    read_matrix(m, n, mat);
    display_matrix(m, n, mat);
    transpose_matrix(m, n, mat, trans);
    printf("The transpose of the matrix is:\n");
    display_matrix(n, m, trans);
    return 0;
}
//Output:
// Enter the number of rows and columns of the matrix: 2 3
// Enter the elements of the matrix: 1 2 3 4 5 6
// The matrix is:
// 1 2 3
// 4 5 6
// The transpose of the matrix is:
// 1 4
// 2 5
// 3 6