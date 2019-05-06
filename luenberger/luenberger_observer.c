#include "luenberger_observer.h"

void InitLuembergerMatrices(luenberger_matrices_t * self)
{
	// TODO
	// Matrices size as input
	InitMatrix(self->A, 6, 6, 0.0);
	InitMatrix(self->B, 6, 1, 0.0);
	InitMatrix(self->C, 2, 6, 0.0);
	InitMatrix(self->L, 6, 2, 0.0);

	InitMatrix(u_prev, 1, 1, 0.0);
	InitMatrix(x_prev, 6, 1, 0.0);
	InitMatrix(y_prev, 2, 1, 0.0);
}
