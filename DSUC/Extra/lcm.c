// Write a program in C to LCM of two number.
#include <stdio.h>
int main(){
	int a, b, i;
	int lcm, gcd;
	printf("Enter a, b: ");
	scanf("%d %d", &a, &b);
	int n = (a<b)?a:b;
	for( i = 1; i <= n; i ++ ){
		if( a%i==0 && b%i==0 ) gcd = i;
	}
	lcm = (a*b)/gcd;
	printf("LCM is %d", lcm);
}
