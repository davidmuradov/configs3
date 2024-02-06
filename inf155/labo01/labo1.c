#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Constante mathematique pi = 3.1415 ...
#define PI			M_PI

// Masse volumique de l'air
#define MASSE_VOLUMIQUE_AIR	1.2

// Acceleration en chute libre d'une sphere
#define ACCELERATION		9.81

// Constante pour ecoulement laminaire
#define CONST_LAMINAIRE		2000

// Constante pour ecoulement turbulant
#define CONST_TURBULENT		4000

// Constante pour la maigreur
#define MAIGREUR		20

// Constante pour poids normal
#define NORMAL			25

// Constante pour la surchage ponderale
#define SURCHARGE_PONDERALE	30

// Constante pour obesite
#define OBESITE			35

// Constante pour obesite severe
#define OBESITE_SEVERE		40

// fonction pour ignorer \n dans la lecture de caractere (exo15)
#define FFLUSH() 		while ((c = getchar()) != '\n' && c != EOF) { }

int exo1() {
	printf("Bonjour tous le monde\n");
}

int exo2() {
	printf("07h00 - dejeuner\n");
	printf("12h00 - diner\n");
	printf("17h00 - souper\n");
}

int exo3() {
	int entier; // Le nombre a doubler
	int entier_double = 0; // double du nombre precedent

	printf("Entrez un nombre entier a doubler: ");
	scanf("%i", &entier);

	entier_double = entier * 2;
	printf("\nLe double de %i est %i\n", entier, entier_double);
}

int exo4() {
	int entier; // Le nombre a elever au carre
	int entier_carre = 0; // nombre precedent au carre

	printf("Entrez un nombre entier: ");
	scanf("%i", &entier);

	entier_carre = entier * entier;
	printf("\nLe carre de %i est %i\n", entier, entier_carre);
}

int exo5() {
	double tension; // Tension dans le circuit
	double resistance; // Resistance dans le circuit
	double intensite = 0;

	printf("Veuillez saisir la tension du circuit (en volts): ");
	scanf("%lf", &tension);

	printf("Veuillez saisir la resistance du circuit (en ohm): ");
	scanf("%lf", &resistance);

	intensite = tension / resistance;
	printf("L'intensite du courant est: %lf A\n", intensite);
}

int exo6() {
	int nombre_article = 0; // Le nombre d'article achete
	double prix_unitaire = 0; // nombre precedent au carre
	double prix_final = 0;

	// l'usager entre le nombre d'article achete et son prix unitaire
	printf("Entrez le nombre d'item achete: ");
	scanf("%i", &nombre_article);
	printf("Entrez le prix unitaire de l'item: ");
	scanf("%lf", &prix_unitaire);

	prix_final = nombre_article * prix_unitaire * 1.15;
	printf("Avec taxe, l'achat de %i article(s) a %.2lf $/article revient a: %.2lf\n", nombre_article, prix_unitaire, prix_final);
}

int exo7() {
	double rayon; // Rayon de la sphere
	double masse; // Masse de la sphere
	double vitesse_terminale = 0;

	// l'usager entre le rayon de la sphere et sa masse
	printf("Veuillez saisir le rayon de la sphere (en metres): ");
	scanf("%lf", &rayon);
	printf("Veuillez saisir la masse de la sphere (en kilogrammes): ");
	scanf("%lf", &masse);

	double numerateur = 2.0 * masse * ACCELERATION; // numerateur dans la formule
	double denominateur = 0.5 * MASSE_VOLUMIQUE_AIR * PI * pow(rayon,2.0); // denominateur

	vitesse_terminale = sqrt(numerateur / denominateur);
	printf("La vitesse terminale de la sphere est: %lf m/s\n", vitesse_terminale);
}

