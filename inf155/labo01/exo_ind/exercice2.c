#include <stdio.h>
#include <stdlib.h>

#define CONVERSION_WATT_CALORIE_PAR_SECONDE	0.2388459

int main(void)
{
	double watts; // Contient le nombre de watts a convertir
	double calorie_par_seconde = 0;

	printf("Saisir la quantite de watts a convertir: ");
	scanf("%lf", &watts);

	calorie_par_seconde = watts * CONVERSION_WATT_CALORIE_PAR_SECONDE;

	printf("%lf watts equivaut a %lf calories par seconde.\n", watts, calorie_par_seconde);

	return EXIT_SUCCESS;
}
