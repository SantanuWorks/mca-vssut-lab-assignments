#include <stdio.h>

struct Bin{
	int arr[100], sindex, lindex;
} B[10];

int main(){
	int i, j, a[100], n, max = 0, dc = 0, bindex, by = 1, aindex;
	
	printf("Enter no of elements: ");
	scanf("%d", &n);
	
	printf("Enter elments: ");
	for( i = 0; i < n; i++ ) scanf("%d", &a[i]);
	
	// bring max no
	for( i = 0; i < n; i ++ ) if( max < a[i] ) max = a[i];
	
	// store no digits
	while( max > 0 ){
		max /= 10;
		dc ++;
	} 
	
	printf("Original Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
	
	// iterate dc times
	for( i = 0; i < dc; i ++ ){
		
		for( j = 0; j < n; j ++ ){
			
			// get the bin index to store sorted element
			bindex = ( a[j] / by ) % 10;
			
			// store the element in thier respective digit class 
			B[bindex].arr[B[bindex].lindex] = a[j];		
			B[bindex].lindex ++;
			
		}
		
		// store party sorted elements back to array
		for( j = 0; j < 10; j ++ ){
			
			// visit each class digit and extract elements and store to array
			while( B[j].sindex != B[j].lindex ){
				
				// store elements from start index to last index
				a[aindex] = B[j].arr[B[j].sindex];
				B[j].sindex ++;
				aindex ++;
				
			}
			
			// set digit class empty
			B[j].sindex = 0;
			B[j].lindex = 0;
			
		}
		
		// increase positional value
		by *= 10;
		
		// set index for array 
		aindex = 0;
		
	}
	
	printf("\nSorted Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
	
}
