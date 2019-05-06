#include "luenberger_observer.h"

void InitLuembergerMatrices(luenberger_matrices_t * self)
{

	self->A = (matrix_t*)malloc(sizeof(matrix_t));
	self->B = (matrix_t*)malloc(sizeof(matrix_t));
	self->C = (matrix_t*)malloc(sizeof(matrix_t));
	self->L = (matrix_t*)malloc(sizeof(matrix_t));

	// TODO
	// Matrices size as input
	InitMatrix(self->A, 6, 6, 0.0);
	InitMatrix(self->B, 6, 1, 0.0);
	InitMatrix(self->C, 2, 6, 0.0);
	InitMatrix(self->L, 6, 2, 0.0);

	u_prev = (matrix_t*)malloc(sizeof(matrix_t));
	x_prev = (matrix_t*)malloc(sizeof(matrix_t));
	y_prev = (matrix_t*)malloc(sizeof(matrix_t));

	InitMatrix(u_prev, 1, 1, 0.0);
	InitMatrix(x_prev, 6, 1, 0.0);
	InitMatrix(y_prev, 2, 1, 0.0);
}

void LuenbergerObserver(matrix_t* u, matrix_t* y, matrix_t* x_hat, luenberger_matrices_t* matrices) {
	matrix_t res_1, res_2, y_hat, res_3, res_4, res_5, res_6;

	// Ax(k-1)
	MatrixMultiplication(matrices->A, x_prev, &res_1);
	// Bu(k-1)
	MatrixMultiplication(matrices->B, u_prev, &res_2);

	// L[y(k-1) - Cx(k-1)]
	MatrixMultiplication(matrices->C, x_prev, &y_hat);
	MatrixSubtraction(y_prev, &y_hat, &res_3);
	MatrixMultiplication(matrices->L, &res_3, &res_4);

	MatrixSum(&res_1, &res_2, &res_5);
	MatrixSum(&res_5, &res_4, &res_6);

	CopyMatrixValues(&res_6, x_hat);

	CopyMatrixValues(y, y_prev);
	CopyMatrixValues(x_hat, x_prev);
	CopyMatrixValues(u, u_prev);

}