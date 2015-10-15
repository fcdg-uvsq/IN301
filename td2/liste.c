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
int   testListeTrie (Liste l);
int   alea          (int n);
Liste aleaListe     ();

////////////////

int main(int argc, char **argv)
{
	srand(time(NULL));
	
	Liste l = creerListe();

	/*
	l = ajoutDebut(l,4);
	l = ajoutDebut(l,7);
	l = ajoutFin(l,9);
	
	afficheListe(l);
	printf("Retour de la fonction testListeTrie = %d\n",testListeTrie(l));
	
	//l = ajoutTrie(l,6);
	//afficheListe(l);
	*/
	
	l = aleaListe();
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
	if (!estVide(l))
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
	
	if(estVide(l)) return ajoutDebut(l,e);
	l->suiv = ajoutFin(l->suiv,e);
	
	return(l);
}



int testListeTrie(Liste l)
{
	while(!estVide(l))
	{
		if(l->suiv != NULL)
		{
			if( (l->val) > ((l->suiv)->val) ) // Si la valeur courant est <= valeur suivante
			{
				printf("La liste n'est pas triée.\n");
				return(0);
			}		
		}
		l = l->suiv;
	}
		
	printf("La liste est triée.\n");
	return(1);
}


/*
Liste ajoutTrie(Liste l, int e)
{
	Liste l1 = malloc(sizeof(l1));
	l1->val = e;
	l1->suiv = NULL;
	
	if(estVide(l)) return ajoutDebut(l,e);
	
	if(l->val > e)  l = ajoutDebut(l,e); // Si toutes les valeurs de la liste sont >e on ajout e au tout début
	
	else l->suiv = ajoutTrie(l->suiv,e);
	
	return(l);	
}
*/


int alea(int n)
{
	return rand() % n;
}

Liste aleaListe()
{
	Liste l = creerListe();
	
	while(!estVide(l))
	{
		l->val = alea(20);
	}
	return l;
	
}



