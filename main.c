#include <stdio.h>
#include "utils\matrix.h"

int main() {
	matrix_t mat_1, mat_2, mat_3, res, res2;
	InitMatrix(&mat_1, 3, 4, 2.0);
	InitMatrix(&mat_2, 4, 3, 2.0);
	InitMatrix(&mat_3, 4, 4, 2.0);

	PrintMatrix(&mat_1);
	printf("\n\n");
	PrintMatrix(&mat_2);

	printf("Multiplication\n");
	MatrixMultiplication(&mat_1, &mat_2, &res);
	PrintMatrix(&res);

	printf("Sum\n");
	MatrixSum(&res, &mat_3, &res2);
	PrintMatrix(&res2);

	getchar();

	return 0;
}