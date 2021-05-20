#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "deplacement.h"
/*deplacement pion*/

int deplacement_valide_pion(coordonnee_t dep, coordonnee_t arriv,partie_t p)
{
  if(piece_identifier(recuperer_caracterer_contenu_tablier_pos(*(p.tablier),dep.x,dep.y)).statut==0 )
  {
  /*teste si le caractere de la piece est P et joueur 0*/
    if(p.joueur==0)
    {
      if((dep.x==arriv.x+1)&&(dep.y==dep.y))
      {
        return 1;
      }

    }
    else
    {
      if((dep.x==arriv.x-1)&&(dep.y==dep.y))
      {
        return 1;
      }
    }
  }
/*si il ya une promotion, le pion prend les caracteristique du general_or*/
else
{
  if(p.joueur==0)
    {
      if((arriv.x==dep.x && arriv.y==dep.y-1)|| (arriv.x==dep.x && arriv.y==dep.y+1)
      || (arriv.x==dep.x+1 && arriv.y==dep.y)|| (arriv.x==dep.x-1 && arriv.y==dep.y)
      ||(arriv.x==dep.x+1 && arriv.y==dep.y-1)||(arriv.x==dep.x+1 && arriv.y==dep.y+1))
      {
        return 1;
      }
    }
    else
    {
      if((arriv.x==dep.x && arriv.y==dep.y-1)|| (arriv.x==dep.x && arriv.y==dep.y+1)
      || (arriv.x==dep.x-1 && arriv.y==dep.y)|| (arriv.x==dep.x-1 && arriv.y==dep.y-1)
      ||(arriv.x==dep.x-1 && arriv.y==dep.y+1)||(arriv.x==dep.x+1 && arriv.y==dep.y))
      {
        return 1;
      }
    }

}
  return 0;
}

/*deplacement valide tour*/
int deplacement_valide_tour(coordonnee_t dep, coordonnee_t arriv,partie_t p)
{
  /*dep.y!=ariv.y c'est pour dire que que si on ne deplacement pas le pion ce ce n'est pas pris en compte */
    if((dep.x==arriv.x && (arriv.y>=1 && arriv.y<=9 && dep.y!=arriv.y)) || (dep.y==arriv.y &&(arriv.x>=1 && arriv.x<=9 && dep.x!=arriv.x)))
    {
      return 1;
    }

  return 0;

  }
/*deplacement_valide_fou*/

int deplacement_valide_fou(coordonnee_t dep, coordonnee_t arriv,partie_t p)
{
  /*deplacement sur les deux droites bissectrices si on considere l'origine les cordonnes de notre piece*/
  if(((arriv.y-dep.y)/(arriv.x-dep.x)==1)|| ((arriv.y-dep.y)/(arriv.x==dep.x))==-1)
  {
    return 1;
  }
  return 0;
}

/*fonction pour le deplacement de la lance*/

int deplacement_valide_lance(coordonnee_t dep, coordonnee_t arriv,partie_t p)
{/*les limites de la grille jouanble*/
  if(dep.x<0 || arriv.x<0 || dep.x>10 || arriv.y>10)
  {
    return 0;
  }
  if(p.joueur==0)
  {
    if((arriv.x=dep.x+1) && (arriv.y==dep.y))
    {
      return 1;
    }
  }
  else
  {
    if((arriv.x=dep.x-1) && (arriv.y==dep.y))
    {
      return 1;
    }
  }
  return 0;
}

/*deplacement du cavalier*/

int deplacement_valide_cavalier(coordonnee_t dep, coordonnee_t arriv,partie_t p)
{
  if(((arriv.x=dep.x-1)&&(arriv.y=dep.y+2))||(((arriv.x=dep.x+1)&&(arriv.y=dep.y-2))))
  {
    return 1;
  }

  return 0;
}

/*DEPLACEMENT GENERAL D'ARGENT*/

int deplacement_valide_G_Argent(coordonnee_t dep, coordonnee_t arriv,partie_t p)
{
  if(p.joueur==0)
  {/*ici on teste les 5 cas deplacemnets posibles*/
    if(((arriv.x=dep.x) && (arriv.y=dep.y-1))||((arriv.x=dep.x) && (arriv.y=dep.y+1))||
    ((arriv.x=dep.x+1) && (arriv.y=dep.y))|| ((arriv.x=dep.x+1) &&
     (arriv.y=dep.y-1)) || ((arriv.x=dep.x+1) && (arriv.y=dep.y+1)))
    {
      return 1;
    }
  }
  else
  {
    if(((arriv.x=dep.x) && (arriv.y=dep.y-1))||((arriv.x=dep.x) && (arriv.y=dep.y+1))||
    ((arriv.x=dep.x-1) && (arriv.y=dep.y))|| ((arriv.x=dep.x-1) &&
     (arriv.y=dep.y-1)) || ((arriv.x=dep.x-1) && (arriv.y=dep.y+1)))
    {
      return 1;
    }
  }

  return 0;
}
/*DEPLACEMENT DU GENERAL D'OR */

