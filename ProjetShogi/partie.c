#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partie.h"
/*declaration des constante pour aquit le tour*/
#define joueur0 0
#define joueur1 1
/*definition des fonction*/

/*fonction modifier case*/
void modifier_case(partie_t *p, piece_t piece, int x, int y)
{
  p->tablier->plateau[x][y] = piece_caractere(piece);
}

/*changer joueur*/
void changer_joueur(partie_t * p)
{
  if(p->joueur==0){
    p->joueur=1;
  }
  p->joueur=0;
}

/*fonction de deplacement*/
void deplacement(partie_t *p, coordonnee_t dep, coordonnee_t arriv)
{

/*  if(!case_vide(p->tablier,arriv))
  {
    reserve_ajouter(p->tablier->plateau[arriv.x][arriv.y]);
  }*/
  p->tablier->plateau[dep.x][dep.y] = p->tablier->plateau[arriv.x][arriv.y];
}


/*fonction de saisi d'une case*/
coordonnee_t saisie_case()
{
  coordonnee_t cord;
  do {
    printf("Veuillez entrer des coordonnés de votre case ");
    scanf("%d %d ",&(cord.x),&(cord.y) );
  } while(cord.x<0 || cord.y<0|| cord.x<10 || cord.y<10);
  return cord;
}
/*fonction creer partie*/
partie_t *partie_creer()
{
  partie_t * p=malloc(sizeof(partie_t));
  p->tablier=initialiser_tablier();
  p->liste=initialiser_liste();
  p->joueur=joueur0;
  return p;
}

/*fonction detruire*/
void partie_detruire(partie_t * p)
{
  free(p);
}

void partie_jouer(partie_t *p)
{
  int jeu_en_cours= 1;
  int a,b,c,d;
  coordonnee_t depart,arrivee;
  initialiser_tablier_debut_partie(p->tablier);
  while(jeu_en_cours)
  {

    printf("Joueur %d\n",p->joueur);
    printf("Donner les coordonnees du depart et arrivee\n");
    scanf("%d %d %d %d",&a,&b,&c,&d);
    if(a<10 && a>0 && b<10 &&b>0 && c<10 && c>0 && d<10 && d>0)
    {
      depart.x = a;
      depart.y=b;
      arrivee.x=c;
      arrivee.y=d;
      if(deplacement_valide(depart,arrivee,p)==1)
      {
        /*deplacement(p,depart,arrivee);*/
        changer_joueur(p);
        initialiser_tablier_debut_partie(p->tablier);
      }
      else
      {
        printf("Vous ne pouvez pas effectuer de deplacement\n");
      }
    }
  }


  }

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
        printf("Saisiez un caractere valide\n");
      break;
     }
     return 0;
  }
  /*faire une fonction pour la promotion*/
