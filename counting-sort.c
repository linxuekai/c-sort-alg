/**************************************************
                    计数排序
 **************************************************/
#include <stdlib.h>

void countingSort(int *arr, int len)
{
    /**
     * 根据数组最大值确认创建中间数组的长度
     * -------------------- */
    int maxItem = 0;
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > maxItem)
            maxItem = arr[i];
    }

    int *alcArr = (int *)calloc(maxItem + 1, sizeof(int));
    for (int i = 0; i < len; i++)
    {
        alcArr[arr[i]]++;
    }

    int assignIdx = 0;
    for (int i = 0; i <= maxItem; i++)
    {
        while (alcArr[i]--)
        {
            arr[assignIdx++] = i;
        }
    }

    free(alcArr);
}