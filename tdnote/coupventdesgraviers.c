#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/*************  Constantes   *****************************/
#define NbPriorite 10    //nombre total de priorités
#define Nmax       8    //nombre de requêtes générées


/**************  Définition des structures ***************/

struct requete{
  int numero;    // numéro de la requête
  int priorite;  // priorité de la requête
};
typedef struct requete Requete;



/* Définir ici la structure Fap1 et Fap2 */

struct element{
	Requete val;
	struct element *suiv;	
};
typedef struct element *Fap1;



/**************  Fonctions de manipulation des structures *******/

// file initialisée vide
Fap1 initialiseFile1(){
	return NULL;
}

/*
// file initialisée vide
Fap2 initialiseFile2(){
	
}
*/


void afficheFile1(Fap1 f)
{
	if(f == NULL)
	{
		printf("La file est vide !");
	}
	
	else
	{
		while(f != NULL)
		{
			printf("Requête : Numéro = %d\tPriorité = %d.\n", f->val.numero, f->val.priorite);
			f = f->suiv;
		}
	}
	putchar('\n');
}


/*
void afficheFile2(Fap2 f){
  
}
*/

Fap1 ajoutFile1(Fap1 f, Requete r)
{
// Si la file est vide on l'ajoute à la fin	
    if (f == NULL)
    {
		Fap1 file = malloc(sizeof(struct element));
		file->val.numero   = r.numero;
		file->val.priorite = r.priorite;
		file->suiv = NULL;
		return(file);
	}
	
// Sinon on crée un nouvel élément en lui allouant de la mémoire et on l'ajoute à la fin	
	else
	{		
		Fap1 f1 = malloc(sizeof(struct element));
		f1->val.numero   = r.numero;
		f1->val.priorite = r.priorite;
		f1->suiv = NULL;
		f1->suiv = ajoutFile1(f1->suiv,r);	
		return(f);
	}		
}


/*
Fap2 ajoutFile2(Fap2 f, Requete r){
  
}
*/

// La fonction suivante crée un Segmentation Fault, l'idée me semble bonne mais 
// l'erreur doit être due à la ligne "Fap1 p = f->suiv;" que je n'arrive pas à corriger

Fap1 traiteRequete1(Fap1 f)
{
	if(f == NULL) return NULL;		
	
	else
	{
		Fap1 p = f->suiv;
		
		while(f != NULL)
		{
			// Si la priorité de f est strictement supérieur à p (pointeur qui pointe sur l'élément suivant de la file), on l'extrait
			if( (f->val.priorite) > (p->val.priorite) )
			{
				printf("Extraction de l'élément prioritaire : %d\n", f->val.numero);
			}
			p = p->suiv; // On avance dans la file
		}
		
	}
	return(f); 
}


/*
Fap2 traiteRequete2(Fap2 f){
   
}
*/


void libereMemoire1(Fap1 f)
{
	if (f != NULL)
	{
		libereMemoire1(f->suiv);
		free(f);
	}
}
 


/*
void libereMemoire2(Fap2 f){
  
}
*/




/************** Génération des requêtes pour simulation *****************/

//retourne un entier aléatoire entre 0 et n-1
int alea(int n){
  return rand()%n;
}

Requete generationRequete(){
  static int numero = 0;
  Requete r;
  numero++;
  r.numero = numero;
  r.priorite = alea(NbPriorite);
  return r;
}



/************ Simulation file *****************************/

/*
//structure 1
void simulationFile1(){
  Fap1 f1 = initialiseFile1();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f1 = traiteRequete1(f1);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f1 = ajoutFile1(f1, r);
    }
    afficheFile1(f1);
  }
  libereMemoire1(f1);
  printf("#######################################\n");
}

/*
//structure 2
void simulationFile2(){
  Fap2 f2 = initialiseFile2();
  int compteur = 0;
  Requete r;
  while(compteur < Nmax){
    if(alea(2) == 0){ //traitement requête avec proba 0.5
      f2 = traiteRequete2(f2);
    }
    else{ //génération d'une nouvelle requête avec proba 0.5
      compteur++;
      r = generationRequete();
      f2 = ajoutFile2(f2, r);
    }
    afficheFile2(f2);
  }
  libereMemoire2(f2);
  printf("########################################\n");
}
*/

/*************  Fonction main *******************************/

int main()
{	
	srand(time(NULL));

	/********  à décommenter pour lancer une simulation *********/
	  
	//simulationFile1();
	  
	 
	Fap1 f = initialiseFile1();
	Requete r = generationRequete();
	f = ajoutFile1(f,r);
	afficheFile1(f);
	f = traiteRequete1(f);
	
	  
		
	//simulationFile2();
		  
	return 0;
}






