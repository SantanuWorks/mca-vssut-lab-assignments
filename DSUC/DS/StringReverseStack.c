#include <stdio.h>
#include <string.h>
#define MAX 100
int top;
char stack[MAX];
void push( char ch ){
	if( top == MAX-1 ) printf("\nOverflow!\n");
	else{
		top ++;
		stack[top] = ch;
		printf("%c", ch);
	}
}
void pop(){
	if( top == -1 ) printf("\nUnderflow!\n");
	else{
		char ch = stack[top];
		top --;
		printf("%c", ch);
	}
}
int main(){
	top = -1;
	int i;
	char str[MAX];
	printf("Enter a string: ");
	gets(str);
	int n = strlen(str);
	printf("Original String: ");
	for( i = 0; i < n; i ++ ) push(str[i]);
	printf("\nReverse String: ");
	for( i = 0; i < n; i ++ ) pop();
}
