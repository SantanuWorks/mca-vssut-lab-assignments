#include <stdio.h>
#include <stdlib.h>

struct Node{
	char val;
	struct vertex* next;
};

struct Graph{
	int countV;
	struct Node** List;	
};

struct Node* createNode(char val){
	struct Node* newnode = ( struct Node* )	malloc( sizeof(struct Node) );
	newnode -> val = val;
	newnode -> next = NULL;
	return newnode;
}

struct Graph* creategraph(int n){
	int i;
	struct Graph* G = (struct Graph*) malloc(sizeof(struct Graph));
	G -> countV = n;
	G -> List = (struct Node**) malloc(n * sizeof(struct Node*));
	for(i = 0; i < n; i ++) G -> List[i] = NULL;
	return G;
}

void addEdge( struct Graph* G, char u, char v){
	
	struct Node* newnode = createnode(u);
	
	
}

void printAdjMatrix(struct Graph* G){
	int i, j;
	
	
}

int main(){
	int countV = 5;
	struct Graph* G = creategraph(countV);
	addEdge(G, 0, 1);
	addEdge(G, 1, 2);
	addEdge(G, 2, 3);
	addEdge(G, 3, 4);
	addEdge(G, 4, 0);
	printAdjMatrix(G);
}
