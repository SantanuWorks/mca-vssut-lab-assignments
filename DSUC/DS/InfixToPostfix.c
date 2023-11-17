#include <stdio.h>
#include <string.h>
#define MAX 1000
int top;
char stack[MAX];
int isEmpty(){
	if( top == -1 ) return 1;
	else return 0;
}
void push( char n ){
	top ++;
	stack[top] = n;
}
char pop(){
	char v = stack[top];
	top --;
	return v;
}
char peek(){
	return stack[top];
}
int precedence(char ch){
	if( ch=='(' || ch==')' ) return 4;
	else if( ch=='^' ) return 3;
	else if( ch=='*' || ch=='/' ) return 2;
	else if( ch=='+' || ch=='-' ) return 1;
	else return 0;
}
int associativity(char ch){
	// 0 : right to left
	// 1 : left to right
	if( ch=='^' ) return 0;
	else if( ch=='*' || ch=='/' || ch=='+' || ch=='-' ) return 1;
}
void InfixToPostfix(char ch){
	if( precedence(ch)==0 ) printf("%c", ch);
	else if( isEmpty()==1 || peek()=='(' ) push(ch);
	else if( ch=='(' ) push(ch);
	else if( ch==')' ){
		while(1){
			char t = pop();
			if( t=='(' ) break;
			printf("%c", t);
		}
	}
	else if( precedence(ch) > precedence(peek()) ) push(ch);
	else{
		while(1){
			int com = precedence(ch) < precedence(peek());
			if( com == 1 ){
				char t = pop();
				printf("%c", t);	
				if( precedence(ch) > precedence(peek()) ) break;	
			}
			else{
				if( associativity(ch)==1 ){
					char t = pop();
					printf("%c", t);
					push(ch);
				}
				else{
					push(ch);
					break;
				}			
			}
		}
	}
}
void disp(){
	int i;
	printf("\n[");
	for( i = 0; i <= top; i ++ ) printf("%c", stack[i]);
	printf("]\n");
}
int main(){
	top = -1;
	int i;
	char *exp = "K+L-M*N+(O^P)*W/U/V*T+Q";
	int s = strlen(exp);
	for( i = 0; i < s; i ++ ){
		InfixToPostfix(exp[i]);
		// disp();
	}
	while( isEmpty()==0 ) printf("%c", pop());
}
