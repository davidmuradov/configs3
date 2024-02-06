#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// fonction pour ignorer \n dans la lecture de caractere (exo15)
#define FFLUSH() 	while ((c = getchar()) != '\n' && c != EOF) { }

// Tests
#define APPLICATION	1
#define TEST		0

// valeurs booleennes
#define TRUE		1
#define FALSE		0

#if(TEST)
// Declaration des fonctions
void test_exo1(void);
void test_exo2(void);
void test_exo3(void);
double calculer_aire_cercle(const double rayon);
double calculer_aire_rectangle(const double longueur, const double largeur);
double calculer_aire_piece(const double longueur, const double largeur, const double rayon);

/*					*/
/*		MAIN FUNCTION		*/
/*					*/
int main(void) {
	test_exo3();
	return EXIT_SUCCESS;
}

// Definitions des fonctions calculees
double calculer_aire_cercle(const double rayon) {
	double aire = M_PI * rayon * rayon;
	return aire;
}

double calculer_aire_rectangle(const double longueur, const double largeur) {
	double aire = longueur * largeur;
	return aire;
}

double calculer_aire_piece(const double longueur, const double largeur, const double rayon) {
	double diametre = 2 * rayon;
	double aire;

	if (diametre > longueur || diametre > largeur) {
		aire = 0;
	}

	else {
		double aire_cercle = calculer_aire_cercle(rayon);
		double aire_rectangle = calculer_aire_rectangle(longueur, largeur);
		aire = aire_rectangle - aire_cercle;
	}
	return aire;
}

// FONCTIONS DES TESTS
void test_exo1(void) {
	int test = 1;
	double v1 = 1.0;
	double attendue, obtenue;

	attendue = 3.14;
	obtenue = calculer_aire_cercle(v1);

	printf("\n--- TEST CALCULER AIRES CERCLES ---\n\n");
	printf("TEST %i - Donnee\t : %.2lf\n", test, v1);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);

	test += 1;
	v1 = 2.0;
	attendue = 12.57;
	obtenue = calculer_aire_cercle(v1);

	printf("TEST %i - Donnee\t : %.2lf\n", test, v1);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);

	test += 1;
	v1 = 3.5;
	attendue = 38.48;
	obtenue = calculer_aire_cercle(v1);

	printf("TEST %i - Donnee\t : %.2lf\n", test, v1);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);
}

void test_exo2(void) {
	int test = 1;
	double v1 = 2.0;
	double v2 = 1.5;
	double attendue, obtenue;

	attendue = 3.00;
	obtenue = calculer_aire_rectangle(v1, v2);

	printf("\n--- TEST CALCULER AIRES RECTANGLES ---\n\n");
	printf("TEST %i - Donnee\t : %.2lf, %.2lf\n", test, v1, v2);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);

	test += 1;
	v1 = 2.5;
	v2 = 3.0;
	attendue = 7.5;
	obtenue = calculer_aire_rectangle(v1, v2);

	printf("TEST %i - Donnee\t : %.2lf, %.2lf\n", test, v1, v2);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);

	test += 1;
	v1 = 2.5;
	v2 = 1.5;
	attendue = 3.75;
	obtenue = calculer_aire_rectangle(v1, v2);

	printf("TEST %i - Donnee\t : %.2lf, %.2lf\n", test, v1, v2);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);
}

