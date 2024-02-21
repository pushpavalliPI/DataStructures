#include<stdio.h>
#include<stdlib.h>
int a[30][30];
int q[30];
int visited[30];
int f=0,r=0,n,v;
void bfs(int v)
{
    int i;
    if(f==0 && r==0)
    {
        q[1]=v;
        visited[v]=1;
        f++;
        r++;
    }
    for(i=1;i<=n;i++)
    {
        if(a[v][i] && !visited[i])
        {
            q[++r]=i;
            visited[i]=1;
        }
    }
    if(f<=r)
    {
        f++;
        visited[q[f]]=1;
        bfs(q[f++]);
    }
}
void printqueue()
{
    for(int i=1;i<=n;i++)
    {
        printf("%d ",q[i]);
    }
    printf("\n");
}
void dfs(int v)
{
    int i,count=1;
    visited[v]=1;
    for(i=1;i<=n;i++)
    {
        if(a[v][i] || !visited[i])
        {
            if(count<n-1)
            {
                printf("%d -> %d\n",v,i);
                dfs(i);
                count++;
            }
        }
    }
    
}
int main()
{
    int x;
    printf("Enter number of nodes in the grpah\n");
    scanf("%d",&n);
    printf("Enter graph data in matrix form");
    for(int i=1;i<=n;i++)
    {
        for(int j=1;j<=n;j++)
        {
            printf("\nV%d to V%d: ",i,j);
            scanf("%d",&a[i][j]);
        }
    }
    printf("Enter the starting vertex\n");
    scanf("%d",&x);
    printf("BFS: ");
    bfs(x);
    printqueue();
    printf("DFS: ");
    dfs(x);
    return 0;
}