int deplacement_valide_G_Or(coordonnee_t dep, coordonnee_t arriv,partie_t p)
{
  if(p.joueur==0)
  {
    if((arriv.x==dep.x && arriv.y==dep.y-1)|| (arriv.x==dep.x && arriv.y==dep.y+1)
    || (arriv.x==dep.x+1 && arriv.y==dep.y)|| (arriv.x==dep.x-1 && arriv.y==dep.y)
    ||(arriv.x==dep.x+1 && arriv.y==dep.y-1)||(arriv.x==dep.x+1 && arriv.y==dep.y+1))
    {
      return 1;
    }
  }
  else
  {
    if((arriv.x==dep.x && arriv.y==dep.y-1)|| (arriv.x==dep.x && arriv.y==dep.y+1)
   || (arriv.x==dep.x-1 && arriv.y==dep.y)|| (arriv.x==dep.x-1 && arriv.y==dep.y-1)
   ||(arriv.x==dep.x-1 && arriv.y==dep.y+1)||(arriv.x==dep.x+1 && arriv.y==dep.y))
    {
      return 1;
    }
  }

  return 0;
}
/*deplacement valide roi */

int deplacement_valide_Roi(coordonnee_t dep, coordonnee_t arriv,partie_t p)
{/*pour ne pas que la fonction deborde*/
  if(dep.x<0 || arriv.x<0 || dep.x>10 || arriv.y>10)
  {
    return 0;
  }
   return 0;

   if(p.joueur==0)
  {
    if((arriv.x==dep.x && arriv.y==dep.y-1)|| (arriv.x==dep.x && arriv.y==dep.y+1)
    || (arriv.x==dep.x+1 && arriv.y==dep.y)|| (arriv.x==dep.x+1 && arriv.y==dep.y-1)
    ||(arriv.x==dep.x+1 && arriv.y==dep.y+1)|| (arriv.x==dep.x-1 && arriv.y==dep.y)
    || (arriv.x==dep.x-1 && arriv.y==dep.y-1)|| (arriv.x==dep.x-1 && arriv.y==dep.y+1))    {
      return 1;
      /**/
    }
    else
    {
      if((arriv.x==dep.x && arriv.y==dep.y-1)|| (arriv.x==dep.x && arriv.y==dep.y+1)
      || (arriv.x==dep.x-1 && arriv.y==dep.y)|| (arriv.x==dep.x-1 && arriv.y==dep.y-1)
      ||(arriv.x==dep.x-1 && arriv.y==dep.y+1)|| (arriv.x==dep.x+1 && arriv.y==dep.y)
      || (arriv.x==dep.x+1 && arriv.y==dep.y-1)|| (arriv.x==dep.x+1 && arriv.y==dep.y+1))    {
        return 1;
      }
    }
  }
  return 0;
}
/*deplacement valide */
int deplacement_valide(coordonnee_t dep , coordonnee_t ariv,partie_t *p)
{

/*condition pour que le les cordonnes de depart et d'arrive ne debordent pas en dehors de la grille*/
  if(dep.x<0 || ariv.x<0 || dep.x>10 || ariv.y>10)
  {
    return 0;
  }
  /*la condition dans le switch permet d'identifier et recupere le caractere*/
  switch (piece_identifier(recuperer_caracterer_contenu_tablier_pos(*(p->tablier),dep.x,dep.y)).type)
   {
     /*joueur 0*/
     case 'P':
     return deplacement_valide_pion(dep,ariv,*p);
     case 'L':
     return deplacement_valide_lance(dep,ariv,*p);
     case 'N':
     return deplacement_valide_cavalier(dep,ariv,*p);
     case 'B':
     return deplacement_valide_fou(dep,ariv,*p);
     case 'R':
     return deplacement_valide_tour(dep,ariv,*p);
     case 'S':
     return deplacement_valide_G_Argent(dep,ariv,*p);
     case 'G':
     return deplacement_valide_G_Or(dep,ariv,*p);
     case 'K':
     return deplacement_valide_Roi(dep,ariv,*p);

     /*joueur1*/
    case 'p':
    return deplacement_valide_pion(dep,ariv,*p);
    case 'l':
    return deplacement_valide_lance(dep,ariv,*p);
    case 'n':
    return deplacement_valide_cavalier(dep,ariv,*p);
    case 'b':
    return deplacement_valide_fou(dep,ariv,*p);
    case 'r':
    return deplacement_valide_tour(dep,ariv,*p);
    case 's':
    return deplacement_valide_G_Argent(dep,ariv,*p);
    case 'g':
    return deplacement_valide_G_Or(dep,ariv,*p);
    case 'k':
    return deplacement_valide_Roi(dep,ariv,*p);
    default:
      printf("Saisiez un caractere valide");
    break;
   }
   return 0;
}
/*faire une fonction pour la promotion*/
