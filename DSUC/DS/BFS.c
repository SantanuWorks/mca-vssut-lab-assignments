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
int queue[MAX];
int visited[MAX];
int prev[MAX];
int front = -1;
int rear = -1;
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
void enQueue( int val ){
	if( rear != MAX-1 ){
		if( front == -1 ) front = 0;
		rear ++;
		queue[rear] = val;
	}	
}
int deQueue(){
	int val = -1;
	if(!(front == -1 || front > rear)){
		val = queue[front];
		front ++;
		if( front > rear ) front = rear = -1;
	}	
	return val;
}
void bfs_algorithm(struct Graph* graph, int s, int d){
	int path[MAX], i, in = 0;
	for( in = 0; in < MAX; in ++ ) prev[in] = -1;
	visited[s] = 1;
	enQueue(s);
	while( !(front == -1 || front > rear) ){
		int currv = deQueue();
		struct node* nodeadjlist = graph -> adjlist[currv];
		while( nodeadjlist != NULL ){
			int adjnode = nodeadjlist -> data;
			if( visited[adjnode] == 0 ){
				visited[adjnode] = 1;
				prev[adjnode] = currv;
				enQueue(adjnode);
			}
			nodeadjlist = nodeadjlist -> next;
		}
	}
	in = 0;
	for( i = d; i != -1; i = prev[i] ) path[in ++] = i;
	if( path[in - 1] == s ) for( i = in-1; i >= 0; i -- ) printf("%d ", path[i]);
	else printf("No path found!");
}
int main(){
	struct Graph* graph = createGraph(7);
	int s = 0, d = 2;
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
	printf("\nSource: %d, Destination: %d\n", s, d);
	printf("\nShortest Path: ");
	bfs_algorithm(graph, s, d);
}
