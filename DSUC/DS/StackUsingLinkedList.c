#include <stdio.h>
#include <stdlib.h>

struct node{
	int data;
	struct node* next;
};

typedef struct node* NODE;

NODE top = NULL;

NODE createNode( int data ){
	NODE newnode = ( NODE ) malloc( sizeof( struct node ) );
	newnode -> next = NULL;
	newnode -> data = data;
	return newnode;
}

void push(){
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	NODE newnode = createNode( data );
	if( top == NULL ){
		top = newnode;
	}
	else{
		newnode -> next = top;
		top = newnode;	
	}
	printf("%d is pushed!\n", top -> data);
}

void pop(){
	if( top == NULL ) printf("Stack Underflow!\n");
	else{
		printf("%d is poped!\n", top -> data);
		top = top -> next;
	}
}

void traverse(){
	NODE temp = top;
	if( temp == NULL ) printf("Stack is empty!");
	else{
		printf("Stack: ");
		while( temp != NULL ){
			printf("%d ", temp -> data);
			temp = temp -> next;		
		}
	}
	printf("\n");
}

int main(){
	int ch;
	while(1){
		printf("1. Push\n2. Pop\n3. Traverse\n4. Exit\nChoose op: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: push(); break;
			case 2: pop(); break;
			case 3: traverse(); break;
			case 4: return 1;
		}
	}
}
