#include <stdlib.h>
#include "tools.h"

// extern void bubbleSort(int *arr, int len);
// extern void selectionSort(int *arr, int len);
// extern void insertionSort(int *arr, int len);
// extern void mergeSort(int *arr, int len);
// extern void quickSort(int *arr, int len);
// extern void countingSort(int *arr, int len);
extern void radixSort(int *arr, int len);

int main()
{
    const int arrLen = 100;
    int *alcArr = genRandomArr(arrLen, 1, arrLen);

    radixSort(alcArr, arrLen);
    printArr(alcArr, arrLen);
    free(alcArr);

    return 0;
}
