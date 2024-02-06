#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

// fonction pour ignorer \n dans la lecture de caractere (exo15)
#define FFLUSH() 	while ((c = getchar()) != '\n' && c != EOF) { }

// valeurs booleennes
#define TRUE		1
#define FALSE		0

void exo7(void);

double solde_apres_paiement(const double solde_hypotheque, double* addr_montant_mensuel, const double taux_interet, double* addr_interet_paye, double* remboursement);
void relever_compte(const double solde_hypotheque, double* addr_montant_mensuel, const double taux_interet, double* addr_interet_paye, double* remboursement);

int main(void) {
	exo7();
	return EXIT_SUCCESS;
}

void exo7() {
	double montant_hypotheque;
	double montant_interet;
	double montant_paiement_mensuel;
	double* addr_montant_paiement_mensuel = &montant_paiement_mensuel;
	double interet_paye = 0;
	double* addr_interet_paye = &interet_paye;
	double remboursement = 0;
	double* addr_remboursement = &remboursement;

	printf("Quel est le montant de l'hypotheque : ");
	scanf("%lf", &montant_hypotheque);
	printf("Quel est le montant du taux d'interet annuel : ");
	scanf("%lf", &montant_interet);
	printf("Quel est le montant du paiement mensuel : ");
	scanf("%lf", &montant_paiement_mensuel);
	printf("\n\n\n");
	relever_compte(montant_hypotheque, addr_montant_paiement_mensuel, montant_interet, addr_interet_paye, addr_remboursement);
}

void relever_compte(const double solde_hypotheque, double* addr_montant_mensuel, const double taux_interet, double* addr_interet_paye, double* remboursement) {
	int mois = 1;
	double solde = solde_hypotheque;
	(*remboursement) = solde;

	printf("\t Solde initial : %.2lf $ @ %.3lf %%\n", solde_hypotheque, taux_interet);
	printf("------------------------------------------------------------\n");
	printf(" No Mois | Paiement  |  Interet |  Remboursement | Solde\n");

	// dans loop
	while (solde != 0) {
		solde = solde_apres_paiement(solde, addr_montant_mensuel, taux_interet, addr_interet_paye, remboursement);
		printf("%8i | %8.2lf  | %8.2lf | %14.2lf | %9.2lf\n", mois, *addr_montant_mensuel, *addr_interet_paye, *remboursement, solde);
		mois++;
	}
}

double solde_apres_paiement(const double solde_hypotheque, double* addr_montant_mensuel, const double taux_interet, double* addr_interet_paye, double* remboursement) {
	double montant_interet_du = solde_hypotheque * taux_interet / 12;
	(*addr_interet_paye) = montant_interet_du;
	double paiement = (*addr_montant_mensuel) - montant_interet_du;
	double solde = solde_hypotheque - paiement;
	(*remboursement) = solde_hypotheque - solde;

	if (solde <= 0) {
		(*addr_montant_mensuel) += solde;
		(*remboursement) = (*addr_montant_mensuel) - (*addr_interet_paye);
		solde = 0;
	}
	return solde;
}
