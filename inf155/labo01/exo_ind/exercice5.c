/*
 * Fichier: exercice5.c
 * Auteur: David Muradov
 * Date: 2024-01-05
 *
 * Description: Programme qui calcule la vitesse terminale d'un objet spherique
 * en chute libre en fonction de sa masse et de son rayon selon la formule
 * v = sqrt(2 * m * g / 0.5 * rho * pi * r**2) ou v est la vitesse terminale,
 * m est la masse de la sphere et r est le rayon de la sphere
*/

// Commande de préprocesseur
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constante mathematique pi = 3.1415 ...
#define PI			M_PI

// Masse volumique de l'air
#define MASSE_VOLUMIQUE_AIR	1.2

// Acceleration en chute libre d'une sphere
#define ACCELERATION		9.81

int main(void)
{
	double rayon; // Rayon de la sphere
	double masse; // Masse de la sphere
	double vitesse_terminale = 0;

	printf("Veuillez saisir le rayon de la sphere (en metres): ");
	scanf("%lf", &rayon);

	printf("Veuillez saisir la masse de la sphere (en kilogrammes): ");
	scanf("%lf", &masse);

	double numerateur = 2.0 * masse * ACCELERATION; // numerateur dans la formule
	double denominateur = 0.5 * MASSE_VOLUMIQUE_AIR * PI * pow(rayon,2.0); // denominateur

	vitesse_terminale = sqrt(numerateur / denominateur);
	printf("La vitesse terminale de la sphere est: %lf m/s\n", vitesse_terminale);

	return EXIT_SUCCESS;
}
