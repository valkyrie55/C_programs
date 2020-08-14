#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void swap(char *x, char *y) 
{ 
    char temp; 
    temp = *x; 
    *x = *y; 
    *y = temp; 
}

void permute(char *a, int l, int r){
	int i;
	if(l == r)
		printf("%s\n", a);   // base condition
	else{
		for(i = l;i <= r;i++){
			swap((a+l), (a+i));
			permute(a, l+1, r);
			swap((a+l), (a+i));
		}
	}
}

int main(){
	char str[] = "ABC";
	int n = strlen(str);
	printf("\nAll permutations: ");
	permute(str,0, n - 1);
	return 0;
}
