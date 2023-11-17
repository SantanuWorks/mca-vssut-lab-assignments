#include <stdio.h>

int main(){
	int i, n, key, a[100];
	
	printf("Enter no of elements: ");
	scanf("%d", &n);
	
	printf("Enter elements of array: ");
	for(i = 0; i < n; i ++) scanf("%d", &a[i]);
	
	printf("Enter key to search: ");
	scanf("%d", &key);
	
	for(i = 0; i < n; i ++) if(a[i] == key) break;
	
	if( i==n ) printf("%d not found!", key);
	else printf("%d found at %d", key, i);
}
