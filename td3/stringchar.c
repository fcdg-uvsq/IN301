#include <stdio.h>
#include <string.h>
#include <stdlib.h>

struct Element
{
	char val;
	struct Element *suiv;
};

typedef struct Element *ListeC;


// PROTOTYPES //

void   afficheChaine(ListeC l);
ListeC ajoutFin(char c, ListeC l);
ListeC ajoutChaine(char* t, ListeC l);



int main(int argc, char **argv)
{
	ListeC chaine1 = malloc(sizeof(struct Element));
	//char   chaine2[200];
	
	int i;
	
	for(i=1; i<argc; i++)
	{
		chaine1 = ajoutChaine(argv[i], chaine1);
	}
	
	afficheChaine(chaine1);

	return 0;
}


// FONCTIONS //

void afficheChaine(ListeC l)
{
	if(l == '\0')
	{
		printf("La chaîne de caractère est vide");
	}
	
	else printf("%c", l->val);
	afficheChaine(l->suiv);
}

ListeC ajoutFin(char c, ListeC l)
{
	ListeC tmp = malloc(sizeof(struct Element));
	tmp->val = c;
	
	if(l == NULL)
		return tmp;
	
	else
	{
		while(tmp->suiv != NULL)
		{
			tmp = tmp->suiv;
		}
		l->suiv = tmp;
		
	}
	return(tmp);
}


ListeC ajoutChaine(char* t, ListeC l)
{
	if(t[0] == '\0')
	{
		return l;
	}
	
	l = ajoutFin(t[0], l);
	l->suiv = ajoutChaine(t+1, l);
	
	return(l);
}
