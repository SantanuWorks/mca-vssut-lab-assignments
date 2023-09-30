// Write a program in C to swap two numbers.
#include <stdio.h>
int main(){
	int a, b, t;
	printf("Enter a and b: ");
	scanf("%d %d", &a, &b);
	printf("Before Swap: a = %d, b = %d", a, b);
	t = a;
	a = b;
	b = t;
	printf("\nAfter Swap: a = %d, b = %d", a, b);
}
