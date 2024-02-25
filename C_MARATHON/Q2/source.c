#include <stdio.h>
#include "head.h"

int Arraysorting(int arr[], int size)
{
    int even[size];
    int odd[size];
    int j = 0, k = 0;
    // Separating Odd and even integers.
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % 2 == 0)
        {
            even[j] = arr[i];
            j++;
        }
        else
        {
            odd[k] = arr[i];
            k++;
        }
    }
    //  Sorting Arrays
    //  Even-Ascending
    //  Odd- Descending
    sortascending(even, j);
    sortdescending(odd, k);

    int final_size = j + k;
    int sortedarray[final_size];
    int s, count = 0;
    for (int count = 0; count < final_size; count++)
    {
        for (s = 0; s < j; s++)
        {
            sortedarray[count] = even[s];
            count++;
        }
        for (int l = 0; l < k; l++)
        {
            sortedarray[count] = odd[l];
            count++;
        }
    }
    for (int m = 0; m < final_size; m++)
    {
        printf("%d\t", sortedarray[m]);
    }
}

int sortascending(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}

int sortdescending(int a[], int size)
{
    for (int i = 0; i < size - 1; i++)
    {
        for (int j = 0; j < size - 1 - i; j++)
        {
            if (a[j] < a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
            }
        }
    }
}