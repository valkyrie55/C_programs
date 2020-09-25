#include <stdio.h>
#include<stdlib.h>
#include<string.h>

void reverse(char *i, char *j){
    char temp;
    while(i < j){
        temp = *i;
        *i++ = *j;
        *j-- = temp;
    }
}

void reversestring(char *s){
    char *i = s;
    char *temp = s;
    while(*temp){
        temp++;
        if(*temp == '\0')
            reverse(i,temp-1);
        else if(*temp == ' '){
            reverse(i, temp-1);
            i = temp+1;
        }
    }
    //reverse the entire string
    reverse(s,temp-1);
}

int main() 
{ 
    char s[] = "i like the program";
    reversestring(s);
    printf("Reversed string: %s\n",s);
    return 0;
} 
