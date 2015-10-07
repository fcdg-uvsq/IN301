#include <stdio.h>

void initialise (int *tableau, int taille);
void affiche    (int *tableau, int taille);
int  produit    (int *tableau, int taille);
int  minimum    (int *tableau, int taille);
void decalage   (int *tableau, int taille);


int main()
{
	int taille = 6;
	int tableau[] = { 3, 7, 12, 9, 1, 4};
	
	
	affiche(tableau, taille);
	
	printf("Produit des éléments du tableau : %d\n", produit(tableau, taille));
	printf("Minimum du tableau = %d\n", minimum(tableau, taille));
	printf("Effet du décalage : ");
	decalage(tableau, taille);
	affiche(tableau, taille);
	

	return 0;
}


void initialise(int *tableau, int taille)
{
	int i;
	for(i=0; i<taille; i++)
	{
		tableau[i] = 1;
	}	
}

void affiche(int *tableau, int taille)
{
	int i;
	//char message[] = "Eléments du tableau : "; puts(message);
	for(i=0; i<taille; i++)
	{
		printf("%d\t", tableau[i]);
	}
	putchar('\n');	
}


int produit(int *tableau, int taille)
{
	int i;
	int resultat = 1;
	
	for(i=0; i<taille; i++)
	{
		resultat = resultat * tableau[i];		
	}
	return resultat;
}


int minimum (int *tableau, int taille)
{
	int i = 1;
	int min = tableau[0];
	
	while (i<taille)
	{
		if (min > tableau[i])
		{
			min = tableau[i];
		}
		i++;
	}
	return min;
}


void decalage (int *tableau, int taille)
{
	tableau[0] = 0;
	tableau[taille] = -1;
	
	int i;
	
	for(i=1; i<=taille-1; i++) // On commence à 1 car la 1re case (tableau[0]) vaut déjà 0 et la dernière est supprimée (-1)
	{
		tableau[i] = tableau[i+1];		
	}
}
