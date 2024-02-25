#include <stdio.h>
#include "head.h"

int gennumseq(int n)
{
    unsigned int num = 3;
    int a[n];
    a[0] = 3;
    printf("%d\t", num);
    // Logic
    for (int i = 1; i <= n; i++)
    {
        a[i] = (num * 2) - 1;
        num = a[i];
    }
    // Printing
    for (int i = 1; i < n; i++)
    {
        printf("%d\t", a[i]);
    }

    printf("\n");
}
