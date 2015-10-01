#include <stdio.h>

int main()
{
	int x;
	printf("Entrez un nombre entier: \n");
	scanf("%d",&x);
	
	if((x % x == 1) && (x % 1 == 1)){
		if(x<10) printf("Le chiffre est premier.\n");
		else printf("Le nombre est premier.\n");
	}
	else{
		if(x<10) printf("Le chiffre n'est pas premier.\n");
		else printf("Le nombre n'est pas premier.\n");
	}
	
	return(0);	
}

