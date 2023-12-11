#include <stdio.h>
#include <stdlib.h>
typedef struct node* NODE;
struct node{
	int data;
	NODE next;
};
NODE start = NULL;
void Insert(){
	printf("\n");
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	NODE newnode;
	newnode = ( NODE ) malloc( sizeof(struct node) );
	newnode -> data  = data;
	newnode -> next  = NULL;
	if( start != NULL ) newnode -> next = start;
	start = newnode;
	printf("\nNew node inserted!\n\n");
}
void Delete(){
	printf("\n");
	if( start == NULL ) printf("\nList is empty!\n\n");
	else{
		NODE delnode = start;
		start = start -> next;
		free(delnode);
		printf("\nNode deleted!\n\n");
	}
}
void revList(){
	NODE temp = NULL, next;
	while( start != NULL ){
		next = start -> next;
		start -> next = temp;
		temp = start;
		start = next;	
	}
	start = temp; 
	printf("\nLinked list reversed!\n\n");
}
void traverse(){
	NODE temp = start;
	printf("\nLinkedList: ");
	while( temp != NULL ){
		printf("%d --> ", temp -> data);	
		temp = temp -> next;
	}
	printf("X\n\n");
}
int main(){
	int op;
	while(1){
		printf("1. Insert \n2. Delete\n3. Reverse List\n4. Traverse\n5. Exit\nEnter operation: ");
		scanf("%d", &op);
		switch(op){
			case 1: Insert(); break;
			case 2: Delete(); break;
			case 3: revList(); break;
			case 4: traverse(); break;
			case 5: return 0;
			default: printf("Invalid option!\n");
		}
	}
}
