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

	/*
	L =

		1.0e+04 *

		0.0001    0.0010
		0.0051    0.0541
		0.0000    0.0013
		0.0024    0.0870
		0.0059    0.0489
		- 0.0324 - 1.0508
	*/

	InitMatrix(self->L, 6, 2, 0.0);
	self->L->mat[0][0] = 1.0;
	self->L->mat[0][1] = 10.0;
	self->L->mat[1][0] = 51.0;
	self->L->mat[1][1] = 541.0;
	self->L->mat[2][1] = 13.0;
	self->L->mat[3][0] = 24.0;
	self->L->mat[3][1] = 870.0;
	self->L->mat[4][0] = 59.0;
	self->L->mat[4][1] = 489.0;
	self->L->mat[5][0] = -324.0;
	self->L->mat[5][1] = -10508.0;

	x_prev = (matrix_t*)malloc(sizeof(matrix_t));
	InitMatrix(x_prev, 6, 1, 0.0);
}

int LuenbergerObserver(matrix_t* u, matrix_t* y, matrix_t* x_hat, luenberger_matrices_t* matrices) {

	/*
		LUENBERGER OBSERVER
		X_hat(k+1) = Ax(k) + Bu(k) + L[y(k) - Cx(k)]
	*/
	int ret = 0;
	// TODO
	// Be more memory efficient
	matrix_t res_1, res_2, y_hat, res_3, res_4, res_5, res_6;

	// Ax(k)
	ret = MatrixMultiplication(matrices->A, x_hat, &res_1);
	// Bu(k)
	ret = MatrixMultiplication(matrices->B, u, &res_2);

	// L[y(k) - Cx(k)]
	ret = MatrixMultiplication(matrices->C, x_hat, &y_hat);
	ret = MatrixSubtraction(y, &y_hat, &res_3);
	ret = MatrixMultiplication(matrices->L, &res_3, &res_4);

	ret = MatrixSum(&res_1, &res_2, &res_5);
	ret = MatrixSum(&res_5, &res_4, &res_6);

	CopyMatrixValues(&res_6, x_hat);
	//CopyMatrixValues(x_hat, x_prev);
	
	return ret;

}