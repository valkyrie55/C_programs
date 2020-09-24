#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void findsum(int arr[],int n,int sum){
    int *l = &arr[0], *r = &arr[0];
    int l1 = 0, r1 = 0;
    int curr_sum = 0,i = 0;
    while(i <= n){
        if(curr_sum < sum){
            curr_sum += *r;
            // printf("new sum: %d\n",curr_sum);
            ++r;
            ++r1;
            }
        else if (curr_sum > sum){
            curr_sum = curr_sum - *l;
                // printf("new sum: %d\n",curr_sum);
            ++l;
            ++l1;
                }
        if(curr_sum == sum){
            printf("Sum found b/w indices: %d %d\n",l1,r1);
            return;
        }
        i++;
    }
    printf("Sum not found!\n");
}

int main(){
    int arr[] = {1,4,20,3,10,5};
    int n = sizeof(arr)/sizeof(arr[0]);
    int sum = 33;
    findsum(arr,n,sum);
    return 0;
    }
