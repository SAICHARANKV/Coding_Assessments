#include <stdio.h>
#include "head.h"

int main()
{
    // No.of candidates
    int n;
    printf("Enter number of candidates:\t");
    scanf("%d", &n);
    best a[n];
    float final_scores[n];
    // Inputs
    for (int i = 0; i < n; i++)
    {
        printf("enter candidate id\t");
        scanf("%d", &a[i].candidateid);
        printf("Enter scores:\t");
        int sum = 0;
        float avg = 0;
        // Score Inputs and sum for each candidate
        for (int i = 0; i < 3; i++)
        {
            scanf("%d", &a[i].scores[i]);
            sum += a[i].scores[i];
        }
        // Average of each score
        avg = (float)sum / 3;
        // Collecting Averages
        final_scores[i] = avg;
    }
    // Finding best average score
    float max = best_score(final_scores, n);
    for (int i = 0; i < n; i++)
    {
        if (max == final_scores[i])
            printf("The Selected Candidate with the highest average score is candidate %d with an average score %f\n", a[i].candidateid, final_scores[i]);
    }
    // Successful Execution and exiting from loop.
    return 0;
}