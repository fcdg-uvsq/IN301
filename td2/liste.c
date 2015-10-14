#include <stdio.h>
#include <stdlib.h>


struct element{
	int val;
	struct element *suiv;
};

typedef struct element *Liste;


// PROTOTYPES //

Liste creerListe    ();
int   estVide       (Liste l);
void  afficheListe  (Liste l);
void  libereMemoire (Liste l);
Liste ajoutDebut    (Liste l, int e);
Liste ajoutFin      (Liste l, int e);
Liste ajoutTrie     (Liste l, int e);

////////////////

int main(int argc, char **argv)
{
	Liste l = creerListe();

	l = ajoutDebut(l,4);
	l = ajoutDebut(l,7);
	l = ajoutFin(l,9);
	l = ajoutTrie(l,6);
	afficheListe(l);
	
	return 0;
}


///////////////
// FONCTIONS //
///////////////


Liste creerListe()
{
	return (NULL);	
}


int estVide(Liste l)
{
	return (l == NULL) ? 1 : 0;
}


void afficheListe(Liste l)
{
	if(estVide(l))
	{
		printf("La liste est vide.\n");
	}
		
	else
	{
		while(l != NULL)
		{
			printf("%d\t", l->val);
			l = l->suiv;
		}	
	}
	putchar('\n');
}


void libereMemoire(Liste l)
{	
	if (l != NULL)
	{
		libereMemoire(l->suiv); // On se rappelle récursivement sur la Liste
		free(l);
	}
}


Liste ajoutDebut(Liste l, int e)
{
	Liste l1;
	l1 = malloc(sizeof(l1));
	
	l1->val = e;
	l1->suiv = l;
	
	return(l1);	
}


Liste ajoutFin(Liste l, int e)
{	
	Liste l1 = malloc(sizeof(l1));
	l1->val = e;
	l1->suiv = NULL;
	
	if(l == NULL) return ajoutDebut(l,e);
	l->suiv = ajoutFin(l->suiv,e);
	
	return(l);
}


Liste ajoutTrie(Liste l, int e)
{
	Liste l1 = malloc(sizeof(l1));
	l1->val = e;
	l1->suiv = NULL;
	
	if(l == NULL) return ajoutDebut(l,e);
	
	if(l->val > l1->val) ajoutDebut(l,e); // Si toutes les valeurs de la liste sont >e on ajout e au tout début
	else ajoutTrie(l->suiv,e);
	
	return(l);	
}



