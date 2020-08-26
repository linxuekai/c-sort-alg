/**************************************************
                    快速排序
 **************************************************/
#include "tools.h"

void quickSort(int *arr, int len)
{
    if (len < 2)
        return;

    int pivot = 0;
    int storeIdx = 1;
    for (int i = 1; i < len; i++)
    {
        if (arr[i] < arr[pivot])
        {
            swap(arr + i, arr + storeIdx);
            storeIdx++;
        }
    }

    swap(arr + pivot, arr + storeIdx - 1);
    pivot = storeIdx - 1;

    quickSort(arr, pivot);
    quickSort(arr + pivot + 1, len - pivot - 1);
}