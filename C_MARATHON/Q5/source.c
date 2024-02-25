#include <stdio.h>
#include <string.h>
#include "head.h"

char findlongestpalindrome(char *s)
{
    int i = 0, j = 0, count = 0,k=0;
    int len = strlen(s);
    char m[20];
    //Logic
    while (s[i] != 0 && i < len)
    {
        if (s[i] == s[len - 1])
        {

            for (j = i; j < len; j++)
            {
                m[k]=s[j];
                k++;
                
            }
            printf("\n");
            if (strlen(m)== 0 || strlen(m)==1)
            {
                printf("No such palindrome found\n");
            }
            else
            {
                for(int i=0;i<j-1;i++)
                {
                    printf("%c",m[i]);
                }
                printf("\n");
            }
            break;
        }
        else
        {
            i++;
            len--;
        }
    }
}
