#include <stdio.h>
#define MAX 6	

void heapify( int heap[], int n, int i ){
	int rooti = i, lefti = i*2+1, righti = i*2+2;
	int t;
	
	if( lefti < n && heap[lefti] > heap[rooti] )
		rooti = lefti;
	if( righti < n && heap[righti] > heap[rooti] )
		rooti = righti;
	if( rooti != i ){
		t = heap[i];
		heap[i] = heap[rooti];
		heap[rooti] = t;
		heapify(heap, MAX, rooti);	
	}
}

void heapSort( int heap[] ){
	int i, t;
	
	for( i = MAX/2 - 1; i >= 0; i -- ){
		heapify( heap, MAX, i );	
	}
	
	for( i = MAX - 1; i >= 0; i -- ){
		t = heap[0];
		heap[0] = heap[i];
		heap[i] = t;
		heapify( heap, i, 0 );
	}
}

int main(){
	int heap[MAX] = { 1, 12, 9, 5, 6, 10 };
	int i;
	
	printf("Original Array: ");
	for( i = 0; i < MAX; i ++ ) printf("%d ", heap[i]);
	
	heapSort(heap);
		
	printf("Sorted Array: ");
	for( i = 0; i < MAX; i ++ ) printf("%d ", heap[i]);
}
