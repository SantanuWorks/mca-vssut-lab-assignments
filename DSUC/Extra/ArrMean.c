#include <stdio.h>
int main(){
	int n, i, sum = 0;
	float mean;
	printf("Enter no of elements: ");
	scanf("%d", &n);
	int a[n];
	printf("Enter all the elements: ");
	for( i = 0; i < n; i ++ ){
		scanf("%d", &a[i]);
		sum += a[i];
	}
	mean = (float)sum/n;
	printf("Mean marks for the given marks is %.2f", mean);
}
