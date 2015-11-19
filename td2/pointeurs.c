#include <stdio.h>

void permute (int *x, int *y);
void reinitPointeur (int** p);

int main(int argc, char **argv)
{	
	// QUESTION a) // 
	
	printf("char :   %u\n", sizeof(char));
	printf("int :    %u\n", sizeof(int));
	printf("float :  %u\n", sizeof(float));
	printf("double : %u\n", sizeof(double)); //nombre à virgule plus précis qu'un float

	
	// La taille de l'adresse est invariante selon le type vers lequel le pointeur pointe
	printf("char* :  %u\n", sizeof(char*));
	printf("void* :  %u\n", sizeof(void*));
	printf("int* :   %u\n", sizeof(int*));
	printf("double*  %u\n", sizeof(double*));	
	printf("int** :  %u\n", sizeof(int**));	
	
	
	printf("int[10] :    %u\n",   sizeof(int[10]));	
	printf("char[7][3] : %u\n\n", sizeof(char[7][3]));
  //printf("int[] :      %u\n", sizeof(int[]));  La taille du tableau n'est pas définie
	
	
	
	
	printf("Avec un tableau de caractères : \n\n");
	
	char tab[10];
	
	printf("tab :      %u\n",   sizeof(tab));      // Taille du tableau * taille d'un char >> 10 * 1 = 10
	printf("tab[0] :   %u\n",   sizeof(tab[0]));   // <=> sizeof(char) puisque c'est un élément char (taille = 1) du tableau
	printf("&tab[0] :  %u\n",   sizeof(&tab[0]));  // Adresse - codée sur ce pc sur 4 octets
	printf("*&tab :    %u\n",   sizeof(*&tab));    // * et & sont des opérateurs complémentaires s'annulant
	printf("*&tab[0] : %u\n\n", sizeof(*&tab[0])); // <=> tab[0]
	
	char (*p)[10] = &tab; // Adresse du tableau de 10 caractères (sans l'étoile : tableau de 10 caractères)
	
	printf("p :        %u\n", sizeof(p));       // Taille de l'adresse du tableau (sur ce pc : codé en 32 bits, donc sur 4 octets)
	printf("*p :       %u\n", sizeof(*p));      // <=> 
	printf("(*p)[2] :  %u\n", sizeof((*p)[2])); // Taille d'un char (1)
	printf("&(*p)[2] : %u\n", sizeof(&(*p)[2])); // Adresse de l'élément ci-dessus donc sur ce pc codée sur 4 octets
	
	
	return(0);	
	
	
	/*
	// QUESTION b) //
	
	int a = 32;
	int b = 9;
	permute(&a, &b);
	printf("a = %d et b = %d\n",a,b);
	
	return(0);
	 */
	
	
	// QUESTION c) //
	/*
	int a = 1;
	int* p = &a;
	
	printf("Adresse de a : %p\n", p);	
	reinitPointeur(&p); // On passe l'adresse du pointeur p
	printf("Adresse de a après réinitialisation : %p\n", p);
	*/
	return(0);
	
}

void permute(int *x, int *y)
{
	int z;
		
	z = *x;
	*x = *y;
	*y = z;
}


void reinitPointeur(int** p) // Adresse d'un pointeur sur un entier
{
	*p = NULL;
}


