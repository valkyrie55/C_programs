#include <stdio.h>
#include<stdlib.h>
#include<string.h>

long long convert(int n){
    long long r = 0;
    int rem,i = 1;
    while(n != 0){
        rem = n%2;   //return either 0 or 1
        n = n/2;
        r += rem*i;
        // printf("%11d\n",r);
        i = i * 10;
    }
    return r;
}

int main() {
    int n;
    printf("Enter a decimal number: ");
    scanf("%d", &n);
    printf("Binary of %d is %lld", n, convert(n));
    return 0;
}

