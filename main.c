#include <stdlib.h>
#include <stdlib.h>

#define MAX_ELEMENT_IN_LIST 100

typedef struct _Case *Case;

struct _Case{
    int valeurPremier;
    int valeurSecondaire;
    Case suivant;
};


int main() {
    int tailleList = 0;
    int list[MAX_ELEMENT_IN_LIST];
    int listOriginal[MAX_ELEMENT_IN_LIST];
    int numChoix, end = 0, tete;

    int fifoRendu = 0;
    int pctrRendu = 0;
    int scamRendu = 0;



    do{
        printf("Rempliser le tableau des cases\n");

        printf("nombre d'element dans votre list: ");
        scanf("%d",&tailleList);

        *list = addList(tailleList);

        copyList(list, listOriginal, tailleList);

        // choisir la methods
        int numChoix = 0;
        printf("choisir la methods a utiliser");
        printf("1- FIFO\n");
        printf("2- PCTR\n");
        printf("3- SCAN\n");

        scanf("%d", &numChoix);

        printf("definiser la tete");
        scanf("%d", &tete);

        sortList(list);
        switch(numChoix){
            case 1:
                Case listValue = fifo(list, listOriginal, tailleList, tete);

                break;
            case 2:
                break;
            case 3:
                break;
            default:
                break;
        }
    }while(!end);

    return 0;
}