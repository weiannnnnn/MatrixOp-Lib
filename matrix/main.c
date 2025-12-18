#include <stdio.h>
#include "matrix_op.h"

void print_mat(const char *title, int M[3][3]) {
    int i, j;
    printf("%s\n", title);
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++)
            printf("%5d ", M[i][j]);
        printf("\n");
    }
    printf("\n");
}

int main() {
    int A[3][3] = {
        {1, 2, 3},
        {0, 1, 4},
        {5, 6, 0}
    };

    int B[3][3] = {
        {7, 8, 9},
        {1, 2, 3},
        {4, 5, 6}
    };

    int R[3][3];
    int adj[3][3];

    print_mat("Matrix A:", A);
    print_mat("Matrix B:", B);

    mat_add(A, B, R);
    print_mat("A + B:", R);

    mat_sub(A, B, R);
    print_mat("A - B:", R);

    mat_elem_mul(A, B, R);
    print_mat("A o B:", R);

    mat_mul(A, B, R);
    print_mat("A * B:", R);

    mat_transpose(A, R);
    print_mat("A^T:", R);

    int detA = mat_det(A);
    printf("det(A) = %d\n\n", detA);

    mat_inverse(A, adj);
    print_mat("adj(A):", adj);

    printf("A^{-1} = adj(A) / %d\n", detA);

    return 0;
}