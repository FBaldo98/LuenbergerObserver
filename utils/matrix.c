#include "matrix.h"

void InitMatrix(matrix_t * self, int cols, int rows)
{
	self->rows = rows;
	self->cols = cols;

	// Allocate rows pointers
	self->mat = (double**)malloc(rows * sizeof(double*));

	// Allocate cols pointers
	for (int i = 0; i < rows; ++i) {
		self->mat[i] = (double*)malloc(cols * sizeof(double));
		for (int j = 0; j < cols; ++j)
			self->mat[i][j] = 0.0;
	}
}
