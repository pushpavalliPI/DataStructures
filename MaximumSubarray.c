#include <stdio.h>
#include <stdlib.h>
int max(int a, int b) 
{
    if (a > b) 
    {
        return a;
    }
    else 
    {
        return b;
    }
}
int find_max_crossing_subarray(int arr[], int low, int mid, int high) 
{
    int left_sum = -1000;
    int sum = 0;
    int max_left = mid;
    for (int i = mid; i >= low; i--) 
    {
        sum += arr[i];
        if (sum > left_sum)
        {
            left_sum = sum;
            max_left = i;
        }
    }

    int right_sum = -1000;
    sum = 0;
    int max_right = mid + 1;
    for (int i = mid + 1; i <= high; i++)
    {
        sum += arr[i];
        if (sum > right_sum) 
        {
            right_sum = sum;
            max_right = i;
        }
    }
    return left_sum + right_sum;
}
int find_max_subarray(int arr[], int low, int high) 
{
    if (low == high)//one element
    {
        return arr[low];
    }
    int mid = (low + high) / 2;
    int left_max = find_max_subarray(arr, low, mid);
    int right_max = find_max_subarray(arr, mid + 1, high);
    int cross_max = find_max_crossing_subarray(arr, low, mid, high);

    return max(max(left_max, right_max), cross_max);
}
int main() 
{
    int size;
    printf("Enter number of elements in the array\n");
    scanf("%d",&size);
    int* arr =(int*)malloc(size*sizeof(int));
    printf("Enter array elements\n");
    for(int i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    int result = find_max_subarray(arr, 0, size - 1);
    printf("Maximum subarray sum: %d\n", result);
    return 0;
}
