/**************************************************
                    插入排序
 **************************************************/

extern void swap(int *a, int *b);

void insertionSort(int *arr, int len)
{
    for (int i = 0; i < len; i++)
    {
        for (int j = i + 1; i > 0; j--)
        {
            if (arr[j] >= arr[j - 1])
                break;
            swap(arr + j, arr + j - 1);
        }
    }
}