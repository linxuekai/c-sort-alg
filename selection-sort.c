/**************************************************
                    选择排序
 **************************************************/

extern void swap(int *a, int *b);

void selection_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int *min = arr + i;

        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < *min)
                min = arr + j;
        }

        if (min != arr + i)
            swap(min, arr + i);
    }
}