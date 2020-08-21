#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define R 3
#define C 6

void spiral(int m, int n, int arr[R][C]){
	int i, k = 0, l = 0;
	while(k < m && l < n){
		//print 1st row
		for(i = l; i< n;i++)
			printf("%d ", arr[k][i]);
		k++;
		///////////////////////
		//print last column 
		for(i = k; i < m; i++)
			printf("%d ", arr[i][n-1]);
		n--;
		///////////////////////
		//print last row
		for(i = n-1; i >= l; i--)
			printf("%d ", arr[m-1][i]);
		m--;
		///////////////////////
		//print 1st row
		for(i = m-1; i >= k; i--)
			printf("%d ", arr[i][l]);
		l++;
	}
}

int main(){
	int arr[R][C] = { { 1, 2, 3, 4, 5, 6 }, 
                    { 7, 8, 9, 10, 11, 12 }, 
                    { 13, 14, 15, 16, 17, 18 } }; 
	spiral(R,C, arr);
	return 0;
}


