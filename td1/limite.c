#include <stdio.h>

int main()
{
	float i;
	float somme = 0;
	
	for(i=1; i<30000; i++){
		somme += (1/(i*i));
	}
	printf("Limite = %.15f\n",somme);
	
	return 0;
}

