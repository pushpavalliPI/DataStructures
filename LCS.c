#include <stdio.h>
#include <string.h>
#include<stdlib.h>
int longestCommonSubsequence(char X[], char Y[], int m, int n, char direction[m + 1][n + 1]) 
{
    int C[m + 1][n + 1];
    for (int i = 0; i <= m; i++) 
    {
        for (int j = 0; j <= n; j++) 
        {
            if (i == 0 || j == 0) 
            {
                C[i][j] = 0;
                direction[i][j] = '0'; 
            } 
            else if (X[i - 1] == Y[j - 1])
            {
                C[i][j] = C[i - 1][j - 1] + 1;
                direction[i][j] = 'D'; 
            } 
            else if (C[i - 1][j] >= C[i][j - 1]) 
            {
                C[i][j] = C[i - 1][j];
                direction[i][j] = 'U'; 
            } 
            else 
            {
                C[i][j] = C[i][j - 1];
                direction[i][j] = 'L'; 
            }
        }
    }
    int lcsLength = C[m][n];
    char lcs[lcsLength + 1];
    lcs[lcsLength] = '\0';
    int i = m, j = n;
    while (i > 0 && j > 0) 
    {
        if (direction[i][j] == 'D') 
        {
            lcs[--lcsLength] = X[i - 1];
            i--;
            j--;
        } 
        else if (direction[i][j] == 'U') 
        {
            i--;
        } 
        else 
        {
            j--;
        }
    }
    printf("Longest Common Subsequence: %s\n", lcs);

    return C[m][n];
}
int main() 
{
    char X[] = "ABCD";
    char Y[] = "DAEBC";
    int m = strlen(X);
    int n = strlen(Y);
    char direction[m + 1][n + 1];
    int lcsLength = longestCommonSubsequence(X, Y, m, n, direction);
    printf("Length of Longest Common Subsequence for %s and %s is : %d\n",X,Y,lcsLength);
    return 0;
}
