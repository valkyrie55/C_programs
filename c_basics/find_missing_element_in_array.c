#include <stdio.h>
#include<stdlib.h>
int main() {
    int t,i, n, size;
    //printf("\nEnter no. of testcases");
    scanf("%d",&t);
    while(t){
        //printf("\nEnter n");
        scanf("%d",&n);
        int arr[n-1], n1,n2 = 0,res;
        size = sizeof(arr)/sizeof(arr[0]);
        n1 = n*(n+1)/2;
        //printf("\n%d", n1);
        //for n2
        //printf("\nEnter array-----");
        for(i =0; i<size ;i++){
            scanf("\n%d",&arr[i]);
        }
        //find the sum of the array elements
        for (i = 0; i < size; i++) 
            n2 += arr[i]; 
        res = n1-n2;
        //printf("\nMissing element is %d ",res);
        printf("\n%d", res);
        t--;

}
return 0;
}