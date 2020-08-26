/**************************************************
                    归并排序
 **************************************************/
#include <stdlib.h>
#include <stdio.h>
#include "tools.h"

void merge_arr(int *left, int left_len, int *right, int right_len, int *target)
{
    int tarIdx = 0;
    int leftIdx = 0;
    int rightIdx = 0;
    int len = left_len + right_len;

    while (tarIdx < len)
    {
        if (left[leftIdx] <= right[rightIdx])
        {
            target[tarIdx++] = left[leftIdx++];
            if (leftIdx == left_len)
                while (rightIdx < right_len)
                    target[tarIdx++] = right[rightIdx++];
        }
        else
        {
            target[tarIdx++] = right[rightIdx++];
            if (rightIdx == right_len)
                while (leftIdx < left_len)
                    target[tarIdx++] = left[leftIdx++];
        }
    }
}

void merge_sort(int *arr, int len)
{
    if (len < 2)
        return;

    int left_len = len / 2;
    int right_len = len - left_len;
    int *left = malloc(sizeof(int) * left_len);
    int *right = malloc(sizeof(int) * right_len);

    for (int i = 0; i < len; i++)
    {
        if (i < left_len)
            left[i] = arr[i];
        else
            right[i - left_len] = arr[i];
    }

    merge_sort(left, left_len);
    merge_sort(right, right_len);
    merge_arr(left, left_len, right, right_len, arr);

    free(left);
    free(right);
}
