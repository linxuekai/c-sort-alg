#include <stdlib.h>

int main2()
{
    int *a = (int *)malloc(8);
    int *b = a;
    free(b);
    a[0] = 1;
    free(a);
}