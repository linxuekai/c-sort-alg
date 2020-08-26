#include <stdlib.h>
#include "tools.h"

// extern void bubbleSort(int *arr, int len);
// extern void selectionSort(int *arr, int len);
// extern void insertionSort(int *arr, int len);
// extern int *mergeSort(int *arr, int len);
// extern int *quickSort(int *arr, int len);
extern int *countingSort(int *arr, int len);

int main()
{
    const int arrLen = 100;
    int *alcArr = genRandomArr(arrLen, 1, arrLen);

    countingSort(alcArr, arrLen);
    printArr(alcArr, arrLen);
    free(alcArr);

    return 0;
}
