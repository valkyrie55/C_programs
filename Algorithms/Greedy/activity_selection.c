#include<stdlib.h>
#include<stdio.h>
#include<string.h>

struct Activity{
	int start, finish;
};

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

//function to sort
void fun(struct Activity arr[], int n){
	 //ascending order
	int i,j;
	for(i=0; i< n-1 ;i++){
		for(j=0; j < n-i-1; j++){
			if(arr[j].finish > arr[j+1].finish){
				swap(&arr[j].finish, &arr[j+1].finish);
				swap(&arr[j].start, &arr[j+1].start);
			}
		}
	}

}

void printactivities(struct Activity arr[], int n){
	int i, j =0;
	//sort acc to finsih time
	fun(arr,n);
	printf("\nSelected activities-------");
	printf("\nStart  Finish\n");
	//start from the first activity 
	printf("%d      %d\n", arr[0].start, arr[0].finish);
	//if starting time of current activity is greater than the finish time 
	// of previous activity then the activity is selected
	for(i=1; i< n;i++){
		if(arr[i].start >= arr[j].finish){
			printf("%d      %d\n", arr[i].start, arr[i].finish);
			j = i;
		}
	}


}

int main(){
	struct Activity arr[6];
	int i,j,n = 6;
	for(i=0;i<n;i++){
		printf("start and finish time\n");
		scanf("%d %d",&arr[i].start, &arr[i].finish);
	}
	printactivities(arr,n);
	return 0;
} 
