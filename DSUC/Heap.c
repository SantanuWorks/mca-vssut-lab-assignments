#include <stdio.h>

void swap(int* a, int* b ){
	int t = *a; *a = *b; *b = t;
}

void heapify(int a[], int i, int n){
	int rooti = i;
	int lefti = i*2 + 1;
	int righti = i*2 + 2;
	
	if( lefti < n && a[lefti] > a[rooti] ) rooti = lefti;
	
	if( righti < n && a[righti] > a[rooti] ) rooti = righti;
	
	if( rooti != i ){
		swap(&a[rooti], &a[i]);
		heapify(a, rooti, n);
	}
}

void HeapSort(int a[], int n){
	int i;

	for( i = n/2-1; i >= 0; i -- ) heapify(a, i, n);
	
	for( i = n-1; i >= 0; i -- ){
		swap(&a[i], &a[0]);
		heapify(a, 0, i);		
	} 
}

int main(){
	int i, a[100], n;
	
	printf("Enter no of elements: ");
	scanf("%d", &n);
	
	printf("Enter elments: ");
	for( i = 0; i < n; i++ ) scanf("%d", &a[i]);
	
	printf("Original Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
	
	HeapSort(a, n);
	
	printf("\nSorted Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
}
