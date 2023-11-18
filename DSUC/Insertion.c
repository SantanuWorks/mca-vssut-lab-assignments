#include <stdio.h>

void InsertionSort(int a[], int n){
	int i, j;
	for( i=1; i<n; i++ ){
		j = i-1;
		while( j >= 0 && a[i] < a[j] ){
			a[j+1] = a[j];
			j --;	
		}
		a[j+1] = a[i];
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
	
	InsertionSort(a, n);
	
	printf("\nSorted Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
}
