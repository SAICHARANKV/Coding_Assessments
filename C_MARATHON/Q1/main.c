#include <stdio.h>
#include "head.h"

int main()
{
    unsigned int number;
    int n;
    // Taking Inputs according to limitations.
    printf("Enter a number:\n");
    scanf("%d", &number);
    if (number > 0 && number <= 30)
        gennumseq(number);
    else
    {
        printf("Re enter limit correctly:\t");
        scanf("%d", &n);
        gennumseq(n);
    }

    return 0;
}