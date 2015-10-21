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
Liste aleaListe     (int n);
int   nombreElement (Liste l);
int   recherche     (Liste l, int e);
Liste supprime      (Liste l, int e);


////////////////



int main(int argc, char **argv)
{
	srand(time(NULL));
	
	Liste l = creerListe();

		
	//l = aleaListe(100);
	l = ajoutDebut(l,666);
	l = ajoutDebut(l,42);
	l = ajoutFin(l,999);
	afficheListe(l);
	
	printf("Nombre d'élément(s) : %d\n", nombreElement(l));
	
	// RECHERCHE
	int chercheNbr = 999; // Valeur que l'on recherche
	if(recherche(l,chercheNbr) == 1) printf("%d présent dans la liste !\n",chercheNbr);
	else printf("%d non présent dans la liste !\n",chercheNbr);
	printf("Valeur de renvoie de la recherche : %d.\n", recherche(l,chercheNbr));
	
	// SUPPRIME
	int supprimeNbr = 666; // Valeur que l'on supprime
	printf("Suppression de %d.\n", supprimeNbr);
	l  = supprime(l,supprimeNbr);
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
			printf("%d ", l->val);
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

/*
Liste aleaListe()
{	
	Liste l = NULL;
	
	do{
		l = ajoutDebut(l, alea(100));
	}while( (l->val) != 0 );

	return l;
}
* */

// Correction du prof

Liste aleaListe(int n)
{
	int x;
	Liste l = creerListe();
		
	while(1)
	{
		x = rand()%n;
		
		if(x == 0) return l;
		
		else l = ajoutDebut(l,x);		
	}
	return l;
}
			

int nombreElement(Liste l)
{
	// EN RECURSIF
	
	if(estVide(l)) return 0;
	return 1 + nombreElement(l->suiv);
	
	
	// EN ITERATIF	
	/*
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
	return(compteur); */
}


int recherche(Liste l, int e)
{
	if(estVide(l)) return 0;
	
	if((l->val) == e) return 1;
	else return(e = recherche(l->suiv, e));		
}


Liste supprime(Liste l, int e)
{
	
	// Si triée
		// au début 
		/*
		Liste p = l->suiv;
		return (p);
		*/
		
		// milieu
		Liste p = l;
		while(!estVide(p))
		{
			if( (p->suiv->val) != e)
				{
					p->suiv = p->suiv->suiv;
				}
			p = p->suiv;
		}
		
		
		
		//fin
	
	
	// Si non triée
		// au début
		
		// milieu
		
		//fin
}


