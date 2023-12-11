#include <stdio.h>
#define MAX 100
int top = -1;
int stack[MAX];
void push( int n ){
	if( top==MAX-1 ) printf("Overflow!");
	else{
		top ++;
		stack[top] = n;
		printf("%d is pushed!", n);
	}
}
void pop(){
	if( top==-1 ) printf("Underflow!");
	else{
		int v = stack[top];
		top --;
		printf("%d is popped!", v);
	}
}
void display(){
	if( top==-1 ) printf("Underflow!");
	else{
		int i;
		printf("Stack: ");
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
		printf("--- MENU ---\n1. Push\n2. Pop\n3. Display\n4. Exit\nEnter choice: ");
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
