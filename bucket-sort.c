/**************************************************
                    桶排序
 **************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "link.h"
#define BUCKETS_COUNT 665

void bucketSort(int *arr, int len)
{
    int minItem = arr[0];
    int maxItem = arr[0];

    for (int i = 1; i < len; i++)
        if (arr[i] < minItem)
            minItem = arr[i];
        else if (arr[i] > maxItem)
            maxItem = arr[i];

    if (!(maxItem > minItem))
        return;

    int step = (maxItem + 1 - minItem) / BUCKETS_COUNT;
    if ((maxItem + 1 - minItem) % BUCKETS_COUNT != 0)
        step += 1;

    printf("minItem = %d\n", minItem);
    printf("maxItem = %d\n", maxItem);
    printf("step = %d\n", step);

    LinkNode *arrBuckets[BUCKETS_COUNT] = {};
    for (int i = 0; i < BUCKETS_COUNT; i++)
        arrBuckets[i] = createLink();

    for (int i = 0; i < len; i++)
    {
        int bucketIdx = (arr[i] - minItem) / step;
        LinkNode *pNode = createLinkNode(arr[i]);
        LinkNode *tarNode = arrBuckets[bucketIdx];
        while (tarNode->next != NULL && tarNode->next->value < arr[i])
            tarNode = tarNode->next;
        linkInsert(tarNode, pNode);
    }

    int storeIdx = 0;
    for (int i = 0; i < BUCKETS_COUNT; i++)
    {
        LinkNode *pNode = arrBuckets[i];
        while ((pNode = pNode->next))
            arr[storeIdx++] = pNode->value;
    }

    for (int i = 0; i < BUCKETS_COUNT; i++)
        freeLink(arrBuckets[i]);
}
