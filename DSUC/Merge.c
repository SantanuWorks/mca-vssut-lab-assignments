#include <stdio.h>

int MergeArr(int a[], int l, int mid, int h){
	int i, j, k = 0, s1, s2;
	s1 = mid - l + 1;
	s2 = h - mid;
	int A1[s1], A2[s2];
	
	for( i = 0; i < s1; i ++ ) A1[i] = a[l+i];
	for( i = 0; i < s2; i ++ ) A2[i] = a[mid+1+1];
	
	k = l, i = 0, j = 0;
	
	while( i < s1 && j < s2 ){
		if( A1[i] <= A2[j] ){
			a[k] = A1[i];
			i ++;
		}	
		else{
			a[k] = A2[j];
			j ++;
		}
		k ++;
	}
	
	while( i < s1 ){
		a[k] = A1[i];
		i ++;
		k ++;
	}
	
	while( j < s2 ){
		a[k] = A2[j];
		j ++;
		k ++;
	}
}

void MergeSort(int a[], int l, int h){
	if( l < h ){
		int mid = (l+h)/2;
		MergeSort(a, l, mid);
		MergeSort(a, mid+1, h);
		MergeArr(a, l, mid, h);
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
	
	MergeSort(a, 0, n-1);
	
	printf("\nSorted Array: ");
	for( i = 0; i < n; i ++ ) printf("%d ", a[i]);
}
