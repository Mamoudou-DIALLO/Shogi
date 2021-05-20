#include <stdio.h>
#include <stdlib.h>
#include "tablier.h"
/*definition des fonction*/

tablier_t * initialiser_tablier()
{
  tablier_t *tab=malloc(sizeof(tablier_t));
  int i,j;
  for(i=0;i<11;i++)
  {
    for(j=0;j<11;j++)
    {
      tab->plateau[i][j]='.';
    }
  }
  return tab;
}
/*fonction d'afficahage du tablier avec les points*/

void affichier_plateau(tablier_t t)
{
  int i,j,k;
  printf("  ");
  /*afficher les iinde de 0 à 10 pour les lignes*/
  for(k=0;k<11;k++)
  {
    printf(" %d ",k );
  }
  printf("\n" );
  /*boucle pour afficher les points*/
  for(i=0;i<11;i++)
  {
    printf("%2d",i );/*afficher les indice des colonnes*/
    for(j=0;j<11;j++)
    {
      printf(" %c ",t.plateau[i][j] );
    }
    printf("\n");
  }
}

int case_vide(tablier_t t, coordonnee_t c)
{
  if(t.plateau[c.x][c.y]=='.')
		return 1;
  return 0;
}

/*initialisation du  tablier en debut de partie*/
void initialiser_tablier_debut_partie(tablier_t * t){
 int i,j;

	for(i=0;i<11;i++)
		for(j=0;j<11;j++)
                    t->plateau[i][j]='.';


	  t->plateau[1][1]='L';
  	t->plateau[1][2]='N';
  	t->plateau[1][3]='S';
  	t->plateau[1][4]='G';
  	t->plateau[1][5]='K';
  	t->plateau[1][6]='G';
  	t->plateau[1][7]='S';
  	t->plateau[1][8]='N';
  	t->plateau[1][9]='L';
	  t->plateau[2][2]='R';
  	t->plateau[2][8]='B';
  	t->plateau[3][1]='P';
	  t->plateau[3][2]='P';
  	t->plateau[3][3]='P';
	  t->plateau[3][4]='P';
  	t->plateau[3][5]='P';
  	t->plateau[3][6]='P';
  	t->plateau[3][7]='P';
  	t->plateau[3][8]='P';
  	t->plateau[3][9]='P';
	  t->plateau[9][1]='l';
  	t->plateau[9][2]='n';
  	t->plateau[9][3]='s';
  	t->plateau[9][4]='g';
  	t->plateau[9][5]='k';
  	t->plateau[9][6]='g';
  	t->plateau[9][7]='s';
  	t->plateau[9][8]='n';
  	t->plateau[9][9]='l';
	  t->plateau[8][8]='r';
  	t->plateau[8][2]='b';
  	t->plateau[7][1]='p';
	  t->plateau[7][2]='p';
  	t->plateau[7][3]='p';
  	t->plateau[7][4]='p';
  	t->plateau[7][5]='p';
  	t->plateau[7][6]='p';
  	t->plateau[7][7]='p';
  	t->plateau[7][8]='p';
  	t->plateau[7][9]='p';

	affichier_plateau(*t);
}
/*fonctions pour modifier le cotenu d'un case */

void modifier_contenu_tablier_pos(tablier_t t,char car,int x,int y)
{


  t.plateau[x][y]=car;
}

char recuperer_caracterer_contenu_tablier_pos(tablier_t t,int x,int y)
{
  char carac;
  carac=t.plateau[x][y];
  return carac;
}
