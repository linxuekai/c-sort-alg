/**************************************************
                    希尔排序
 **************************************************/

#include <stdio.h>
#include "tools.h"

void shellSort(int *arr, int len)
{
    int gap = 1;
    int radix = 1;
    while (_pow(2, radix) - 1 <= len / 2)
        radix++;
    radix--;

    while ((gap = _pow(2, radix--) - 1) > 0)
    {
        for (int i = 0; i < gap; i++)
        {
            for (int j = i; j < len; j += gap)
            {
                int insertIdx = j;
                while (insertIdx > i && arr[insertIdx] < arr[insertIdx - gap])
                {
                    swap(arr + insertIdx, arr + insertIdx - gap);
                    insertIdx -= gap;
                }
            }
        }
    }
}