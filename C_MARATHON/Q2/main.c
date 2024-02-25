#include <stdio.h>
#include "head.h"

int main()
{
    int n;
    int a[50];
    printf("Enter size of an Array:\t");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(int i=0;i<n;i++)
    {

        scanf("%d",&a[i]);
        if(a[i]<0)
        {
            printf("\nRe enter input:\t");
            a[i]=scanf("%d",&a[i]);
        }
    }
    Arraysorting(a,n);
    return 0;
}