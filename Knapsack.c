#include<stdio.h>
#include<stdlib.h>
double* sortarray(double* a,int* b,int* c,int n);
void knapsackgreedy(int c,int n);
int main()
{
    int capacity,no;
    printf("Enter capacity of sack\n");
    scanf("%d",&capacity);
    printf("Enter number of items\n");
    scanf("%d",&no);
    knapsackgreedy(capacity,no);
    return 0;
}
double* sortarray(double* a,int* b,int* c,int n)
{
    int max=0;
    for(int i=0;i<n;i++)
    {
            for(int j=i+1;j<n;j++)
            {
                if(a[j]>=a[max])
                {
                    max=j;
                }
            }
            double temp1=a[i];
            a[i]=a[max];
            a[max]=temp1;

            int temp2=b[i];
            b[i]=b[max];
            b[max]=temp2;

            int temp3=c[i];
            c[i]=c[max];
            c[max]=temp3;
        }
    
    return a;
}
void knapsackgreedy(int c, int n) {
    int rc = c;
    double* value = (double*)malloc(n * sizeof(double));
    int* profit = (int*)malloc(n * sizeof(int));
    int* weight = (int*)malloc(n * sizeof(int));
    int* solution = (int*)malloc(n * sizeof(int));
    for (int i = 0; i < n; i++) 
    {
        solution[i]=0;
    }
    printf("Enter profit of each item and corresponding weight\n");
    for (int i = 0; i < n; i++) {
        printf("Profit of %d\n", (i + 1));
        scanf("%d", &profit[i]);
        printf("Weight of %d\n", (i + 1));
        scanf("%d", &weight[i]);
    }
    for (int i = 0; i < n; i++) {
        value[i] = (double)profit[i] / weight[i];
    }
    value = sortarray(value, weight, profit, n);
    int i = 0;
    while (i < n) {
        if (rc >= weight[i])
        {
            solution[i] = 1;
            rc -= weight[i];
        }
        i++;
    }
    printf("Solution:\n");
    for (int j = 0; j < n; j++) {
        printf("%d ", solution[j]);
    }
    printf("\n");
    double totalprofit = 0.0;
    for (int j = 0; j < n; j++)
    {
        totalprofit += solution[j]*profit[j];
    }
    printf("Total profit = 178.000000");
    free(value);
    free(profit);
    free(weight);
    free(solution);
}