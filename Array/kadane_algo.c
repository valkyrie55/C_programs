#include <stdio.h>
#include<stdlib.h>
#include<string.h>

int kadane(int arr[], int n){
    int max_so_far = -99999, max = 0;
    int i;
    for(i = 0;i<n;i++){
        max += arr[i];
        if(max_so_far < max)
            max_so_far = max;   //update it
        if(max < 0)
            max = 0;
    }
    return max_so_far;
}


int main() 
{ 
    int a[] = {-2, -3, 4, -1, -2, 1, 5, -3}; 
    int n = sizeof(a)/sizeof(a[0]); 
    int max_sum = kadane(a, n); 
    printf("Maximum contiguous sum is: %d", max_sum);
    return 0; 
} 
