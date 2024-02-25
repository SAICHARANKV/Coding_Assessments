#include <stdio.h>
#include "head.h"

//For Checking Best score among the scores.
float best_score(float final_scores[],int n)
{
int max=final_scores[0];
    for(int i=1;i<n;i++)
    {
        if(max<final_scores[i])
            max=final_scores[i];   
    }
    return max;
    
}