#include <stdio.h>
#define N 100


void init_tab(int tablo[N])
{
	int i;
	for(i=0; i<N; i++)
	{
		tablo[i]=1;
		printf("%d",tablo[i]);
	}	
}

int main()
{
	int T[N];
	
	init_tab(T[N]);
	
	
	return 0;
}

