#ifndef COORDONNEE_H
#define COORDONNEE_H
  struct coordonnee_s{
    int x;
    int y;
  };
  /*declaration des fonctions utilisateur*/
  typedef struct coordonnee_s coordonnee_t;
  coordonnee_t creer_coordonnee(int x,int y);
  void afficher_coordonnee(coordonnee_t p);
  double comparer_coordonnee(coordonnee_t p1,coordonnee_t p2);
#endif
