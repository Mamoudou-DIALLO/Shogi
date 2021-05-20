#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "partie.h"

/*declaraction de la fonction a*/
int Menu();
/*FONCTION PRINCIPAL*/
int main()
{
  partie_t * partie;
  partie = partie_creer();
  /*uililistation de la fonction Menu*/
  switch (Menu())
    {
    case 1:
        printf("Veuillez demarrer votre partie \n");
        partie_jouer(partie);

        break;

    default:
        printf("Vous n'avez pas choisit la bonne option!\n");
        break;
    }

    return EXIT_SUCCESS;
}

/*definition de la fonction Menu*/
int Menu()
{
    int menu;

    printf("******Menu*****\n\n");
    printf("Bonjour et bienvenue \n");
    printf("1.Pour demarrer une partie!\n");
    printf("2.!\n");
    printf("3.!\n");
    printf("0.Quitter!\n");
    printf("Faites votre choix\n");
    scanf("%d", &menu);
    return menu;
}
