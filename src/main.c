#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "utils/matrix.h"
#include "luenberger/luenberger_observer.h"
#include <time.h>

int main() {
	matrix_t u, y, x_hat;
	luenberger_matrices_t *matrices = (luenberger_matrices_t*)malloc(sizeof(luenberger_matrices_t));

	FILE* stream = fopen("../test.csv", "r");

	char line[1024];
	double u_vals[201];
	double y_vals[201][2];
	int idx = 0;
    while (fgets(line, 1024, stream))
    {
        char* tmp = strdup(line);
		char* token = NULL;
		token = strtok(tmp, ",");
		double line_split[10];
		int i = 0;
		while( token != NULL ) {
      		line_split[i] = atof(token);

      		token = strtok(NULL, ",");
			i++;
   		}
		u_vals[idx] = line_split[2];
		y_vals[idx][0] = line_split[0];
		y_vals[idx][1] = line_split[1];

        // NOTE strtok clobbers tmp
        free(tmp);
		idx++;
    }

	fclose(stream);

	InitMatrix(&u, 1, 1, 0.0);
	InitMatrix(&y, 2, 1, 0.0);
	InitMatrix(&x_hat, 6, 1, 0.0);

	InitLuembergerMatrices(matrices);

	u.mat[0][0] = u_vals[0];
	y.mat[0][0] = y_vals[0][0];
	y.mat[1][0] = y_vals[0][1];
	
	// Example cycle
	// TODO
	// Simulate a system both in C and in Simulink
	// Verify the results
	for (int i = 1; i <= 5; ++i) {
		// This method must be called every cycle of the control
		PrintMatrix(&x_hat);
		printf("\n");
		LuenbergerObserver(&u, &y, &x_hat, matrices);

		u.mat[0][0] = u_vals[i];
		y.mat[0][0] = y_vals[i][0];
		y.mat[1][0] = y_vals[i][1];
	}

	getchar();

	return 0;
}