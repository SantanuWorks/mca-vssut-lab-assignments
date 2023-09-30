// Write a program in C to check whether a number is positive, negative or zero.
#include <stdio.h>
int main(){
	int n;
	printf("Enter a no: ");
	scanf("%d", &n);
	if( n>0 ) printf("%d is positive", n);
	else if( n<0 ) printf("%d is negative", n);
	else printf("%d is zero", n);
}
