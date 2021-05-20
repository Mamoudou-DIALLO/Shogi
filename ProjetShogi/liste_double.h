#ifndef COUP_H
#define COUP_H
#include "coordonnee.h"
/*struct coup */
struct coup_s{
  coordonnee_t cord_dep;
  coordonnee_t cord_arriv;
  int promotion;
  int  capture;
  struct coup_s * suivant;
  struct coup_s * precedent;

};
typedef struct coup_s coup_t;
/*structure liste doublement chainees qui est une suite de liste de coup*/
struct liste_s{
  struct coup_s *premier;
  struct coup_s *dernier;
  int taille;

};
typedef struct liste_s liste_t;
/*fonction pour la liste*/
coup_t  *creer_coup(coordonnee_t d, coordonnee_t a,int pro,int cap);
liste_t * initialiser_liste();
int liste_vide(liste_t *l);
void ajout_debut_liste(liste_t *l,coup_t *coup);
void ajout_fin_liste(liste_t *l ,coup_t * coup);
coup_t * extraire_coup_debut(liste_t * l);
coup_t * extraire_coup_fin(liste_t * l);

#endif
