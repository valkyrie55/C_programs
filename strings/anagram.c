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

void sort_string(char str[], int n){
	int i,j;
	for(i = 0; i < n-1 ;i++){   // bubble sort
		for(j = 0; j < n-i-1; j++){
			if(str[j] > str[j+1])
				swap(&str[j], &str[j+1]);
		}
	}
}

int main(){
	char str1[] = "TRIANGLE";
    char str2[] = "INTEGRAL";
    int n1 = strlen(str1);
    int n2 = strlen(str2);
    if(n1 != n2){
    	printf("\nNot Anagrams");
    	return 0;
    }
    int i,j,res;
    printf("\nString before sorting: %s", str1);
    sort_string(str1,n1);
    printf("\nString after sorting: %s", str1);
    printf("\nString before sorting: %s", str2);
    sort_string(str2,n2);
    printf("\nString after sorting: %s", str2); 
    res = strcmp(str1, str2);
    if(res == 0)
        printf("\nAnagrams!");
    else
        printf("\nNot Anagrams");
    return 0;

}
