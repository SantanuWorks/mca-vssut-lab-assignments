#include <stdio.h>
#define MAX 100
int top;
int stack[MAX];
int isFull(){
	if( top == MAX-1 ) return 1;
	else return 0;
}
int isEmpty(){
	if( top == -1 ) return 1;
	else return 0;
}
void push( int n ){
	if( isFull() ) printf("Overflow!");
	else{
		top ++;
		stack[top] = n;
		printf("%d is pushed!", n);
	}
}
void pop(){
	if( isEmpty() ) printf("Underflow!");
	else{
		int v = stack[top];
		top --;
		printf("%d is popped!", v);
	}
}
void display(){
	if( isEmpty() ) printf("Underflow!");
	else{
		int i;
		for( i = top; i >= 0; i -- ){
			printf("%d ", stack[i]);
		}
	}
}
int main(){
	top = -1;
	int ch;
	int num;
	while(1){
		printf("Choose an operation: ");
		fflush(stdin);
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("Enter number: ");
					scanf("%d", &num);
					push(num);
					break;
			case 2: pop();
					break;
			case 3: display();
					break;
			case 4: return 1;
		}
		printf("\n");
	}
}
