/*
 * Fichier: exercice6.c
 * Auteur: David Muradov
 * Date: 2024-01-05
 *
 * Description: Programme qui lit trois caracteres au clavier un a la suite de
 * l'autre et qui les affiche un a la suite de l'autre sur la meme ligne.
*/

// Commande de préprocesseur
#include <stdio.h>
#include <stdlib.h>

// Macro pour 
#define FFLUSH() do{} while (getchar() != '\n')

int main(void)
{
	char caractere_courant = ' '; // Contient le caractere saisit par l'usager

	printf("Veuillez saisir le premier caractere: ");
	scanf("%c", &caractere_courant);
	//FFLUSH();

	return EXIT_SUCCESS;
}
