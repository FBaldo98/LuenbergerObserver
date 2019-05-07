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

	self->A->mat[1][0] = -2000.0;
	self->A->mat[1][1] = -1.2;
	self->A->mat[1][2] = 2000.0;
	self->A->mat[1][4] = 20.0;
	self->A->mat[2][3] = 1.0;
	self->A->mat[3][0] = 163.9341;
	self->A->mat[3][2] = -163.9341;
	self->A->mat[3][5] = -1.6393;

	InitMatrix(self->B, 6, 1, 0.0);

	self->B->mat[3][0] = 27.8688;

	InitMatrix(self->C, 2, 6, 0.0);

	self->C->mat[0][0] = 100.0;
	self->C->mat[0][2] = -100.0;
	self->C->mat[1][2] = 17.0;

	InitMatrix(self->L, 6, 2, 0.0);

	u_prev = (matrix_t*)malloc(sizeof(matrix_t));
	x_prev = (matrix_t*)malloc(sizeof(matrix_t));
	y_prev = (matrix_t*)malloc(sizeof(matrix_t));

	InitMatrix(u_prev, 1, 1, 0.0);
	InitMatrix(x_prev, 6, 1, 0.0);
	InitMatrix(y_prev, 2, 1, 0.0);
}

void LuenbergerObserver(matrix_t* u, matrix_t* y, matrix_t* x_hat, luenberger_matrices_t* matrices) {

	/*
		LUENBERGER OBSERVER
		X_hat(k) = Ax(k-1) + Bu(k-1) + L[y(k-1) - Cx(k-1)]
	*/

	// TODO
	// Be more memory efficient
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