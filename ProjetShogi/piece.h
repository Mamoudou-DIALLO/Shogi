#ifndef PIECE_H
#define PIECE_H

/*declaration des structures*/
struct piece_s{
  int joueur;
  char type;
  int statut;

};
typedef struct piece_s piece_t;

/*declaration des fonctions*/
piece_t piece_initialiser();
piece_t piece_creer(int j,char t,int s);
int  piece_joueur(piece_t p);
piece_t piece_identifier(char carac);
char piece_caractere(piece_t p);
void piece_afficher(piece_t p);

#endif
