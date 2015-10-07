#include <stdio.h>

void initialise (int *tableau, int taille);
int  produit    (int *tableau, int taille);
int  minimum    (int *tableau, int taille);
void decalage   (int *tableau, int taille);


int main()
{
	int taille = 3; //100;
	
	int tableau[] = { 3, 7, 5};
	
	printf("Element du tableau : %d %d %d\n", tableau[0], tableau[1], tableau[2]);
	
	printf("Produit des éléments du tableau : %d\n", produit(tableau, taille));
	printf("Minimum du tableau = %d", minimum(tableau, taille));
	

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
	int i;
	int min = tableau[0];
	
	for(i=1; i<taille; i++)
	{
		if (min > tableau[i])
		{
			min = i;
		}	
	}
	return min;
}

void decalage (int *tableau, int taille)
{
	
}
