#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// fonction pour ignorer \n dans la lecture de caractere (exo15)
#define FFLUSH() 	while ((c = getchar()) != '\n' && c != EOF) { }

// valeurs booleennes
#define TRUE		1
#define FALSE		0

// degree daproximation de la fonction arctan
#define DEGREE_ARCTAN	1000

// nombre de fois que le de est lance
#define MILLION		1000000

// fonction distance calcule la distance euclidienne entre deux points
// p(x1,y1) et p(x2,y2) sur un plan dans R^2
double distance(const double x1, const double y1, const double x2, const double y2) {
	double distance_en_x = x2 - x1;
	double distance_en_y = y2 - y1;
	double distance = sqrt(pow(distance_en_x, 2.0) + pow(distance_en_y, 2.0));

	return distance;
}

// fonction estPremier determine si le nombre entree est un nombre premier
// Retourne 1 (TRUE) si le nombre est premier et 0 (FALSE) si le nombre ne l'est pas
int estPremier(const int nombre) {
	int quantite_de_diviseurs = 0;
	int estpremier;
	
	if (nombre == 0) {
		estpremier = 0;
	}
	else if (nombre == 1) {
		estpremier = 1;
	}
	else {
		for (int i = 1; i <= nombre; i++) {
			if (nombre % i == 0) {
				quantite_de_diviseurs += 1;
			}
			if (quantite_de_diviseurs > 2) {
				estpremier = 0;
				break;
			}
		}
		if (quantite_de_diviseurs == 2) {
			estpremier = 1;
		}
	}
	return estpremier;
}

int nb_aleatoire(int min, int max) {
	return min + (int)(rand() / (RAND_MAX + 0.001) * (max - min + 1));
}

void exo1() {
	double poids = 0;
	int age = 0;

	printf("Entrer l'age du participant: ");
	scanf("%i", &age);
	printf("Entrer le poids du participant: ");
	scanf("%lf", &poids);

	if (age >= 15 && poids >= 40.0) {
		printf("Participant peut participer");
	}
	else {
		printf("Participant ne peut pas participer\n");
	}
}

void exo2() {
	int premier_nombre = 0;
	int deuxieme_nombre = 0;

	printf("Enter le premier nombre: ");
	scanf("%i", &premier_nombre);
	printf("Enter le deuxieme nombre: ");
	scanf("%i", &deuxieme_nombre);

	if (premier_nombre % 2 == 0 && deuxieme_nombre % 2 == 0) {
		printf("Les deux nombres sont pairs\n");
	}
	else if (premier_nombre % 2 != 0 && deuxieme_nombre % 2 != 0) {
		printf("Les deux nombres sont impairs\n");
	}
	else {
		printf("Un des nombres et pair et l'autre est impair\n");
	}
}

void exo3() {
	int c; // pour fonction FFLUSH()

	// coordonnnees des points
	double x1, y1 = 0; // coord. pour p1
	double x2, y2 = 0; // coord. pour p2
	double x3, y3 = 0; // coord. pour p3

	double distance_p1p2 = 0;
	double distance_p2p3 = 0;
	double distance_p3p1 = 0;

	// usager entre les donnees
	printf("Entrer les coordonees du premier point sous la forme (x, y): ");
	scanf("(%lf, %lf)", &x1, &y1);
	FFLUSH();
	printf("Entrer les coordonees du deuxieme point sous la forme (x, y): ");
	scanf("(%lf, %lf)", &x2, &y2);
	FFLUSH();
	printf("Entrer les coordonees du troisieme point sous la forme (x, y): ");
	scanf("(%lf, %lf)", &x3, &y3);

	// calcul des distances
	distance_p1p2 = distance(x1, y1, x2, y2);
	distance_p2p3 = distance(x2, y2, x3, y3);
	distance_p3p1 = distance(x3, y3, x1, y1);

	// calcul des conditions
	if (distance_p1p2 == distance_p2p3 && distance_p2p3 == distance_p3p1) {
		printf("Le triangle est equilateral\n");
	}
	if (distance_p1p2 != distance_p2p3 && distance_p2p3 != distance_p3p1 && distance_p3p1 != distance_p1p2) {
		printf("Le triangle est scalene\n");
	}
	else {
		printf("Le triangle est isocele\n");
	}
}

void exo4() {
	int valeur_limite = 0;
	int valeur_pair_max = 0;

	printf("Entrer la limite des nombres: ");
	scanf("%i", &valeur_limite);

	// petit calcul pour ameliorer l'affichage au dernier entier imprime
	if (valeur_limite % 2 == 0) {
		valeur_pair_max = valeur_limite;
	}
	else {
		valeur_pair_max = valeur_limite - 1;
	}

	printf("Les nombres pairs sont: ");

	// calcul des nombres pair et amelioration affichage au dernier calcul
	for (int i = 0; i <= valeur_limite; i++) {
		if (i == valeur_pair_max) {
			printf("%d\n", i);
			break;
		}
		else if (i % 2 == 0) {
			printf("%d, ", i);
		}
	}
}

void exo5() {
	int nombre = 0; // usager entre ce nombre
	
	// affichage et usager entre la valeur
	printf("Entrer le nombre a analyser: ");
	scanf("%i", &nombre);

	if (nombre == 0) {
		printf("0 est le diviseur nul\n");
	}
	else if (nombre < 0) {
		printf("Erreur: nombre negatif\n");
	}
	else {
		printf("1 est un diviseur de %i\n", nombre);
		for (int i = 2; i <= nombre / 2; i++) {
			if (nombre % i == 0) {
				printf("%i est un diviseur de %i\n", i, nombre);
			}

		}

	}
}

