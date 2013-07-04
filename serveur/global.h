#ifndef GLOBAL_H
#define GLOBAL_H

#define MAX 512
#define MAX_GOUT 10
#define MIN_GOUT -10

#define POID_DEPART 5
#define CAPACITE_ESTOMAC 20
#define CYCLE 3 //duré d'un cycle de mise à jour en seconde
#define DURE_JOUR 24 //nombre de cycle en une journé
#define DURE_PRODUCTION (DURE_JOUR / 4) //duré d'un cycle de production en cycle (ingurgistation, digestion , evacuation)
#define DURE_DIGESTION (DURE_PRODUCTION /3)//nombre de cycle avant le déclanchement de la digestion
#define DURE_EVACUATION (DURE_PRODUCTION - DURE_DIGESTION)//nombre de cycle avant le déclanchement de la digestion
#define DURE_HUMEUR (DURE_JOUR / 6) //nombre de cycle avant la mise a jour d'humeur
#define DURE_POID  DURE_JOUR// nombre de cycle avant la mise a jour de poid

#include <pthread.h>
#include <time.h>
#include "../classe/variable_etat.h"
#include "../classe/liste.h"

int poid, poid_dejection, verrou_ingurgitation, verrou_digestion;
extern variable_etat* niv_faim, *humeur, *nourriture_ingurgite ;




extern pthread_mutex_t mutex_etat;

int eteindre, alive;



#endif
