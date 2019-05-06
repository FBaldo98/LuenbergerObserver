#include "luenberger_observer.h"

void InitLuembergerMatrices(luenberger_matrices_t * self)
{
	// TODO
	// Matrices size as input
	InitMatrix(self->A, 6, 6, 0.0);
	InitMatrix(self->B, 6, 1, 0.0);
	InitMatrix(self->C, 2, 6, 0.0);
	InitMatrix(self->L, 6, 2, 0.0);
}
