#include "matrix.h"

void InitMatrix(matrix_t * self, int rows, int cols, double init_val)
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

void DeInitMatrix(matrix_t *self) {
	for (int i = 0; i < self->rows; ++i)
		free(self->mat[i]);
}

void PrintMatrix(matrix_t *self) {
	for (int i = 0; i < self->rows; ++i) {
		for (int j = 0; j < self->cols; ++j)
			printf("%.2f\t", self->mat[i][j]);
		printf("\n");
	}
}

// Returns 0 if multiplication is succesfull, 1 if it fails
int MatrixMultiplication(matrix_t *m1, matrix_t *m2, matrix_t *res) {

	if (m1->cols == 1 && m1->rows == 1)
		return MatrixScalarMultiplication(m2, m1->mat[0][0], res);

	if (m2->cols == 1 && m2->rows == 1)
		return MatrixScalarMultiplication(m1, m2->mat[0][0], res);

	// Cannot multiply
	if (m1->cols != m2->rows)
		return 1;

	// Initialize result matrix
	InitMatrix(res, m1->rows, m2->cols, 0.0);

	for (int i = 0; i < m1->rows; ++i)
		for (int j = 0; j < m2->cols; ++j)
			for (int k = 0; k < m2->rows; ++k)
				res->mat[i][j] += m1->mat[i][k] * m2->mat[k][j];

	return 0;
}

// Returns 0 if multiplication is succesfull, 1 if it fails
int MatrixScalarMultiplication(matrix_t *m1, double scalar, matrix_t *res) {

	// Initialize result matrix
	InitMatrix(res, m1->rows, m1->cols, 0.0);

	for (int i = 0; i < m1->rows; ++i)
		for (int j = 0; j < m1->cols; ++j)
			res->mat[i][j] = m1->mat[i][j] * scalar;

	return 0;
}

// Returns 0 if sum is succesfull, 1 if it fails
int MatrixSum(matrix_t *m1, matrix_t *m2, matrix_t *res) {
	if (m1->cols != m2->cols || m1->rows != m2->rows)
		return 1;

	InitMatrix(res, m1->rows, m1->cols, 0.0);

	for (int i = 0; i < m1->rows; ++i)
		for (int j = 0; j < m1->cols; ++j)
			res->mat[i][j] = m1->mat[i][j] + m2->mat[i][j];

	return 0;
}

int MatrixSubtraction(matrix_t *m1, matrix_t *m2, matrix_t *res) {
	if (m1->cols != m2->cols || m1->rows != m2->rows)
		return 1;

	InitMatrix(res, m1->rows, m1->cols, 0.0);

	for (int i = 0; i < m1->rows; ++i)
		for (int j = 0; j < m1->cols; ++j)
			res->mat[i][j] = m1->mat[i][j] - m2->mat[i][j];

	return 0;
}

void CopyMatrixValues(matrix_t *src, matrix_t *dst) {
	if (src->cols != dst->cols || src->rows != dst->rows)
		return;

	// TODO
	// Use memcpy

	for (int i = 0; i < src->rows; ++i)
		for (int j = 0; j < src->cols; ++j)
			dst->mat[i][j] = src->mat[i][j];

}