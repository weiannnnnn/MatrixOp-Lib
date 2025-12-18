#include "matrix_op.h"

/* ===== Basic ===== */

void mat_add(int A[3][3], int B[3][3], int R[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            R[i][j] = A[i][j] + B[i][j];
}

void mat_sub(int A[3][3], int B[3][3], int R[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            R[i][j] = A[i][j] - B[i][j];
}

void mat_elem_mul(int A[3][3], int B[3][3], int R[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            R[i][j] = A[i][j] * B[i][j];
}

/* ===== Linear ===== */

void mat_mul(int A[3][3], int B[3][3], int R[3][3]) {
    int i, j, k;
    for (i = 0; i < 3; i++) {
        for (j = 0; j < 3; j++) {
            R[i][j] = 0;
            for (k = 0; k < 3; k++)
                R[i][j] += A[i][k] * B[k][j];
        }
    }
}

void mat_transpose(int A[3][3], int R[3][3]) {
    int i, j;
    for (i = 0; i < 3; i++)
        for (j = 0; j < 3; j++)
            R[j][i] = A[i][j];
}

/* ===== Determinant ===== */

int mat_det(int A[3][3]) {
    int a = A[0][0], b = A[0][1], c = A[0][2];
    int d = A[1][0], e = A[1][1], f = A[1][2];
    int g = A[2][0], h = A[2][1], i = A[2][2];

    return a*(e*i - f*h)
         - b*(d*i - f*g)
         + c*(d*h - e*g);
}

/* ===== Inverse (Adjoint) ===== */

static int det2(int a, int b, int c, int d) {
    return a*d - b*c;
}

int mat_inverse(int A[3][3], int adj[3][3]) {
    int detA = mat_det(A);

    /* adj(A) = cofactor(A)^T */
    adj[0][0] =  det2(A[1][1], A[1][2], A[2][1], A[2][2]);
    adj[1][0] = -det2(A[1][0], A[1][2], A[2][0], A[2][2]);
    adj[2][0] =  det2(A[1][0], A[1][1], A[2][0], A[2][1]);

    adj[0][1] = -det2(A[0][1], A[0][2], A[2][1], A[2][2]);
    adj[1][1] =  det2(A[0][0], A[0][2], A[2][0], A[2][2]);
    adj[2][1] = -det2(A[0][0], A[0][1], A[2][0], A[2][1]);

    adj[0][2] =  det2(A[0][1], A[0][2], A[1][1], A[1][2]);
    adj[1][2] = -det2(A[0][0], A[0][2], A[1][0], A[1][2]);
    adj[2][2] =  det2(A[0][0], A[0][1], A[1][0], A[1][1]);

    return detA;  /* A^{-1} = adj(A) / det(A) */
}