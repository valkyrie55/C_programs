#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void bubble_sort(int arr[], int dep[], int n){
	int i,j;
	for(i = 0; i< n-1 ;i++){
		for(j = 0;j< n-i-1; j++){
			if(arr[j] > arr[j+1]){
				swap(&arr[j], &arr[j+1]);
				swap(&dep[j], &dep[j+1]);
			}
		}
	}
}

int main(){
	int n, platforms = 0;
	printf("\nEnter no. of trains");
	scanf("%d", &n);
	if(n == 2)  // only 2 trains
		platforms++;    // min one platform is needed
	int arr[n], dep[n];
	int i,j;
	for (i = 0;i < n; i++){
		printf("\nArrival: ");
		scanf(" %d", &arr[i]);
		printf("\nDeparture: ");
		scanf(" %d", &dep[i]);
}
// sort the array
	bubble_sort(arr, dep, n);
	printf("\nSorted timings: ");
	for(i = 0; i < n ; i++){
		printf("\nArrival: %d   Departure: %d", arr[i], dep[i]);
	}
	for (i = 0; i < n-1;i++){
		if(dep[i] > arr[i+1]){
			printf("\nOne more platform needed");
			++platforms;
		}
	}
	printf("\nPlatforms required: %d", platforms);
	return 0;
}
