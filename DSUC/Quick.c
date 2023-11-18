#include <stdio.h>

int partition(int a[], int l, int h){
	int i = l, j = h;
	int pivot = a[l];
	while( i < j ){
		do{ i ++; }while( a[i] <= pivot );
		do{ j --; }while( a[j] > pivot );
		if( i < j ){
			int t = a[i];
			a[j] = a[i];
			a[i] = t;
		}
	}
	int t = a[j];
	a[j] = a[l];
	a[l] = t;
	return j;	
}

void QuickSort(int a[], int l, int h){
	if( l < h ){
		int pi = partition(a, l, h);
		QuickSort(a, l, pi-1);
		QuickSort(a, pi+1, h);
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
	
	QuickSort(a, 0, n);
	
	printf("\nSorted Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
}
