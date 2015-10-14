#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct tableau
{
	int taille;
	int tab[100];
};
typedef struct tableau Tableau;



// PROTOTYPES //

int     alea       (int n);
Tableau initialise (Tableau T);
void    affiche    (Tableau T);
int     minimum    (Tableau T);
int     produit    (Tableau T);
Tableau decalage   (Tableau T);
Tableau trie       (Tableau T);

////////////////





int main(int argc, char **argv)
{
	srand((time)NULL);
	
	
	printf("Taille structure = %u\n", sizeof(Tableau)); // (taille du tableau * taille int) + (taille du champs 'taille') = 100*4 + 1 = 404
	

/*	int a = 0; // On initialise arbitrairement la variable a
	printf("%d\n", alea(a));	
*/
	
	Tableau T = initialise(T);
	
	affiche(T);
	printf("Elément minimum du tableau : %d\n", minimum(T));
	if (produit(T) < 0) printf("Produit trop grand"); // Evite d'afficher un produit négatif sur des entiers non signés
	else printf("Produit des éléments du tableau : %d\n", produit(T));
	
	
	// Décalage //
	T = decalage(T); 
	putchar('\n'); 
	printf("Tableau après décalage : \n"); 
	affiche(T);	
	printf("Taille du tableau après le décalage = %d\n\n", T.taille);
	
	
	// Trie //
	printf("Après trie du tableau : \n");
	T = trie(T);
	affiche(T);	
	
	
	return 0;
}




// FONCTIONS //

int alea (int n)
{
	return rand() % n;
}


Tableau initialise(Tableau T)
{
	T.taille = 10;
	int i;
	
	for(i=0; i<T.taille; i++)
	{
		T.tab[i] = alea(20);
	}
	return T;
}


void affiche(Tableau T)
{
	int i;
	for(i=0; i<T.taille; i++)
	{
		printf("%d\t", T.tab[i]);
	}
	printf("\n\n");
}


int minimum(Tableau T)
{
	int min = T.tab[0];
	
	int i;
	for(i=0; i<T.taille; i++)
	{
		if(T.tab[min] > T.tab[i])
		{
			min = i;
		}
	}
	
	return T.tab[min];
}


int produit(Tableau T)
{
	int resultat = 1;
	int i;
	
	for(i=0; i<T.taille; i++)
	{
		resultat = resultat * T.tab[i];
	}
	
	return resultat;
}


Tableau decalage(Tableau T)
{
	int i;
	
	for(i=T.taille; i>=0; i--)
	{
		T.tab[i] = T.tab[i-1];		
	}
	
	T.tab[0] = 0; // 1re case à 0
	T.taille = T.taille + 1; // Augmentation de 1 de la taille du tableau
	
	return T;	
}

/*
void echange(int *x, int *y)
{
	int z;
		
	z = *x;
	*x = *y;
	*y = z;
}
*/

Tableau trie(Tableau T)
{
	//int min = T.tab[0];
	
	
	int i, j, tmp;
	
	for(i=0; i<T.taille; i++)
		{
		for(j=0; j<T.taille; j++)
		{
			tmp = T.tab[T.taille]; 
			T.tab[T.taille] = T.tab[j];
			T.tab[j] = tmp;
		}
	}
	
	return T;
	
	
	
}