int exo8() {
	int nombre_participant = 0; // le nombre de participants dans la classe
	int taille_groupe = 1; // le nombre de personnes dans un sous groupe
	int nombre_groupe_possible = 0; // le nombre de groupes possibles
	int surplus = 0; // le nombre de personnes en surplus
	
	// l'usager entre le nombre de participants et la taille des sous groupes
	printf("Entrez le nombre de participant a l'activite: ");
	scanf("%i", &nombre_participant);
	printf("Entrez la taille des groupes: ");
	scanf("%i", &taille_groupe);

	// calculs du nombre de groupes et de participants en surplus
	nombre_groupe_possible = nombre_participant / taille_groupe;
	surplus = nombre_participant - (nombre_groupe_possible * taille_groupe);

	printf("\nAvec %i participants, on peut former %i de %i personnes.\n", nombre_participant, nombre_groupe_possible, taille_groupe);
	printf("Ainsi, %i seront en surplus.\n", surplus);
}

int exo9() {
	int cents_initial = 0; // le nombre de cents a convertir
	int nombre_25_cents = 0; // le nombre de 25 cents a redonner
	int nombre_10_cents = 0; // le nombre de 10 cents a redonner
	int nombre_5_cents = 0; // le nombre de 5 cents a redonner
	int nombre_1_cents = 0; // le nombre de 1 cents a redonner

	// l'usager entre le nombre de cents a convertir
	printf("Entrez le nombre de cents a convertir: ");
	scanf("%i", &cents_initial);
	int cents = cents_initial; // on effectue les calculs sur cents

	// calculs des pieces a redonner
	nombre_25_cents = cents / 25;
	cents = cents - (nombre_25_cents * 25);

	nombre_10_cents = cents / 10;
	cents = cents - (nombre_10_cents * 10);

	nombre_5_cents = cents / 5;
	cents = cents - (nombre_5_cents * 5);

	// formattage
	printf("\nAvec %i cents, on redonne le change de la maniere suivante:\n", cents_initial);
	printf("\t- %i pieces de 25 cents\n", nombre_25_cents);
	printf("\t- %i pieces de 10 cents\n", nombre_10_cents);
	printf("\t- %i pieces de 05 cents\n", nombre_5_cents);
	printf("\t- %i pieces de 01 cents\n", cents);
}

int exo10() {
	double nombre = 0; // contient le nombre que l'usager va saisir

	printf("Entrez un nombre: ");
	scanf("%lf", &nombre);

	// calcul de la valeur absolue si nombre est negatif
	if (nombre < 0) {
		printf("\nLa valeur absolue de ce nombre est %lf\n", -1.0 * nombre);
	}
	else {
		printf("\nLa valeur absolue de ce nombre est %lf\n", nombre);
	}
}

int exo11() {
	int premier_nombre = 0; // contient le premier nombre que l'usager va saisir
	int deuxieme_nombre = 0; // contient le deuxi. nombre que l'usager va saisir

	// usager saisit les deux nombres
	printf("Entrez un premier nombre: ");
	scanf("%i", &premier_nombre);
	printf("Entrez un deuxieme nombre: ");
	scanf("%i", &deuxieme_nombre);

	// cherche la plus grande des valeurs
	if (premier_nombre >= deuxieme_nombre) {
		printf("\nLe plus grand nombre des deux est %i\n", premier_nombre);
	}
	else {
		printf("\nLe plus grand des deux nombre est %i\n", deuxieme_nombre);
	}
}

int exo12() {
	double vitesse_caracteristique = 0; // contient la vitesse caracteristique du
					    // fluide
	double dimension_caracteristique = 0; // contient la dimension caracteristique
					      // du fluide
	double viscosite_cinematique = 1; // contient la viscosite cinematique du
					  // fluide
	double nombre_reynolds = 0; // la valeur a calculer et a comparer

	// usager saisit les donnes requises
	printf("Entrez la vitesse de l'objet (en m/s): ");
	scanf("%lf", &vitesse_caracteristique);
	printf("Entrez la longueur de l'objet (en m): ");
	scanf("%lf", &dimension_caracteristique);
	printf("Entrez la viscosite du fluide (en m^2/s): ");
	scanf("%lf", &viscosite_cinematique);

	// calcul du nombre de Reynolds
	nombre_reynolds = (vitesse_caracteristique * dimension_caracteristique) / viscosite_cinematique;

	// determiner de quel type est l'ecoulement
	if (nombre_reynolds < CONST_LAMINAIRE) {
		printf("\nL'ecoulement est : laminaire\n"); // ecoulement laminaire
	}
	else if (nombre_reynolds > CONST_TURBULENT) {
		printf("\nL'ecoulement est : turbulent\n"); // ecoulement turbulent
	}
	else {
		printf("\nL'ecoulement est : transitoire\n"); // ecoulement transit.
	}
}

