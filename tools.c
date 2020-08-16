#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>

/**
 * 交换两个 int 指针的值
 * -------------------- */
void swap(int *a, int *b)
{
    int c = *a;
    *a = *b;
    *b = c;
}

/**
 * 根据给定的长度 n 和 上下限 min, max
 * 生成随机 int 数组
 * -------------------- */
int *gen_random_arr(int len, int min, int max)
{
    assert(min <= max);
    srand(time(NULL));

    int *alc_arr = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        alc_arr[i] = rand() % (max - min + 1) + min;
    }

    return alc_arr;
}

/**
 * 打印数组
 * -------------------- */
void print_arr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf(i < len - 1 ? "%d,\t" : "%d", arr[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}