#include <stdio.h>


int main()
{
	int i,j;
	int a=0;
	
	for(i=10; i>0; i--)
	{
		for(j=a; j<10; j++)
		{
			printf(" ");	
		}
		printf("*\n");
		a = a+1;	
	}
		
	return(0);
}


