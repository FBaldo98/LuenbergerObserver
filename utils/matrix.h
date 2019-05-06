#ifndef MATRIX_H
#define MATRIX_H

#include <stdlib.h>

typedef struct matrix_t {
	double** mat;
	int cols;
	int rows;
} matrix_t;

void InitMatrix(matrix_t *self, int cols, int rows);

#endif