#include <stdio.h>
#include <stdlib.h>
#include "coordonnee.h"
#include "liste_double.h"

/*declaration des constantes*/
#define promu 1
#define non_promu 0
#define capturer 1
#define non_cap 0


/*definition des fonction*/

coup_t  *creer_coup(coordonnee_t d, coordonnee_t a,int pro,int cap)
{
  coup_t *coup=malloc(sizeof(coup_t));
  coup->cord_dep=d;
  coup->cord_arriv=a;
  coup->promotion=pro;
  coup->capture=cap;
  coup->suivant=NULL;
  coup->precedent=NULL;
  return coup;
}

liste_t *initialiser_liste()
{
  liste_t *liste=malloc(sizeof(liste_t));
  liste->premier=NULL;
  liste->dernier=NULL;
  liste->taille=0;
  return liste;
}

int liste_vide(liste_t *l)
{
  if(l->taille==0)
  {
    return 1;
  }
  return 0;
}

void ajout_debut_liste(liste_t *l,coup_t *coup)
{
  if(liste_vide(l)==1)
    {
      coup->suivant=NULL;
      coup->precedent=NULL;
    }
    else
    {
      coup->suivant=l->premier;
      l->premier->precedent=coup;
      coup=l->premier;
    }
    l->taille++;
}

void ajout_fin_liste(liste_t *l ,coup_t * coup)
{
  if(liste_vide(l)==1)
  {
    coup->suivant=NULL;
    coup->precedent=NULL;
  }
  else
  {
    l->dernier->suivant=coup;
    coup->precedent=l->dernier;
    l->dernier=coup;
  }
  l->taille++;
}

coup_t * extraire_coup_debut(liste_t * l)
{
  if(liste_vide(l)==1)
  {
    return NULL;
  }
  else
  {
    coup_t *debut=l->premier;
    l->premier=debut->suivant;
    debut->suivant=NULL;
    l->premier->precedent=NULL;
    l->taille--;
    return debut;
  }
}

coup_t * extraire_coup_fin(liste_t * l)
{
  if(liste_vide(l)==1)
  {
    return NULL;
  }
  else
  {
    coup_t *fin=l->dernier;
    l->dernier=fin->precedent;
    l->dernier->suivant=NULL;
    fin->precedent=NULL;
    l->taille--;
    return fin;
  }
}
