#include <stdio.h>

void swap(int* a, int* b ){
	int t = *a; *a = *b; *b = t;
}

void BubbleSort(int a[], int n){
	int i, j;
	for( i=0; i<n-1; i++ ){
		for( j=0; j<n-1-i; j++ ){
			if( a[j] > a[j+1] ) swap(&a[j], &a[j+1]);	
		}
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
	
	BubbleSort(a, n);
	
	printf("\nSorted Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
}
