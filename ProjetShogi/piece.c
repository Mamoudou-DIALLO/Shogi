#include <stdlib.h>
#include <stdio.h>
#include "piece.h"
/*definition des constante*/
#define PROMU 1
#define NON_PROMU 0
/*definition pour les fonctions*/
piece_t piece_initialiser()
{
  piece_t p;
  p.joueur=0;
  p.type='\0';
  p.statut=0;
  return p;
}
/*enlever piece initiliser*/
piece_t piece_creer(int j,char t,int s)
{
  piece_t p;
  p.joueur=j;
  p.type=t;
  p.statut=s;
  return p;
}
int piece_joueur(piece_t p)
{
  return p.joueur;
}
piece_t piece_identifier(char carac)
{
  piece_t pi;
  /*declaration des joueurs*/
  int j0=0,j1=1;
  /*decalration des caracteres des pieces*/
  char P='P';
  char L='L';
  char N='N';
  char B='B';
  char R='R';
  char S='S';
  char G='G';
  char K='K';
  char D='D';
  char J='J';
  char C='C';
  char F='F';
  char T='T';
  char A='A';
  char p='p';
  char l='l';
  char n='n';
  char b='b';
  char r='r';
  char s='s';
  char g='g';
  char k='k';
  char d='d';
  char j='j';
  char c='c';
  char f='f';
  char t='t';
  char a='a';
  /*creation des pieces du jour jo*/
  piece_t Pion = piece_creer(j0,P, NON_PROMU);
  piece_t Lance = piece_creer(j0, L, NON_PROMU);
  piece_t Cavalier = piece_creer(j0, N, NON_PROMU);
  piece_t Fou = piece_creer(j0, B, NON_PROMU);
  piece_t Tour = piece_creer(j0, R, NON_PROMU);
  piece_t General_argent = piece_creer(j0,S, NON_PROMU);
  piece_t General_or= piece_creer(j0,G, NON_PROMU);
  piece_t Roi = piece_creer(j0, K, NON_PROMU);
  piece_t Pp1 = piece_creer(j0,D, PROMU);
  piece_t Pp2 = piece_creer(j0, J, PROMU);
  piece_t Pp3 = piece_creer(j0, C, PROMU);
  piece_t Pp4 = piece_creer(j0, F, PROMU);
  piece_t Pp5 = piece_creer(j0, T, PROMU);
  piece_t Pp6 = piece_creer(j0, A, PROMU);

  /*creation des pieces du jour j1*/
  piece_t lance = piece_creer(j1, l, NON_PROMU);
  piece_t pion = piece_creer(j1, p, NON_PROMU);
  piece_t cavalier = piece_creer(j1, n, NON_PROMU);
  piece_t fou = piece_creer(j1, b, NON_PROMU);
  piece_t tour = piece_creer(j1, r, NON_PROMU);
  piece_t general_argent = piece_creer(j1, s, NON_PROMU);
  piece_t general_or= piece_creer(j1, g, NON_PROMU);
  piece_t roi = piece_creer(j1, k, NON_PROMU);
  piece_t pp1 = piece_creer(j1, d, PROMU);
  piece_t pp2 = piece_creer(j1, j, PROMU);
  piece_t pp3 = piece_creer(j1, c, PROMU);
  piece_t pp4 = piece_creer(j1, f, PROMU);
  piece_t pp5 = piece_creer(j1, t, PROMU);
  piece_t pp6 = piece_creer(j1, a, PROMU);
  /*test du switch pour renvoyer le pion*/
    switch(c)
    {
      case'p':
        pi = pion;
      break;

      case'l':
        pi = lance;
      break;

      case'n':
        pi = cavalier;
      break;
      case'b':
        pi = fou;
      break;

      case'r':
        pi = tour;
      break;

      case's':
        pi = general_argent;
      break;
      case'g':
        pi = general_or;
      break;

      case'k':
        pi = roi;
      break;
      case'd':
        pi = pp1;
      break;
      case'j':
        pi = pp2;
      break;

      case'c':
        pi = pp3;
      break;

      case'f':
        pi = pp4;
      break;
      case't':
        pi = pp5;
      break;

      case'a':
        pi = pp6;
      break;

      case'P':
        pi = Pion;
      break;

      case'L':
        pi = Lance;
      break;

      case'N':
        pi = Cavalier;
      break;
      case'B':
        pi = Fou;
      break;

      case'R':
        pi = Tour;
      break;

      case'S':
        pi = General_argent;
      break;
      case'G':
        pi = General_or;
      break;

      case'K':
        pi = Roi;
      break;
      case'D':
        pi = Pp1;
      break;
      case'J':
        pi = Pp2;
      break;

      case'C':
        pi = Pp3;
      break;

      case'F':
        pi = Pp4;
      break;
      case'T':
        pi = Pp5;
      break;

      case'A':
        pi = Pp6;
      break;

      default: printf("Entrer un caractere valide");
      break;
    }
    /*ici ressaye avec return pi=piece_t lance = piece_creer(j1, l, NON_PROMU) pour gangne en espace et temps*/

    return pi;
}

char piece_caractere(piece_t p)
{
  return p.type;
}
void piece_afficher(piece_t p)
{
  printf("%c",p.type);
}
