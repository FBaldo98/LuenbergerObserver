#include <stdio.h>
#include "utils/matrix.h"
#include "luenberger/luenberger_observer.h"

int main() {
	matrix_t u, y, x_hat;
	luenberger_matrices_t *matrices = (luenberger_matrices_t*)malloc(sizeof(luenberger_matrices_t));

	InitMatrix(&u, 1, 1, 0.0);
	InitMatrix(&y, 2, 1, 0.0);
	InitMatrix(&x_hat, 6, 1, 0.0);

	InitLuembergerMatrices(matrices);

	// TODO
	// Some testing code, with simulated input. Compare results with Matlab

	// This method must be called every cycle of the control
	LuenbergerObserver(&u, &y, &x_hat, matrices);

	return 0;
}