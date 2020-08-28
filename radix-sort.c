/**************************************************
                    基数排序
 **************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "link.h"
#include "tools.h"

void radixSort(int *arr, int len)
{
    // printArr(arr, len);
    int max = 0;
    for (int i = 0; i < len; i++)
        if (arr[i] > max)
            max = arr[i];

    int iterCount = 1;
    while (max /= 10)
        iterCount++;

    LinkNode *arrBuckets[10] = {};
    for (int i = 0; i < 10; i++)
        arrBuckets[i] = createLink();

    for (int i = 0; i < iterCount; i++)
    {
        for (int j = 0; j < len; j++)
        {
            int radix = arr[j] % _pow(10, i + 1) / _pow(10, i);
            linkAdd(arrBuckets[radix], createLinkNode(arr[j]));
        }

        int assignIdx = 0;
        for (int k = 0; k < 10; k++)
        {
            LinkNode *pNode = arrBuckets[k];
            while ((pNode = pNode->next))
                arr[assignIdx++] = pNode->value;
            linkClear(arrBuckets[k]);
        }
    }

    for (int i = 0; i < 10; i++)
        freeLink(arrBuckets[i]);
}