int exo13() {
	int coordonnee_x = 0; // contient la coordonne x du point
	int coordonnee_y = 0; // contient la coordonne y du point

	// usager saisit les coordonnes
	printf("Entrez la coordonnee en x du point: ");
	scanf("%i", &coordonnee_x);
	printf("Entrez la coordonnee en y du point: ");
	scanf("%i", &coordonnee_y);

	// deterimation du quadrant du point (x,y)
	if (coordonnee_x > 0) {
		if (coordonnee_y > 0) {
			printf("\nLe point saisit est dans le quadrant I\n");
		}
		else if (coordonnee_y < 0) {
			printf("\nLe point saisit est dans le quadrant IV\n");
		}
		else {
			printf("\nLe point saisit est sur l'axe des absices\n");
		}
	}
	else if (coordonnee_x < 0) {
		if (coordonnee_y > 0) {
			printf("\nLe point saisit est dans le quadrant II\n");
		}
		else if (coordonnee_y < 0) {
			printf("\nLe point saisit est dans le quadrant III\n");
		}
		else {
			printf("\nLe point saisit est sur l'axe x\n");
		}
	}
	else {
		if (coordonnee_y == 0) {
			printf("\nLe point saisit est l'origine\n");
		}
		else {
			printf("\nLe point saisit est sur l'axe y\n");
		}
	}
}

int exo14() {
	double poids = 0; // contient le poids de l'usager
	double taille = 1; // contient la taille de l'usager
	double imc = 0;

	// usager saisit les donnees
	printf("Entrez votre taille en m: ");
	scanf("%lf", &taille);
	printf("Entrez votre poids en kg: ");
	scanf("%lf", &poids);

	// calcul de l'imc
	imc = poids / pow(taille, 2.0);

	// determination de la categorie de poids
	if (imc < MAIGREUR) {
		printf("Votre categorie de poids est : Maigreur\n");
	}
	else if (imc >= MAIGREUR && imc < NORMAL) {
		printf("Votre categorie de poids est : Normal\n");
	}
	else if (imc >= NORMAL && imc < SURCHARGE_PONDERALE) {
		printf("Votre categorie de poids est : Surcharge ponderale\n");
	}
	else if (imc >= SURCHARGE_PONDERALE && imc < OBESITE) {
		printf("Votre categorie de poids est : Obesite\n");
	}
	else {
		printf("Votre categorie de poids est : Obesite severe\n");
	}
}

int exo15() {
	char initiale_prenom; // contient l'initiale du prenom
	char initiale_nom; // contient l'initiale du nom
	int c;		   // utile pour clear les \n dans les lecture de caractere

	// usager saisit l'initiale du prenom
	printf("Entrez l'initiale de votre prenom: ");
	scanf("%c", &initiale_prenom);
	FFLUSH();

	// on verifie si la donnee rentree est un espace
	if (initiale_prenom == ' ') {
		printf("\nCommande de sortie\n");
		return EXIT_SUCCESS;
	}

	// usager saisit l'initiale du nom
	printf("Entrez l'initiale de votre nom: ");
	scanf("%c", &initiale_nom);
	FFLUSH();

	// on verifie si la donnee rentree est un espace
	if (initiale_nom == ' ') {
		printf("\nCommande de sortie\n");
		return EXIT_SUCCESS;
	}

	// resultat final
	printf("\nBienvenue en INF155 %c.%c. !\n", initiale_prenom, initiale_nom);
}

int main(void) {
	exo15();
	return EXIT_SUCCESS;
}
