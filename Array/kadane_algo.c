#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int main(){
	int n, i, max_so_far = 0, max_ending_here = 0;
	printf("\nEnter array size: ");
	scanf("%d", &n);
	int arr[n];
	printf("\nEnter array elements:");
	for (i = 0;i < n; i++)
		scanf(" %d", &arr[i]);
	for(i = 0; i < n; i++){
		max_ending_here += arr[i];
		if(max_so_far < max_ending_here)
			max_so_far = max_ending_here;
		if(max_ending_here < 0)
			max_ending_here = 0;
	}
	printf("\nMax. contiguous sum: %d", max_so_far);
	return 0;
}
