#include<stdio.h>
void mergesort(int a[],int start,int end);
void merge(int a[],int i1,int j1,int i2,int j2);
int main() 
{
    int a[30],n,i;
    printf("Enter no of elements:"); scanf("%d",&n);
    printf("Enter array elements:");
    for(i=0;i<n;i++)
        scanf("%d",&a[i]); 
    mergesort(a,0,n-1); 
    printf("\nSorted array is :"); 
    for(i=0;i<n;i++)
        printf("%d ",a[i]);
    return 0;
}
void mergesort(int a[],int start,int end)
{
    int mid; 
    if(start<end) 
    {
        mid=(start+end)/2;
        mergesort(a,start,mid); 
        mergesort(a,mid+1,end); 
        merge(a,start,mid,mid+1,end); 
    } 
}
void merge(int a[],int i1,int i2,int j1,int j2)
{
    int temp[50]; 
    int i=i1,j=j1,k=0;
    while(i<=i2 && j<=j2) 
    {
        if(a[i]<a[j])
            temp[k++]=a[i++];
        else
            temp[k++]=a[j++];
    }
    while(i<=i2) 
        temp[k++]=a[i++];
    while(j<=j2) 
        temp[k++]=a[j++];
    for(i=i1,j=0;i<=j2;i++,j++)
        a[i]=temp[j]; 
}