#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(int* a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

void reverse(int arr[], int l, int r, int n){
	int i;
	while(l < r){
		swap(&arr[l], &arr[r]);
		l++;
		r--;
	}
}

int main(){
	int arr[] = {1,2,3,4,5,6,7,8,9,10, 11,12,13};
	int i, k, count = 0,t_count = 0, n = sizeof(arr)/ sizeof(arr[0]);
	int init = 0;
	printf("\nEnter k: ");
	scanf("%d", &k);
	for(i = 0; i< n;i++){
		count++;
		t_count++;
		if(count == k){
			//reverse array
			reverse(arr, init, i, n);
			// break;
			init = i+1;
			count = 0;
		}
		if((n - t_count +1) < k)  // if remaining elements < k
			{
				reverse(arr, init, n-1, n);  // reverse all
				break;
			}
	}
for(i = 0;i< n;i++)
printf("%d ", arr[i]);
return 0;
}


