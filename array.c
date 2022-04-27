#include "./constant.h"
#include "./array.h"

int addList(int size)
{
    int tailleList;
    int list[MAX_ELEMENT_IN_LIST];
    printf("rempliser une liste des piles: \n");

    for (int i = 0; i < tailleList; i++)
    {
        printf("Insere la %d element dans votre list :", i + 1);
        scanf("%d", list[i]);
    }
    return list;
}

void sortList(int *list, int sizeList)
{
    int tmp = 0;
    for (int i = 0; i < sizeList; i++)
    {
        for (int j = 0; j < sizeList; j++)
        {
            if (list[i] > list[j])
            {
                tmp = list[j];
                list[i] = list[j];
                list[j] = tmp;
            }
        }
    }
}

void addElementInFirstToArray(int *list, int firstElement, int size){
    int tmpList[MAX_ELEMENT_IN_LIST];
    copyList(list, tmpList, size);
    if(list[0] != firstElement){
        list[0] = firstElement;
        for(int i = 0; i < size; i++){
            list[i + 1] = tmpList[i];
        }
    } 
}

int searchHeadIndex(int *list, int sizeList, int valueSearched)
{
    for (int i = 0; i < sizeList; i++)
    {
        if ((list[i] == valueSearched) || (list[i] < valueSearched && list[i + 1] > valueSearched))
        {
            return i;
        }
        return i;
    }
}

void copyList(int *list, int *copy, int size)
{
    for (int i = 0; i < size; i++)
    {
        copy[i] = list[i];
    }
}

int identifySence(int left, int right, int center)
{
    if (right - center == center - left)
    {
        return 0; // echec
    }
    else if (right - center < center - left)
    {
        return 1; // right
    }
    else
    {
        return 2; // left
    }
}

int identifySenceListPctr(int *list, int size, int head)
{
    int indexHead;
    indexHead = searchHeadIndex(list, size, head);
    if (list[indexHead] == head)
    {
        return identifySence(list[indexHead - 1], list[indexHead + 1], head);
    }
    if (list[indexHead] < head)
    {
        return identifySence(list[indexHead], list[indexHead + 1], head);
    }
}

int identifySenceListScan(int *list, int size, int head, int lastHead){
    int indexHead;
    indexHead = searchHeadIndex(list, size, head);

    if(head == lastHead){
        return 0; // echec
    } else if(head > lastHead){
        return 1; // right
    } else {
        return 2; // left
    }
}

int cutToSence(int array[], int indexHead, int sence, int size){
    int tmpArray[MAX_ELEMENT_IN_LIST];
    copyList(array, tmpArray, size);
    int indexStart;
    if((indexHead > 0 || indexHead < size)){
        if(sence == 1){
            indexStart = indexHead + 1;
        }else {
            indexStart = indexHead - 1;
        }
    }else{
        indexStart = indexHead;
    }

    if(sence == 1){
        for(int i = indexStart; i < size; i++){
            tmpArray[ indexStart- i ] = array[i];
        }
        for(int i = indexStart - 1; i >= 0; i--){
            tmpArray[indexStart] = array[i];
        }
    }else {
        for(int i = indexStart; i >= 0; i--){
            tmpArray[indexStart] = array[i];
        }
        for(int i = indexStart +1 ; i < size; i++){
            tmpArray[ indexStart- i ] = array[i];
        }
    }
    return tmpArray;
}

int trieArrayBySence(int array[], int indexHead, int size, int sence) {
    int tmpArray[MAX_ELEMENT_IN_LIST];
    copyList(array, tmpArray, size);

    if(sence == 1){
        *tmpArray = cutToSence(tmpArray, indexHead, sence, size);
    }else{
        *tmpArray = cutToSence(tmpArray, indexHead, sence, size);
    }
    return tmpArray;
}

int generateArrayBySence(int list[], int sence, int head, int size){
    int tmpList[MAX_ELEMENT_IN_LIST];
    copyList(list, tmpList, size);

    int indexOfHead;
    indexOfHead = searchHeadIndex(tmpList, size, head);

    *tmpList = trieArrayBySence(tmpList, indexOfHead, size, sence);

    return tmpList;
}