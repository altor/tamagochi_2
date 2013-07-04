#include <time.h>
#include <stdio.h>

#include "global.h"


void compteur_cycle(void)
{
  static int cycle = 0;
  cycle++;
  printf("%d\n",cycle);
}

void gestion_prod(void)
{
  static int cycle = 0,ancien = 0;
  static time_t t1, t2;
int coulis;
  

  //si ingurgitation a commencé on commence a compter un nombre de cycle
  if(!ancien && verrou_ingurgitation){
    ancien = 1;
    t1 = variable_etat_obtenir_temps(nourriture_ingurgite);
  }

  //on continue tant que l'ingurgitation n'est pas terminé
  if(verrou_ingurgitation){
    t2 = variable_etat_obtenir_temps(nourriture_ingurgite);
    //si une nouvelle ingurgitation a été lancé on réinitialise le nombre de cycle
    if(difftime(t1, t2) != 0){
	cycle = 1;
	t1 = t2;
      }
    else
      cycle ++;
  }
  //si une phase d'ingurgitation a été intéromput on remet le compteur de cycle à zéro
  else if(cycle > 0)
    cycle = 0;
  //dés qu'un nombre de cycle sufisant est passé on lance la digestion
  if(cycle >= (DURE_DIGESTION) )
      {
	coulis = variable_etat_obtenir_valeur(nourriture_ingurgite);
	//phase normal : on termine la phase d'ingurgitation, le poid et le poid des dejection augmente en fonction de la nourriture ingurgité, l'estomac est vidé et on prévient que la phase de digestion est en cours.
	verrou_ingurgitation = 0;
	ancien = 0;
	poid += (coulis / 2);
	poid_dejection += (coulis / 4);
	variable_etat_initialiser(nourriture_ingurgite, 0);
	verrou_digestion = 1;
      }
}
