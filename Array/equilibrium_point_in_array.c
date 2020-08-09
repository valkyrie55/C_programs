// 1. Calculate total sum of the array elements
// traverse each element and subtract value from the total keeping track of the sum before and after the index
// compare both the sums and check if leftsum == totalsum
// return the equilibrium point

#include<stdio.h>
#include<stdlib.h>

int find_equilibrium(int arr[], int n){
	int i, sum = 0, leftsum = 0;
	// find total sum of the array elements
	for(i = 0 ; i < n ; i++)
		sum += arr[i];
	for(i=0; i<n ;i++){
		sum = sum - arr[i];   //reduction in overall sum
		if (sum == leftsum)
			return i;
		leftsum += arr[i];
		}
	return -1;
}

int main(){
	int n,i;
	printf("\nEnter the size of the array");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter array elements");
	for(i=0;i<n;i++)
		scanf("%d", &arr[i]);
	printf("\nEquilbrium point: %d", find_equilibrium(arr,n));
	return 0;
}
