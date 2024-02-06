/*
 * Fichier: exercice3.c
 * Auteur: David Muradov
 * Date: 2024-01-05
 *
 * Description: Programme qui calcule l'intensite du courant
 * en fonction de la tension et de la resistance selon la formule
 * I = V/R ou I est l'intensite, V est la tension et R est la resistance.
*/

// Commande de préprocesseur
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	double tension; // Tension dans le circuit
	double resistance; // Resistance dans le circuit
	double intensite = 0;

	printf("Veuillez saisir la tension du circuit (en volts): ");
	scanf("%lf", &tension);

	printf("Veuillez saisir la resistance du circuit (en ohm): ");
	scanf("%lf", &resistance);

	intensite = tension / resistance;
	printf("L'intensite du courant est: %lf A\n", intensite);

	return EXIT_SUCCESS;
}
