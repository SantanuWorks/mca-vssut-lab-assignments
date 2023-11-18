#include <stdio.h>

int main(){
	int i, j, a[100], n, t, mini;
	
	printf("Enter no of elements: ");
	scanf("%d", &n);
	
	printf("Enter elments: ");
	for( i = 0; i < n; i++ ) scanf("%d", &a[i]);
	
	printf("Original Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
	
	for( i = 0; i < n-1; i ++ ){
		
		mini = i;
		
		for( j = i + 1; j < n; j ++ ) if( a[j] < a[mini] ) mini = j;
		
		t = a[mini];
		a[mini] = a[i];
		a[i] = t;
		
	}
	
	printf("\nSorted Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
}