void test_exo3(void) {
	int test = 1;
	double v1 = 3.0; // longueur
	double v2 = 1.0; // largeur
	double v3 = 1.0; // rayon
	double attendue, obtenue;

	attendue = 0;
	obtenue = calculer_aire_piece(v1, v2, v3);

	printf("\n--- TEST CALCULER AIRES PIECES ---\n\n");
	printf("TEST %i - Donnee\t : %.2lf, %.2lf, %.2lf\n", test, v1, v2, v3);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);

	test += 1;
	v1 = 1.0;
	v2 = 3.0;
	v3 = 1.0;
	attendue = 0.0;
	obtenue = calculer_aire_piece(v1, v2, v3);

	printf("TEST %i - Donnee\t : %.2lf, %.2lf, %.2lf\n", test, v1, v2, v3);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);

	test += 1;
	v1 = 4.5;
	v2 = 3.5;
	v3 = 1.5;
	attendue = 8.68;
	obtenue = calculer_aire_piece(v1, v2, v3);

	printf("TEST %i - Donnee\t : %.2lf, %.2lf, %.2lf\n", test, v1, v2, v3);
	printf("Valeur attendue\t : %.2lf\n", attendue);
	printf("Valeur obtenue\t : %.2lf\n\n", obtenue);
}
#endif

#if(APPLICATION)
// Exo
void exo1(void);
void exo2(void);
void exo3(void);
void exo4(void);
void exo5(void);

// Fonctions
double calculer_aire_cercle(const double rayon);
double calculer_aire_rectangle(const double longueur, const double largeur);
double calculer_aire_piece(const double longueur, const double largeur, const double rayon);
double solde_apres_paiement(const double solde_hypotheque, const double montant_mensuel, const double taux_interet);
void relever_compte(const double solde_hypotheque, const double montant_mensuel, const double taux_interet);

int main(void) {
	exo5();
	return EXIT_SUCCESS;
}

void exo1() {
	double aire = calculer_aire_cercle(2);
	printf("%lf\n", aire);
}

void exo2() {
	double aire = calculer_aire_rectangle(2.5, 1.5);
	printf("%lf\n", aire);
}

void exo3() {
	double aire = calculer_aire_piece(5.0, 4.5, 1.5);
	printf("%lf\n", aire);
}

void exo4() {
	double solde = solde_apres_paiement(637.36, 2500, 0.012);
	printf("%.2lf\n", solde);
}

void exo5() {
	double montant_hypotheque;
	double montant_interet;
	double montant_paiement_mensuel;

	printf("Quel est le montant de l'hypotheque : ");
	scanf("%lf", &montant_hypotheque);
	printf("Quel est le montant du taux d'interet annuel : ");
	scanf("%lf", &montant_interet);
	printf("Quel est le montant du paiement mensuel : ");
	scanf("%lf", &montant_paiement_mensuel);
	printf("\n\n\n");
	relever_compte(montant_hypotheque, montant_paiement_mensuel, montant_interet);
}

void relever_compte(const double solde_hypotheque, const double montant_mensuel, const double taux_interet) {
	int mois = 1;
	double solde = solde_hypotheque;

	printf("Solde initial : %.2lf $ @ %.3lf %%\n", solde_hypotheque, taux_interet);
	printf("-------------------------------------\n");
	printf("No Mois\t | Solde\n");

	// dans loop
	while (solde != 0) {
		solde = solde_apres_paiement(solde, montant_mensuel, taux_interet);
		printf("%8i | %.2lf\n", mois, solde);
		mois++;
	}
}

double calculer_aire_cercle(const double rayon) {
	double aire = M_PI * rayon * rayon;
	return aire;
}

double calculer_aire_rectangle(const double longueur, const double largeur) {
	double aire = longueur * largeur;
	return aire;
}

double calculer_aire_piece(const double longueur, const double largeur, const double rayon) {
	double diametre = 2 * rayon;
	double aire;

	if (diametre > longueur || diametre > largeur) {
		aire = 0;
	}

	else {
		double aire_cercle = calculer_aire_cercle(rayon);
		double aire_rectangle = calculer_aire_rectangle(longueur, largeur);
		aire = aire_rectangle - aire_cercle;
	}
	return aire;
}

double solde_apres_paiement(const double solde_hypotheque, const double montant_mensuel, const double taux_interet) {
	double montant_interet_du = solde_hypotheque * taux_interet / 12;
	double paiement = montant_mensuel - montant_interet_du;
	double solde = solde_hypotheque - paiement;

	if (solde <= 0) {
		solde = 0;
	}

	return solde;
}
#endif
