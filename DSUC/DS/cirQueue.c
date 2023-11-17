#include <stdio.h>
#define MAX 5

int queue[MAX];
int front = -1;
int rear = -1;

void enQueue( int val ){
	if( (rear == MAX-1 && front == 0) || (front == rear+1) ) printf("\nQueue is full!\n\n");
	else{
		if( rear == -1 ){ front ++; rear ++; }
		else if( rear == MAX-1 && front > 0 ) rear = 0;
		else rear ++;
		queue[rear] = val; 
		printf("\n%d is inserted!\n\n", val);
	}	
}

void deQueue(){
	int val;
	if( front == -1 && rear == -1 ) printf("\nQueue is empty!\n\n");
	else{
		val = queue[front];
		if( front == rear ) front = rear = -1;
		else front ++;
		if( front == MAX ) front = 0;
		printf("\n%d is deleted!\n\n", val);
	}	
}

void display(){
	int i;
	if( front == -1 ){
		printf("\nQueue is empty!\n\n");
	}
	else{
		printf("\nQueue: ");
		if( front > rear ){
			for( i = front; i < MAX; i ++ ){
				printf("%d ", queue[i]);
			}
			for( i = 0; i <= rear; i ++ ){
				printf("%d ", queue[i]);
			}
		}
		else{
			for( i = front; i <= rear; i ++ ){
				printf("%d ", queue[i]);
			}	
		}
		printf("\n\n");
	}
}

int main(){
	int ch;
	int val;
	while(1){	
		printf("--- MENU ---\n1. Insert\n2. Delete\n3. Display\n4. Exit\nEnter choice: ");
		scanf("%d", &ch);
		switch(ch){
			case 1: printf("Enter a no: "); 
					scanf("%d", &val);
					enQueue(val);
					break;
			case 2: deQueue();
					break;
			case 3: display();
					break;
			case 4: return 0;
					break;
			default: printf("\nInvalid choice!\n\n");
		}
	}	
}
