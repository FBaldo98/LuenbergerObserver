#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>

typedef struct matrix_t {
	double** mat;
	int cols;
	int rows;
} matrix_t;

void InitMatrix(matrix_t *self, int rows, int cols, double init_val);

void CopyMatrixValues(matrix_t *src, matrix_t *dst);

void DeInitMatrix(matrix_t *self);

void PrintMatrix(matrix_t *self);

int MatrixMultiplication(matrix_t *m1, matrix_t *m2, matrix_t *res);

int MatrixScalarMultiplication(matrix_t *m1, double scalar, matrix_t *res);

int MatrixSum(matrix_t *m1, matrix_t *m2, matrix_t *res);

int MatrixSubtraction(matrix_t *m1, matrix_t *m2, matrix_t *res);

#endif