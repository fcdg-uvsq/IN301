#include <stdio.h>
#include <stdlib.h>
#include <time.h>


struct element{
	int val;
	struct element *suiv;
};
typedef struct element *Liste;

/* On peut définir la liste soit en 2 typedefs soit en 1 seul
typedef struct element Element
typedef struct Element *Liste */



// PROTOTYPES //

Liste creerListe    ();
int   estVide       (Liste l);
void  afficheListe  (Liste l);
void  libereMemoire (Liste l);
Liste ajoutDebut    (Liste l, int e);
Liste ajoutFin      (Liste l, int e);
Liste ajoutTrie     (Liste l, int e);
int   verifTrie     (Liste l);
int   alea          (int n);
Liste aleaListe     ();
int   nombreElement (Liste l);
int   recherche     (Liste l, int e);


////////////////



int main(int argc, char **argv)
{
	srand(time(NULL));
	
	Liste l = creerListe();

	/*
	l = ajoutDebut(l,4);
	l = ajoutDebut(l,7);
	l = ajoutFin(l,9);
	* */
	//afficheListe(l);
		
	//l = ajoutTrie(l,6);
	//afficheListe(l);
	
	
	l = aleaListe(l);
	afficheListe(l);
	
	printf("Nombre d'élément(s) : %d\n", nombreElement(l));
	
	int e = 4; // Valeur que l'on recherche
	//printf("Valeur de renvoie de la recherche : %d.\n", recherche(l,e));
	
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
	return (l == NULL); // Renvoie directement la valeur du test
}


void afficheListe(Liste l)
{
	if(estVide(l))
	{
		printf("La liste est vide.\n");
	}
		
	else
	{
		while(!estVide(l))
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
	l1 = malloc(sizeof(struct element));
	
	l1->val = e;
	l1->suiv = l;
	
	return(l1);	
}


Liste ajoutFin(Liste l, int e)
{	
	Liste l1 = malloc(sizeof(struct element));
	l1->val = e;
	l1->suiv = NULL;
	
	if(estVide(l)) return ajoutDebut(l,e);
	l->suiv = ajoutFin(l->suiv,e);
	
	return(l);
}


int verifTrie(Liste l)
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


Liste ajoutTrie(Liste l, int e)
{
	if(verifTrie(l) == 1)
	{
		Liste l1 = malloc(sizeof(struct element));
		l1->val = e;
		l1->suiv = NULL;
		
		if(estVide(l)) return ajoutDebut(l,e);
		if(l->val > e)    l = ajoutDebut(l,e); // Si toutes les valeurs de la liste sont >e on ajout e au tout début
		else l->suiv = ajoutTrie(l->suiv,e);
		
		return(l);	
    }
    
    else return(l);
}


int alea(int n)
{
	return rand() % n;
}


Liste aleaListe()
{	
	Liste l = NULL;
	
	do{
		l = ajoutDebut(l, alea(100));
	}while( (l->val) != 0 );

	return l;		
}


int nombreElement(Liste l)
{
	/*
	if(estVide(l)) return 0;
	return nombreElement(l->suiv) + 1;
	*/
	// EN ITERATIF	
	
	int compteur = 0;
	
	if(estVide(l)) return(compteur);
	
	else
	{
		while(!estVide(l))
		{
			compteur++;
			l = l->suiv;
		}
	}
	return(compteur);
}


int recherche(Liste l, int e)
{
	if((l->val) == e) return 1;
	e = recherche(l->suiv, e);
	//return 0;		
}




