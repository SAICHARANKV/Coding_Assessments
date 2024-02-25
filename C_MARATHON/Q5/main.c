#include <stdio.h>
#include "head.h"

int main()
{
    char s[20];
    printf("Enter the string\n");
    gets(s);
    printf("The String entered is:\n");
    puts(s);
    findlongestpalindrome(&s);

}