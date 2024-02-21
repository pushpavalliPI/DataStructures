#include <stdio.h>
void towerOfHanoi(int,int,int,int);
int main()
{
    int x;
    int A,B,C;
    B=2;
    printf("Enter the number of slabs\n");
    scanf("%d",&x);
    printf("Enter from rod\n");
    scanf("%d",&A);
    printf("Enter to rod\n");
    scanf("%d",&C);
    towerOfHanoi(x,A,C,B);
    return 0;
}
void towerOfHanoi(int n,int from_rod,int to_rod,int aux_rod)
{
    if (n==1)
    {
        printf("\nMove disk 1 from rod %d to rod %d",from_rod,to_rod);
        return;
    }
    towerOfHanoi(n-1,from_rod,aux_rod,to_rod);
    printf("\nMove disk %d from rod %d to rod %d",n,from_rod,to_rod);
    towerOfHanoi(n-1,aux_rod,to_rod,from_rod);
}