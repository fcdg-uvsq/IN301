#include <stdio.h>

int main()
{
	int x,y;
	int r = 0;
	
	printf("(Rappel : x>0) x = "); scanf("%d",&x);
	printf("(Rappel : y>0) y = "); scanf("%d",&y);
	printf("\n");
	
	if (x>0 && y>0) 
	{
		printf("%d * %d\n\n",x,y);
		
		while(x!=1)
		{
			if(x % 2 == 0)
			{
				x = (x/2);
				y = (2*y);
				printf("= %d * %d + %d\n",x,y,r);
				
			}			
			else
			{
				x = x-1;
				r = r + y;
				printf("= %d * %d + %d\n",x,y,r);				
			}			
		}
		printf("= %d\n",y+r);
	}
	else printf("Avez-vous lu le rappel ?\n");
	
	
	return 0;
}

/*
 * Correction en récursif
 * 
 * mult_egyp(int x, int y, int reste)
 * {
 * 		if(x == 0) Renvoyer (reste) // et affichage avec printf
 * 		if(x % 2) Renvoyer mult_egyp(x-1,y,reste+y)
 * 		else Renvoyer mult_egyp(x\2,y*2,reste)
 * 
 * }

