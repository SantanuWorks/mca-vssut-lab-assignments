#include <stdlib.h>
#include <stdio.h>
#define MAX 10
struct node{
	int data;
	struct node* next;
};
struct Graph{
	int vc;
	struct node** adjlist;
};
int visited[MAX];
struct node* createNode(char data){
	struct node* newnode = malloc(sizeof(struct node));
	newnode -> data = data;
	newnode -> next = NULL;
	return newnode;
}
struct Graph* createGraph(int vc){
	int i;
	struct Graph* newgraph = malloc(sizeof(struct Graph));
	newgraph -> vc = vc;
	newgraph -> adjlist = malloc(vc * sizeof(struct node*));
	for( i = 0; i < vc; i ++ ) newgraph -> adjlist[i] = NULL;
	return newgraph;
}
void addEdge(struct Graph* graph, char s, char d){
	struct node* newnode = createNode(d);
	newnode -> next = graph->adjlist[s];
	graph -> adjlist[s] = newnode;
	newnode = createNode(s);
	newnode -> next = graph -> adjlist[d];
	graph -> adjlist[d] = newnode;
}
void printGraph(struct Graph* graph){	
	int v;
	printf("Given Graph:\n\n");
	for ( v = 0; v < graph -> vc; v ++) {
		struct node* temp = graph -> adjlist[v];
		printf("%d: ", v);
		while (temp){
			printf("%d -> ", temp -> data);
			temp = temp->next;
		}
		printf("X\n");
	}	
}
void dfs_algorithm(struct Graph* graph, int s){
	struct node* nodeadjlist = graph -> adjlist[s];
	struct node* temp = nodeadjlist;
	visited[s] = 1;
	printf("%d ", s);
	while( temp != NULL ){
		int adjnode = temp -> data;
		if( visited[adjnode] == 0 ) dfs_algorithm(graph, adjnode);
		temp = temp -> next;
	}
}
int main(){
	struct Graph* graph = createGraph(7);
	int s = 0;
	addEdge(graph, 0, 1);
	addEdge(graph, 0, 3);
	addEdge(graph, 0, 5);
	addEdge(graph, 1, 2);
	addEdge(graph, 1, 4);
	addEdge(graph, 2, 4);
	addEdge(graph, 3, 4);
	addEdge(graph, 3, 5);
	addEdge(graph, 3, 6);
	addEdge(graph, 4, 6);
	addEdge(graph, 5, 6);
	printGraph(graph);
	printf("\nSource: %d\n", s);
	printf("\nDFS Path: ");
	dfs_algorithm(graph, s);
}
