#include <stdio.h>
#include <stdlib.h>

typedef struct node* NODE;
int count = 0;

struct node{
	int data;
	NODE next;
};

NODE start = NULL;

NODE createNode(){
	int data;
	printf("Enter data: ");
	scanf("%d", &data);
	NODE newnode;
	newnode = ( NODE ) malloc( sizeof(struct node) );
	newnode -> data  = data;
	newnode -> next  = NULL;
	return newnode;
}

void insertAtBeg(){
	printf("\n");
	if( start == NULL ) start = createNode();
	else{
		NODE newnode  = createNode();
		newnode -> next = start;
		start = newnode;
	}
	count ++;
	printf("\nNew node inserted at begining!\n\n");
}

void insertAtEnd(){
	NODE temp = start;
	printf("\n");
	if( temp == NULL ) temp = createNode();
	else{
		NODE newnode = createNode();
		while( temp -> next != NULL ) temp = temp -> next;
		temp -> next = newnode;
	}
	count ++;
	printf("\nNew node inserted at end!\n\n");
}

void insertInBet(){
	int n;
	printf("\nEnter pos: ");
	scanf("%d", &n);
	if( start == NULL || n==1 ) insertAtBeg();
	else if( n<1 || n>count ) printf("\nInvalid Position!\n\n");
	else{
		NODE newnode = createNode();
		NODE prev = NULL, temp = start;
		int in = 1;
		while( in != n ){
			prev = temp;
			temp = temp -> next;
			in ++;
		}
		prev -> next = newnode;
		newnode -> next = temp;
		count ++;
		printf("\nNew node inserted at %d!\n\n", in);		
	}
}

void deleteAtBeg(){
	printf("\n");
	if( start == NULL ) printf("\nList is empty!\n\n");
	else{
		NODE delnode = start;
		start = start -> next;
		free(delnode);
		count --;
		printf("\nNode deleted at begining!\n\n");
	}
}

void deleteAtEnd(){
	NODE temp = start, prev = NULL;
	printf("\n");
	if( temp == NULL ) printf("\nList is empty!\n\n");
	else if( temp -> next == NULL ){
		start = NULL;
		count --;
		printf("\nNode deleted at end!\n\n");
	}
	else{
		while( temp -> next != NULL ){
			prev = temp;
			temp = temp -> next;
		}
		prev -> next = NULL;
		count --;
		printf("\nNode deleted at end!\n\n");
	}
	free(temp);
}

void deleteInBet(){
	int n, in = 1;
	printf("\nEnter pos: ");
	scanf("%d", &n);
	if( start == NULL || n==1 ) deleteAtBeg();
	else if( n<1 || n>count ) printf("\nInvalid Position!\n\n");
	else if( n==count ) deleteAtEnd();
	else{
		NODE prev = NULL, temp = start, delnode = temp;
		while( in != n ){
			prev = temp;
			temp = temp -> next;
			in ++;
		}
		temp = temp -> next;
		prev -> next = temp;
		free(delnode);
		count --;
		printf("\nNew node deleted at %d!\n\n", in);		
	}
}

void sortList(){
	NODE curr, prev;
	int i, j, flg = 0;
	for( i = 0; i < count - 1; i ++ ){
		flg = 0;
		curr = start;
		for( j = 0; j < count - 1 - i; j ++ ){
			prev = curr;
			curr = curr -> next;
			if( prev -> data > curr -> data ){
				int t = prev -> data;
				prev -> data = curr -> data;
				curr -> data = t;
				flg = 1;
			}
		}
		if( flg==0 ) break;
	}
	printf("\nLinked list sorted!\n\n");		
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
		printf("1. Insert at beginning\n2. Insert in between\n3. Insert at end\n4. Delete at beginning\n5. Delete in between\n6. Delete at end\n7. Sort\n8. Reverse List\n9. Traverse\n10. Exit\nEnter operation: ");
		scanf("%d", &op);
		switch(op){
			case 1: insertAtBeg(); break;
			case 2: insertInBet(); break;
			case 3: insertAtEnd(); break;
			case 4: deleteAtBeg(); break;
			case 5: deleteInBet(); break;
			case 6: deleteAtEnd(); break;
			case 7: sortList(); break;
			case 8: revList(); break;
			case 9: traverse(); break;
			case 10: return 0;
			default: printf("Invalid option!\n");
		}
	}
	return 0;
}
