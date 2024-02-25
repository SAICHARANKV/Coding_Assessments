#include <stdio.h>
#include "head.h"
int main()
{
    int start, end;
    // Taking inputs
    printf("Enter the Numbers:\n");
    scanf("%d %d", &start, &end);
    // Condition for limitations
    if ((start > 999 || end > 999) || (start < 0 || end < 0) || (start > end))
    {
        printf("Re Enter Correct Values\n");
        scanf("%d", &start);
        scanf("%d", &end);
    }
    // Calling function
    findmaxfreqdigit(start, end);
    return 0;
}