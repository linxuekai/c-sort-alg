/**************************************************
                    归并排序
 **************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

void mergeArr(int *left, int leftLen, int *right, int rightLen, int *target)
{
    int tarIdx = 0;
    int leftIdx = 0;
    int rightIdx = 0;
    int len = leftLen + rightLen;

    while (tarIdx < len)
    {
        if (left[leftIdx] <= right[rightIdx])
        {
            target[tarIdx++] = left[leftIdx++];
            if (leftIdx == leftLen)
                while (rightIdx < rightLen)
                    target[tarIdx++] = right[rightIdx++];
        }
        else
        {
            target[tarIdx++] = right[rightIdx++];
            if (rightIdx == rightLen)
                while (leftIdx < leftLen)
                    target[tarIdx++] = left[leftIdx++];
        }
    }
}

void mergeSort(int *arr, int len)
{
    if (len < 2)
        return;

    int leftLen = len / 2;
    int rightLen = len - leftLen;
    int *left = malloc(sizeof(int) * leftLen);
    int *right = malloc(sizeof(int) * rightLen);

    for (int i = 0; i < len; i++)
    {
        if (i < leftLen)
            left[i] = arr[i];
        else
            right[i - leftLen] = arr[i];
    }

    mergeSort(left, leftLen);
    mergeSort(right, rightLen);
    mergeArr(left, leftLen, right, rightLen, arr);

    free(left);
    free(right);
}
