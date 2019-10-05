//swap adjacent elements
#include <stdio.h>
void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
void waveform(int arr[], int n){
    int i,j;
    //swap adjacent elements
    for(i=0;i<n;i+=2){
            swap(&arr[i], &arr[i+1]);
        }

    for(i=0;i<n-1;i++){
        printf("\n%d",arr[i]);
    }
}
int main() {
    int n;
    printf("\n Enter n");
    scanf("%d",&n);
	int arr[n],i;
    printf("\nEnter array----\n");
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    waveform(arr,n);
	printf("\nDone!");
	return 0;
}