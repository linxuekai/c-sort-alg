/**************************************************
                    选择排序
 **************************************************/

extern void swap(int *a, int *b);

void selectionSort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        int minIdx = i;

        for (int j = i + 1; j < len; j++)
        {
            if (arr[j] < arr[minIdx])
                minIdx = j;
        }

        if (arr[minIdx] != arr[i])
            swap(arr + minIdx, arr + i);
    }
}