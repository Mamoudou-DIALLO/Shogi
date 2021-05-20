#ifndef PARTIE_H
#define PARTIE_H

/*inclusion des autres fichiers*/
#include "tablier.h"
#include "liste_double.h"

/*structure partie*/
struct partie_s{
  tablier_t * tablier;
  liste_t * liste;
  int  joueur;
};
typedef struct partie_s partie_t;

/*declaration des fonctions*/
void modifier_case(partie_t *p, piece_t piece, int x, int y);
void changer_joueur(partie_t * p);
void debut_partie(tablier_t * p);
coordonnee_t saisie_case();
partie_t *partie_creer();
void partie_detruire(partie_t * p);
void partie_jouer(partie_t * p);
void deplacement(partie_t *p, coordonnee_t dep, coordonnee_t arriv);

/*definitions des fonctions de placements*/
int deplacement_valide_pion(coordonnee_t dep, coordonnee_t arriv,partie_t p);
int deplacement_valide_tour(coordonnee_t dep, coordonnee_t arriv,partie_t p);
int deplacement_valide_fou(coordonnee_t dep, coordonnee_t arriv,partie_t p);
int deplacement_valide_lance(coordonnee_t dep, coordonnee_t arriv,partie_t p);
int deplacement_valide_cavalier(coordonnee_t dep, coordonnee_t arriv,partie_t p);
int deplacement_valide_G_Argent(coordonnee_t dep, coordonnee_t arriv,partie_t p);
int deplacement_valide_G_Or(coordonnee_t dep, coordonnee_t arriv,partie_t p);
int deplacement_valide_G_Roi(coordonnee_t dep, coordonnee_t arriv,partie_t p);
int deplacement_valide(coordonnee_t dep , coordonnee_t ariv,partie_t *p);
#endif
