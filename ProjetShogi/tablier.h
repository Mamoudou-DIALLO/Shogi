#ifndef TABLIER_H
#define TABLIER_H
/*INCLUSION   PIECE*/
#include "piece.h"
#include "coordonnee.h"


/*structure tablier*/
struct tablier_s{
  char plateau[11][11];
};
typedef struct tablier_s tablier_t;
/*fonctions*/
tablier_t * initialiser_tablier();
int case_vide(tablier_t t, coordonnee_t c);
void affichier_plateau(tablier_t t);
void initialiser_tablier_debut_partie(tablier_t * p);
void modifier_contenu_tablier_pos(tablier_t t,char car,int x,int y);
char recuperer_caracterer_contenu_tablier_pos(tablier_t t,int x,int y);
#endif
