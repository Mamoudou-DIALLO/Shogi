#ifndef DEPLACEMENT_H
#define DEPLACEMENT_H
#include "partie.h"
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
