// Write a program in C to find the factorial of a number.
#include <stdio.h>
int main(){
	int n, i;
	long f = 1;
	printf("Enter a no: ");
	scanf("%d", &n);
	for( i = 2; i <= n; i ++ ){
		f *= i;
	}
	printf("Factorial of %d is %ld", n, f);
}
