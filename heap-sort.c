/**************************************************
                    堆排序
 **************************************************/
#include "tools.h"

void heapSort(int *arr, int len)
{
    if (len < 2)
        return;

    for (int i = len - 1; i > 0; i--)
    {
        int parentIdx = i % 2 ? (i - 1) / 2 : i / 2;
        if (arr[i] > arr[parentIdx])
            swap(arr + i, arr + parentIdx);
    }
    swap(arr, arr + len - 1);
    heapSort(arr, len - 1);
}
