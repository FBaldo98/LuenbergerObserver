#include "matrix.h"

void InitMatrix(matrix_t * self, int cols, int rows, double init_val)
{
	self->rows = rows;
	self->cols = cols;

	// Allocate rows pointers
	self->mat = (double**)malloc(rows * sizeof(double*));

	// Allocate cols pointers
	for (int i = 0; i < rows; ++i) {
		self->mat[i] = (double*)malloc(cols * sizeof(double));
		for (int j = 0; j < cols; ++j)
			self->mat[i][j] = init_val;
	}
}

void PrintMatrix(matrix_t *self) {
	for (int i = 0; i < self->rows; ++i) {
		for (int j = 0; j < self->cols; ++j)
			printf("%.2f\t", self->mat[i][j]);
		printf("\n");
	}
}

// Returns 1 if multiplication is succesfull, 0 if it fails
int MatrixMultiplication(matrix_t *m1, matrix_t *m2, matrix_t *res) {

	// Cannot multiply
	if (m1->rows != m2->cols)
		return 0;

	// Initialize result matrix
	InitMatrix(res, m1->rows, m2->cols, 0.0);

	for (int i = 0; i < m1->rows; ++i)
		for (int j = 0; j < m2->cols; ++j)
			for (int k = 0; k < m2->rows; ++k)
				res->mat[i][j] += m1->mat[i][k] * m2->mat[k][j];

	return 1;
}