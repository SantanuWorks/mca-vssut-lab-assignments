#include <stdio.h>
#define COUNTV 5

void addEdge(int G[][COUNTV], int u, int v){
	G[u][v] = 1;
	G[v][u] = 1;
}

void printAdjMatrix(int G[][COUNTV]){
	int i, j, n = COUNTV;
	printf("Adjacency Matrix: ");
	for( i = 0; i < n; i ++ ){
		for( j = 0; j < n; j ++ ){
			printf("%d ", G[i][j]);	
		}	
		printf("\n");	
	}
}

int main(){
	int G[50][50];
	addEdge(G, 0, 1);
	addEdge(G, 1, 2);
	addEdge(G, 2, 3);
	addEdge(G, 3, 4);
	addEdge(G, 4, 0);
	printAdjMatrix(G);
}
