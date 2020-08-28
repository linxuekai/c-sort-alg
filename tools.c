#include <stdlib.h>
#include <time.h>
#include <assert.h>
#include <stdio.h>

/**
 * 交换两个 int 指针的值
 * -------------------- */
void swap(int *a, int *b)
{
    if (a == b)
        return;

    int c = *a;
    *a = *b;
    *b = c;
}

/**
 * 根据给定的长度 n 和 上下限 min, max
 * 生成随机 int 数组
 * -------------------- */
int *genRandomArr(int len, int min, int max)
{
    assert(min <= max);
    srand(time(NULL));

    int *alcArr = (int *)malloc(len * sizeof(int));
    for (int i = 0; i < len; i++)
    {
        alcArr[i] = rand() % (max - min + 1) + min;
    }

    return alcArr;
}

/**
 * 打印数组
 * -------------------- */
void printArr(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        printf(i < len - 1 ? "%d,\t" : "%d", arr[i]);
        if ((i + 1) % 10 == 0)
            printf("\n");
    }
}

int _pow(int num, unsigned int radix)
{
    if (radix == 0)
        return 1;

    int result = 1;
    while (radix--)
        result *= num;

    return result;
}