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
Liste concatene     (Liste l1, Liste l2);
Liste renverse      (Liste l);
Liste entrelace     (Liste l1, Liste l2);

////////////////



int main(int argc, char **argv)
{
	srand(time(NULL));
	
	// OPERATIONS DE BASES 
/*	Liste l = creerListe();		
	l = aleaListe(10);
	l = ajoutDebut(l,666);
	l = ajoutDebut(l,42); 
	l = ajoutDebut(l,999);
	afficheListe(l);
	printf("Nombre d'élément(s) : %d\n", nombreElement(l));
	printf("Recherche de %d : %d (1 = Dans la liste - 0 = Pas dans la liste)\n", 999, recherche(l,999));	
	
		
	// SUPPRIME
	printf("Suppression de %d.\n", 666);
	l  = supprime(l,666);
	afficheListe(l);
	
	
	// CONCATENE
	Liste l1 = aleaListe(10); afficheListe(l1);
	Liste l2 = aleaListe(10); afficheListe(l2);
	       concatene(l1,l2); afficheListe(l1); 
	        
	        
	// RENVERSE
	Liste l = aleaListe(10);
	afficheListe(l);
	l = renverse(l);
	afficheListe(l); */
	
	
	// ENTRELACE
	Liste l1 = creerListe();
	l1 = ajoutDebut(l1,7);
	l1 = ajoutDebut(l1,8);
	l1 = ajoutDebut(l1,10);
	l1 = renverse(l1);
	
	Liste l2 = creerListe();
	l2 = ajoutDebut(l2,3);
	l2 = ajoutDebut(l2,9);
	l2 = ajoutDebut(l2,11);
	l2 = renverse(l2);
	
	afficheListe(l1); afficheListe(l2);
	
	Liste l = entrelace(l1,l2);
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

// Correction pour l'aleaListe

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
	else return(recherche(l->suiv, e));		
}

/*
Liste supprime(Liste l, int e)
{
	// Supprime toute la liste
	* 
	if(estVide(l)) return l;
	if((l->val) == e) return NULL;
	else return supprime(l->suiv, recherche(l->suiv, e));	
	
	// Supprime qu'un seul élément
	* 
	* 
	if(estVide(l)) return l;
	
	Liste p = malloc(sizeof(int));
	p = l;
	
	if(recherche(p,e))
	{
		if(p->val == e)  // Si au début
		{
			return (p->suiv);
		}		 
		
		if( (p->suiv->val) == e) // Si ni début ni fin
		{
			p->suiv = p->suiv->suiv;
		}
		
		// Ne fonctionne pas pour la fin
		if( ((p->suiv->val) == e)  &&  ((p->suiv->suiv) == NULL) )  //Si élément à la fin
		{
			p->suiv = NULL;
		}
	}
	
	return p;	
}*/
	
// Correction pour la suppression

Liste supprime(Liste l, int e)
{
	if(estVide(l)) return l;
	
	Liste temp = l;
	
	if( (l->val) == e)  // 1er élément à supprimer
	{
		temp = l->suiv;
		free(l);
		return temp;		
	}
	
	while( (temp->suiv->val != e)  && (temp->suiv != NULL) )
	{
		temp = temp->suiv;
		if(temp->suiv != NULL)
		{
			Liste v = temp->suiv;
			temp->suiv = temp->suiv->suiv;
			free(v);
		}
	}
	return l;	
}
	

Liste concatene(Liste l1, Liste l2)
{
	if (estVide(l1)) return l2;
	else l1->suiv = concatene(l1->suiv, l2);
	return l1;	
}


Liste renverse(Liste l)
{
	if( estVide(l) || estVide(l->suiv) ) return l;
	
	
	Liste  res = creerListe();	
	
	while(!estVide(l))
	{
		res = ajoutDebut(res,l->val);
		l   = l->suiv;
	}	
	return res;
}


Liste entrelace(Liste l1, Liste l2)
{
	if(estVide(l1)) return l2;
	if(estVide(l2)) return l1;
	
	Liste l = creerListe();
	
	if( verifTrie(l1) && verifTrie(l2) ) // on vérifie si les 2 listes sont triées
	{
		while( (!estVide(l1)) && (!estVide(l2)) ) // tant que les deux listes ne sont pas vides
		{
			if( (l1->val) > (l2->val) )
			{
				l  = ajoutDebut(l, l2->val);
				l1 = l1->suiv;
			}
			else
			{
				l  = ajoutDebut(l, l1->val);
				l2 = l2->suiv;
			}			
		}						
	}
	
	l = renverse(l); // On renverse la liste puisqu'on a ajouté au début
}


/* CORRECTION DU PROF
Liste fusion(Liste l1, Liste l2)
{
	Liste debut, fin;
	
	if(estVide(l1)) return l2;
	if(estVide(l2)) return l1;
	
	if( (l1->val) < (l2->val) )
	{
		debut = l1;
		fin = l1;
		l1 = l1->suiv;
	}
	
	else
	{
		debut = l2;
		fin = l2;
		l2 = l2->suiv;
	}
	
	while( (!estVide(l1)) && (!estVide(l2)) )
	{
		if( (l1->val) < (l2->val) )
		{
			fin->suiv = l1;
			l1 = l1->suiv;
			fin = fin->suiv;
		}
		
		else
		{
			fin->suiv = l2;
			l2 = l2->suiv;
			fin = fin->suiv;
		}		
	}
	
	if(l1==NULL)
	{
		fin->suiv = l2;
	}
	else
	{
	fin->suiv = l1;	
	}
	
	return debut;	
}
*/




