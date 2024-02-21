#include <stdio.h>
void swap(int* a, int* b) {
	int t = *a;
	*a = *b;
	*b = t;
}

int split(int arr[], int low, int high) {
	int pivot = arr[high];
	int i = (low - 1);

	for (int j = low; j <= high - 1; j++) {
		if (arr[j] < pivot) {
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i + 1], &arr[high]);
	return (i + 1);
}
void quickSort(int arr[], int low, int high) {
	if (low < high) {
		int mid = spilt(arr, low, high);
		quickSort(arr, low, mid - 1);
		quickSort(arr, mid + 1, high);
	}
}

int main() {
    int n;
    printf("Enter number of elements:  ");
    scanf("%d",&n);
	int arr[n];
    printf("Enter elements to be sorted:\n ");
    for(int j=0;j<n;j++)
    {
        scanf("%d",&arr[j]);
    }
	quickSort(arr, 0, n - 1);
	printf("Sorted array: \n");
	int i;
	for (i = 0; i < n; i++)
		printf("%d\n", arr[i]);
	return 0;
}
