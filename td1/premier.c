#include <stdio.h>

int main()
{
	int n,i;
	
	printf("Entrez un nombre entier n : ");
	scanf("%d",&n);
	i = 1;
	
	do{ i++; }
	while( ((i*i)<n)  &&  (!(n%i == 0)) );
	
	if ( (i*i) >n ) printf("%d est premier\n",n);
	else printf("%d n'est pas premier\n",n);
		
	return(0);
}
