#include <stdio.h>

void SortArr(int a[], int n){
	int i, j, t, flg = 0;
	for(i = 0; i < n-1; i ++){
		for(j = 0; j < n-1-i; j ++){
			if(a[j+1] < a[j]){
				t = a[j+1];
				a[j+1] = a[j];
				a[j] = t;
				flg = 1;	
			}
		}
		if(!flg) break;
 	}
}

int BinarySearch(int a[], int k, int l, int h){
	int m = (l+h)/2;
	if(l > h) return -1;
	else if(k == a[m]) return m;
	else if(k > a[m]) return BinarySearch(a, k, m+1, h);
	else if(k < a[m]) return BinarySearch(a, k, l, m-1);
}

int main(){
	int i, n, key, a[100];
	
	printf("Enter no of elements: ");
	scanf("%d", &n);
	
	printf("Enter elements of array: ");
	for(i = 0; i < n; i ++) scanf("%d", &a[i]);
	
	printf("Enter key to search: ");
	scanf("%d", &key);
	
	SortArr(a, n);
	
	i = BinarySearch(a, key, 0, n-1);
	
	if( i==-1 ) printf("%d not found!", key);
	else printf("%d found at %d", key, i);
}
