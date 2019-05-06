#ifndef LUENBERGER_OBSERVER_H
#define LUENBERGER_OBSERVER_H

#include "../utils/matrix.h"

typedef struct luenberger_matrices_t {
	matrix_t* A;
	matrix_t* B;
	matrix_t* C;
	matrix_t* L;
} luenberger_matrices_t;

matrix_t* x_prev; // 6x1
matrix_t* u_prev; // 1x1
matrix_t* y_prev; // 2x1

void InitLuembergerMatrices(luenberger_matrices_t *self);

void LuenbergerObserver(matrix_t* u, matrix_t* y, matrix_t* x_hat, luenberger_matrices_t* matrices);

#endif //!LUENBERGER_OBSERVER_H