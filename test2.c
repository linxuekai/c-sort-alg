#include <stdio.h>

int main2()
{
    int a = 1;
    int *p1 = &a;
    int *p2 = &a;

    printf("p1 == p2 => %d\n", p1 == p2);

    return 0;
}