void exo6() {
	int nombre = 0; // usager entre ce nombre
	int quantite_de_diviseurs = 0;
	
	// affichage et usager entre la valeur
	printf("Entrer le nombre a analyser: ");
	scanf("%i", &nombre);

	if (nombre == 0) {
		printf("Le nombre n'est pas premier\n");
	}
	else if (nombre < 0) {
		printf("Erreur: nombre negatif\n");
	}
	else if (nombre == 1) {
		printf("Le nombre est premier\n");
	}
	else {
		for (int i = 1; i <= nombre; i++) {
			if (nombre % i == 0) {
				quantite_de_diviseurs += 1;
			}
			if (quantite_de_diviseurs > 2) {
				printf("Le nombre n'est pas premier\n");
				break;
			}
		}
		if (quantite_de_diviseurs == 2) {
			printf("Le nombre est premier\n");
		}
	}
}

void exo7() {
	int nombre_limite = 0;

	// usager rentre le nombre limite
	printf("Quel est le nombre limite: ");
	scanf("%i", &nombre_limite);

	for (int i = 0; i <= nombre_limite; i++) {
		if (estPremier(i) == 1) {
			printf(" %i ", i);
		}
	}
	printf("\n");
}

void exo8() {
	int nombre = 0;

	while (TRUE) {
		printf("Entrer une valeur entre [1; 100]: ");
		scanf("%i", &nombre);

		if (nombre >= 1 && nombre <= 100) {
			printf("Le nombre entre est: %i\n", nombre);
			break;
		}
		else if (nombre < 1) {
			printf("La valeur entree est trop petite\n\n");
		}
		else {
			printf("La valeur entree est trop grande\n\n");
		}
	}
}

void exo9() {
	int nombre = 0;
	int puissance_dix = 1;
	int reste = 0;
	int chiffres_present = 1;

	printf("Entrer une valeur: ");
	scanf("%i", &nombre);

	while (TRUE) {
		reste = nombre % puissance_dix;
		if (nombre == 0) {
			printf("Il y a %i chiffre(s) dans la valeur %i\n", chiffres_present, nombre);
			break;
		}
		else if (reste == nombre) {
			chiffres_present -= 1;
			printf("Il y a %i chiffre(s) dans la valeur %i\n", chiffres_present, nombre);
			break;
		}
		chiffres_present += 1;
		puissance_dix *= 10;
	}
}

void exo10() {
	double radian = 0;
	double arctan_de_x = 0;

	printf("Entrer la valeur de x en radian: ");
	scanf("%lf", &radian);

	for (int iterations = 1; iterations <= DEGREE_ARCTAN; iterations++) {
		arctan_de_x += pow(-1, iterations - 1) * pow(radian, 2 * iterations - 1) / (2 * iterations - 1);
	}
	printf("arctan(%lf) = %lf\n", radian, arctan_de_x);
}

void exo11() {
	double facteur_de_modification = 1;
	double approximation_pi_sur_2 = 1;
	double premier_terme = 0;
	double deuxieme_terme = 0;
	double epsilon = 1;
	int indice = 0;

	while (facteur_de_modification >= 0.00001) {
		premier_terme = ((2.0 * (double) indice) + 2) / (2.0 * (double) indice + 1);
		deuxieme_terme = (2.0 * indice + 2) / (2.0 * indice + 3);
		epsilon = approximation_pi_sur_2;
		approximation_pi_sur_2 *= premier_terme * deuxieme_terme;
		facteur_de_modification = approximation_pi_sur_2 - epsilon;
		indice++;
	}
	printf("%lf\n", 2 * approximation_pi_sur_2);
}

void exo12() {
	srand((unsigned int) time(NULL));
	rand();

	int nombre_de;

	for (int i = 1; i <= 5; i++) {
		nombre_de = nb_aleatoire(1,6);
		printf("Lancer No%i: %i\n", i, nombre_de);
	}
}

void exo13() {
	srand((unsigned int) time(NULL));
	rand();

	int nombre_de;
	double moyenne;
	double somme_cumulative = 0;

	for (int i = 1; i <= MILLION; i++) {
		nombre_de = nb_aleatoire(1,6);
		somme_cumulative += nombre_de;
	}
	moyenne = somme_cumulative / MILLION;
	printf("La moyenne des lances des des est: %lf\n", moyenne);
}

void exo14() {
	srand((unsigned int) time(NULL));
	rand();

	int nombre_premier_de;
	int nombre_deuxieme_de;
	int somme_des;
	int nombre_de_7 = 0;
	double probabilite;
	
	for (int i = 1; i <= MILLION; i++) {
		nombre_premier_de = nb_aleatoire(1,6);
		nombre_deuxieme_de = nb_aleatoire(1,6);
		somme_des = nombre_premier_de + nombre_deuxieme_de;

		if (somme_des == 7) {
			nombre_de_7 += 1;
		}
	}

	probabilite = (double) nombre_de_7 / MILLION;
	printf("La probabilite d'obtenir 7 est: %lf\n", probabilite);
}

int main(void) {
	exo14();
	return EXIT_SUCCESS;
}
