#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int are_rotations(char *s1, char* s2){
	int n1 = strlen(s1);
	int n2 = strlen(s2);
	// check if both are same
	if(n1 != n2)
		return 0;
	// allocate new memory with size n1*2 + 1
	char *new_str = (char*)malloc(sizeof(char) * (n1 *2 +1 ));
	new_str[0] = '\0';
	// append s1 in new_str 2 times
	strcat(new_str, s1);
	strcat(new_str, s1);
	// now check if s2 is a substring of new_str

	void *p =  strstr(new_str, s2);
	//free new_str
	free(new_str);
	if(p != NULL)
		return 1;
	else
		return 0;
}

int main(){
	char *s1 = "AACD";
	char *s2 = "ACDA";
	if(are_rotations(s1,s2))
		printf("Yes!");
	else
		printf("No!");
	return 0;
}
