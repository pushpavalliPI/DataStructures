#include<stdio.h>
#include<stdlib.h>
int x[20];
int place(int k, int i) 
{
    for(int j=1; j<=k-1; j++)
    {
        if(x[j]==i || abs(x[j]-i)==abs(j-k)) 
        {
            return 0;
        }
    }
    return 1;
}
void nQueens(int k, int n)
{
    for(int i=1; i<=n; i++)
    if (place(k,i))
    {
        x[k]=i; 
        if(k==n) 
        { 
            for(int r=1; r<=n; r++)
            {
                printf("%d ",x[r]);
            }
            printf("\n");
        }
        else
        nQueens(k+1,n);
    }

}
int main()
{
    int k=1;
    int n;
    printf("Enter the value of n\n");
    scanf("%d",&n);
    printf("All solutions to the %dQueens problem are\n",n);
    nQueens(k,n);
    return 0;
}