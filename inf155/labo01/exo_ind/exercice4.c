/*
 * Fichier: exercice4.c
 * Auteur: David Muradov
 * Date: 2024-01-05
 *
 * Description: Programme qui calcule l'aire d'un cercle
 * en fonction de son rayon selon la formule A = pi * r * r
 * ou A est l'aire du cercle et r est le rayon du cercle
*/

// Commande de préprocesseur
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constante mathematique pi = 3.1415 ...
#define PI	M_PI

int main(void)
{
	double rayon; // Rayon du cercle
	double aire = 0;

	printf("Veuillez saisir le rayon du cercle: ");
	scanf("%lf", &rayon);

	aire = PI * rayon * rayon;
	printf("L'aire du cercle est: %lf\n", aire);

	return EXIT_SUCCESS;
}
