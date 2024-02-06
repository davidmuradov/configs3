#include <stdio.h>
#include <stdlib.h>
#include "header/config.h"
#include "header/vecteur.h"

#if(MODE_APP)
int main(void) {
	double force1 = 100;
	double theta = degre_a_radian(30);
	printf("force F = %.2lf\n", force1);
	printf("angle = %.2lf\n", theta);
	return EXIT_SUCCESS;
}
#endif
