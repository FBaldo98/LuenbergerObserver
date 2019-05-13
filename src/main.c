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

	u.mat[0][0] = 0.7;
	y.mat[0][0] = 0.7;

	// Example cycle
	// TODO
	// Simulate a system both in C and in Simulink
	// Verify the results
	for (int i = 0; i < 4; ++i) {

		printf("U: %.2f\n", u.mat[0][0]);
		printf("Y:\n");
		PrintMatrix(&y);

		// This method must be called every cycle of the control
		LuenbergerObserver(&u, &y, &x_hat, matrices);

		printf("\n");
		PrintMatrix(&x_hat);
	}

	getchar();

	return 0;
}