#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


int estFlottant(char *argument)
{
	int i = 0;
	
	while((argument[i]) != '\0') // Tant que la chaîne de caractère n'est pas vide
	{
		if( (isdigit(argument[i])) || ((argument[i]) == '-') || ((argument[i]) == '.') ) // Si l'argument est un chiffre OU négatif OU un flottant
		{
			i++; // On avance dans le mot
		}
		else
		{
			printf("Votre argument %s n'est pas un flottant !\n", argument); // %s affiche une chaîne de caractères
			return 0;	
		}	
	}
	return 1;
}



int main(int argc, char **argv)  // argv : tableau de chaîne de caractère && argc : taille du tableau
{
	/// QUESTION a) ///
	/*
	int i;
	for(i=0; i<argc; i++)
	{
		printf("%s\n", argv[i]);
	}
	return 0;
	
	/!\ dans le passage des arguments, " :! " ne sera pas reconnu
	On les appelle dans le terminal de cette façon : ./executable <argument_1> <argument_2> ...
	*char <=> mot  et **char <=> tableau de mots
	*/
	
	
	/// QUESTION c) ///
	/*
	int i;
	double somme;	
	for(i=1; i<argc; i++) // On comment i à 1 pour éviter d'avoir l'exucutable qui arrive en premier argument
	{
		somme = somme + atof(argv[i]);  // atof convertit une chaîne de char en un double, ici somme les arguments
	}	
	printf("%.1f", somme);  // Affiche le double avec une précision de une décimale après la virgule	
	return 0;
	*/
	
	/// QUESTION d)
	int i;
	double somme;	
	for(i=1; i<argc; i++)
	{
		if(estFlottant(argv[i]))
		{
			somme = somme + atof(argv[i]);  
		}
		
	}	
	printf("Somme = %.1f\n", somme); 	
	return 0;	
}
