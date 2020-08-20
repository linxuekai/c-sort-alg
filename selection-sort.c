/**************************************************
                    选择排序
 **************************************************/

extern void swap(int *a, int *b);

void selection_sort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int min_idx = i;

        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[min_idx])
                min_idx = j;
        }

        if (arr[min_idx] != arr[i])
            swap(arr + min_idx, arr + i);
    }
}