#include <stdlib.h>
#include "tools.h"

extern void bubble_sort(int *arr, int len);
extern void selection_sort(int *arr, int len);

int main()
{
    const int arr_len = 100;
    int *alc_arr = gen_random_arr(arr_len, 1, arr_len);

    // bubble_sort(alc_arr, arr_len);
    selection_sort(alc_arr, arr_len);
    print_arr(alc_arr, arr_len);
    free(alc_arr);

    return 0;
}