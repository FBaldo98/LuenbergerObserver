#include <stdio.h>
#include "utils\matrix.h"

int main() {
	matrix_t mat_1;
	InitMatrix(&mat_1, 3, 3);

	for (int i = 0; i < 3; ++i)
		printf("%.1f\t%.1f\t%.1f\n", mat_1.mat[i][0], mat_1.mat[i][0], mat_1.mat[i][0]);

	getchar();

	return 0;
}