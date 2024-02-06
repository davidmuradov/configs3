/*
 * Fichier: exercice0.c
 * Auteur: David Muradov
 * Date: 2024-01-05
 *
 * Description: Programme qui calcule l'age
*/

// Commande de préprocesseur
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	int annee_actuelle; // Annee de la date actuelle
	int annee_naissance; // Annee de naissance de l'usager
	int age = 0;

	printf("Veuillez saisir l'annee actuelle: ");
	scanf("%d", &annee_actuelle);

	printf("Veuillez saisir votre annee de naissance: ");
	scanf("%d", &annee_naissance);

	age = annee_actuelle - annee_naissance;
	printf("Vous avez %d ans.\n", age);

	system("pause");
	return EXIT_SUCCESS;
}
