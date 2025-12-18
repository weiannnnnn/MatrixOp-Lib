#ifndef MATRIX_OP_H
#define MATRIX_OP_H

#define SIZE 3

/* Basic operations */
void mat_add(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void mat_sub(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void mat_elem_mul(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);

/* Linear operations */
void mat_mul(int A[SIZE][SIZE], int B[SIZE][SIZE], int R[SIZE][SIZE]);
void mat_transpose(int A[SIZE][SIZE], int R[SIZE][SIZE]);

/* Advanced */
int mat_det(int A[SIZE][SIZE]);

/* Inverse: compute adj(A), return det(A) */
int mat_inverse(int A[SIZE][SIZE], int adj[SIZE][SIZE]);

#endif