//declaration des fonction appelé par les commandes utilisé pour la communication serveur/client

#ifndef COMMANDE_SERV_H
#define COMMANDE_SERV_H

void sortir(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void halt(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void  testarg(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void creer(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void etat(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void etat_faim(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void etat_humeur(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);
void manger(char arguments[MAX][12], int nb_arguments, void * retour, liste * liste_arg);


#endif
