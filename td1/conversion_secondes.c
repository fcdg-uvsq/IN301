#include <stdio.h>

int main()
{
	int temps, heure, minute, seconde;
	
	
	printf("Entrez votre temps en secondes : ");
	scanf("%d", &temps);
	
	
	heure = temps/3600;
	temps = temps%3600; // Le reste en minutes des heures
	minute = temps/60; 
	temps = temps%60;	// Le reste en secondes des minutes
	seconde = temps; 	
	
	printf("Vous avez entré %d heure(s) %d minute(s) et %d seconde(s) !\n", heure, minute, seconde); 
							
	return(0);	
}

