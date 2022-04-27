
#include "./structure.h";
#include "./array.h";
#include "./constant.h";

Case calculList(int *list, int size)
{
    Case caseCourant;
    Case casePremier;
    for (int i = 0; i < size; i++)
    {
        caseCourant->valueFirst = list[i];
        caseCourant->valueSecond = list[i + 1];

        Case caseSuivant;
        caseSuivant->next = caseCourant;
        caseCourant = caseSuivant;
    }
    return caseCourant;
};

Case fifo(int *originalList, int size, int head, int lastHead);
Case pctr(int *list, int size, int head, int lastHead);
Case scan(int *list, int size, int head, int lastHead);

Case fifo(int *originalList, int size, int head, int lastHead)
{
    Case casePremier;

    int tmpOriginalList[MAX_ELEMENT_IN_LIST];
    copyList(originalList, tmpOriginalList, size);

    addElementInFirstToArray(tmpOriginalList, head, size);

    convertArrayToListOfStructure(casePremier, tmpOriginalList, size);

    return casePremier;
}

Case pctr(int *list, int size, int head, int lastHead)
{
    Case casePremier;
    int sence = 0;

    int tmpOriginalList[MAX_ELEMENT_IN_LIST];
    copyList(list, tmpOriginalList, size);

    sence = identifySenceListPctr(list, size, head);
    if (sence == 0)
    {
        // scam method
        return scan(*list, size, head, lastHead);
    }
    else
    {
        *tmpOriginalList = generateArrayBySence(tmpOriginalList, sence, head, size);
        convertArrayToListOfStructure(casePremier, tmpOriginalList, size);
        
    }

    return casePremier;
}

Case scan(int *list, int size, int head, int lastHead)
{
    Case casePremier;
    int sence = 0;

    int tmpOriginalList[MAX_ELEMENT_IN_LIST];
    copyList(list, tmpOriginalList, size);

    sence = identifySenceListScan(list, size, head, lastHead);
    if(sence == 0){
        printf("Method scan ne peux pas etre traiter sans un changement entre la tete du disque actual par rapport au precedante");
        return casePremier;
    } else {
        *tmpOriginalList = generateArrayBySence(tmpOriginalList, sence, head, size);
        convertArrayToListOfStructure(casePremier, tmpOriginalList, size);
    }
    
    return casePremier;
}