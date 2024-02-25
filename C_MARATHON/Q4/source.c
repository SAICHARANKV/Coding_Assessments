#include <stdio.h>
#include "head.h"

void findmaxfreqdigit(int start, int end)
{
    int digitfrequency[10] = {0};
    for (int i = start; i <= end; i++)
    {
        int num = i;
        //Logic for count digits in each number
        while (num != 0)
        {
            int rem = num % 10;
            num = num / 10;
            digitfrequency[rem]++;
        }
    }
    for (int j = 0; j < 10; j++)
    {
        printf("Digit %d appears %d times in %d to %d\n", j, digitfrequency[j], start, end);
    }
    max(digitfrequency);
}

//Finding max repeated digit
int max(int arr[])
{
    int max = arr[0];
    int max_digit=0;
    for (int i = 1; i < 10; i++)
    {
        if (max < arr[i])
        {
            max = arr[i];
            max_digit=i;
        }
    }
    int ans = max;
    printf("The Max Frequency number is %d repated for %d times\n", max_digit,ans);
}