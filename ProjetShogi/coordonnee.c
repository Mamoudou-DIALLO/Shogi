#include "coordonnee.h"
#include <stdlib.h>
#include <stdio.h>
#include <math.h>
/*definition des fonction utilisateurs*/

/*fonction de creation*/
coordonnee_t creer_coordonnee(int x,int y)
{
  coordonnee_t c;
  c.x=x;
  c.y=y;
  return c;
}

/*fonction d'affichage*/
void afficher_coordonnee(coordonnee_t c)
{
printf("x=%d,y=%d\n",c.x,c.y );
}
/*fonction de comparaison*/
