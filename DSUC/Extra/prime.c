// Write a program in C to check whether a number is prime or not.
#include <stdio.h>
int main(){
	int n, i;
	printf("Enter a no: ");
	scanf("%d", &n);
	for( i = 2; i < n-1; i ++ ){
		if( n%i==0 ){
			printf("%d is not prime", n);
			return 0;
		}
	}
	printf("%d is prime", n);
}
