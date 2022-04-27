#include "./structure.h";
#include "./constant.h";

Case convertArrayToListOfStructure(Case casePremier, int array[], int size){
    Case caseCourant;
    caseCourant = casePremier;

    for(int i = 0; i < size - 1; i++){
        caseCourant->valueFirst = array[i];
        caseCourant->valueSecond = array[i + 1];

        Case caseSuivant;
        caseSuivant->next = caseCourant;
        caseCourant = caseSuivant;
    }

    return caseCourant;
}

int calculRendu(Case casePremier, int array[] ,int size){
    int rendu = 0;
    Case caseCourant = casePremier;

    while(caseCourant != NULL){
        rendu = caseCourant->valueFirst + caseCourant->valueSecond;
        caseCourant = caseCourant->next;
    }
    return rendu;
}