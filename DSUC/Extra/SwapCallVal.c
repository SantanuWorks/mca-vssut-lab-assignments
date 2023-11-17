#include <stdio.h>
void swap(int a, int b){
	printf("Before Swap: a = %d, b = %d", a, b);
	int t = a;
	a = b;
	b = t;
	printf("\nBefore Swap: a = %d, b = %d", a, b);
}
int main(){
	int a, b;
	printf("Enter a and b: ");
	scanf("%d %d", &a, &b);
	swap(a, b);
}
