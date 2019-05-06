#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>
#include <stdio.h>

typedef struct matrix_t {
	double** mat;
	int cols;
	int rows;
} matrix_t;

void InitMatrix(matrix_t *self, int cols, int rows, double init_val);

void DeInitMatrix(matrix_t *self);

void PrintMatrix(matrix_t *self);

int MatrixMultiplication(matrix_t *m1, matrix_t *m2, matrix_t *res);

int MatrixSum(matrix_t *m1, matrix_t *m2, matrix_t *res);

#endif