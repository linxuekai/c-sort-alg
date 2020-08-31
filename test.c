#include <stdlib.h>
#include "tools.h"

// extern void bubbleSort(int *arr, int len);
// extern void selectionSort(int *arr, int len);
// extern void insertionSort(int *arr, int len);
// extern void mergeSort(int *arr, int len);
// extern void quickSort(int *arr, int len);
// extern void countingSort(int *arr, int len);
// extern void radixSort(int *arr, int len);
// extern void bucketSort(int *arr, int len);
// extern void shellSort(int *arr, int len);
extern void heapSort(int *arr, int len);

int main()
{
    const int arrLen = 88;
    int *alcArr = genRandomArr(arrLen, 1, arrLen * 10);

    heapSort(alcArr, arrLen);
    printArr(alcArr, arrLen);
    free(alcArr);

    return 0;
}
