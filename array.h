int addList(int size);

int sortList(int *list, int sizeList);

int searchHeadIndex(int *list, int sizeList, int valueSearched);

void copyList(int *list, int *copy,int size);

void addElementInFirstToArray(int *list, int firstElement, int size);

int cutToSence(int array[], int indexHead, int sence, int size);

int trieArrayBySence(int array[], int indexHead, int size, int sence);

int generateArrayBySence(int list[], int sence, int head, int size);

int identifySence(int left, int right, int center);

int identifySenceListPctr(int *list, int size, int head);

int identifySenceListScan(int *list, int size, int head, int lastHead);