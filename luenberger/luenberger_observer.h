#ifndef LUENBERGER_OBSERVER_H
#define LUENBERGER_OBSERVER_H

#include "../utils/matrix.h"

typedef struct luenberger_matrices_t {
	matrix_t* A;
	matrix_t* B;
	matrix_t* C;
	matrix_t* L;
} luenberger_matrices_t;

void InitLuembergerMatrices(luenberger_matrices_t *self);

#endif //!LUENBERGER_OBSERVER_H