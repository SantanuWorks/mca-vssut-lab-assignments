#include <stdio.h>
void swap(int *a, int *b){
	int t = *a;
	*a = *b;
	*b = t;
}
int main(){
	int a, b;
	printf("Enter a and b: ");
	scanf("%d %d", &a, &b);
	printf("Before Swap: a = %d, b = %d", a, b);
	swap(&a, &b);
	printf("\nBefore Swap: a = %d, b = %d", a, b);
}
