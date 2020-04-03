
#include<stdio.h>
#include<stdlib.h>

void swap(int *a, int *b){
	int temp = *a;
	*a = *b;
	*b = temp;
}

int i,j;
void sorting(int arrival[], int new_arr[], int n){
	int max_platform = 0;
	int curr_platforms = 0;
	int m = n+n;
	for(i=0; i< m-1;i++){
		for(j = 0; j< m-i-1; j++){
			if(arrival[j] > arrival[j+1]) //decreasing order
			{
				swap(&arrival[j], &arrival[j+1]);
				swap(&new_arr[j], &new_arr[j+1]);
			}
		}
	}

	for(i=0; i< n+n ;i++){
		if(new_arr[i] == 1){
			curr_platforms++;
			//printf("\n Arrival: current platforms count %d", curr_platforms);
			new_arr[i] = curr_platforms;
			if( curr_platforms >= max_platform){
				max_platform = curr_platforms;
			}
		}
		else if(new_arr[i] == 0){
				curr_platforms--;
				//printf("\n Departure: current platforms count %d", curr_platforms);
				new_arr[i] = curr_platforms;
				if( curr_platforms >= max_platform){
				max_platform = curr_platforms;
			}
		}
	}
	printf("Min platforms required: %d", max_platform);
}

void countplatforms(int arrival[], int new_arr[], int n){
	sorting(arrival, new_arr, n);
}

int main(){
	int n,i,j;
	printf("\nEnter no. of trains");
	scanf("%d",&n);
	int arrival[n+n], dep[n];
	int new_arr[n+n];
	printf("\nEnter arrival time");
	for(i=0;i<n;i++){
		scanf("%d",&arrival[i]);
		new_arr[i] = 1;
	}
	printf("\nEnter departure time");
	for(i=0;i<n;i++)
		scanf("%d",&dep[i]);
	//merge arrays
	j =0;
	for(i=n;i<n+n; i++){
		arrival[i] = dep[j];
		new_arr[i] = 0; // to add d corresponding to departure array values
		j++;
	}
	countplatforms(arrival, new_arr, n);
	return 0;
}
