#include<stdio.h>
#include<stdlib.h>
#include<string.h>


int main(){
  	int arr[] = {100,180,260,310,40,535,695}; 
    int n = sizeof(arr) / sizeof(arr[0]); 
    int min = arr[0],max = 0,i = 1, profit = 0;
    int final_profit = 0;
    while(min < arr[i]){
    	if(i == n-1){
    		max = arr[i];
    		// printf("new min: %d\n",min);
    		// printf("new max: %d\n",max);
    		if((max-min) > profit){
    			profit = max-min;
    			final_profit += profit;
    			// printf("Max profit so far: %d\n",profit);
    			break;
    	}
    }
		else if(arr[i] < arr[i+1])
    		++i;
    	else if(!(arr[i] < arr[i+1])){
    		//max found
    		max = arr[i];
    		if((max-min) > profit){
    			profit = max-min;
    			final_profit += profit;
    			// printf("Max profit so far: %d\n",profit);
    			if(i+1 < n){
    				// printf("more elements remaining\n");
    				min = arr[i+1];
    				// printf("new min: %d\n",min);
    				i+=2;
    				// printf("arr[i]: %d\n",arr[i]);
    			}
    		}
    	}
    }
    printf("Max stock profit: %d\n",final_profit);

	return 0;
}
