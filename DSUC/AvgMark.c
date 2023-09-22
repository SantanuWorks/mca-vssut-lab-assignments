#include <stdio.h>
int main(){
	int n, i, sum = 0, m;
	float avg;
	printf("Enter no of marks: ");
	scanf("%d", &n);
	printf("Enter marks:\n");
	for( i = 0; i < n; i ++ ){
		printf("Enter mark %d: ",i+1);
		scanf("%d", &m);
		sum += m;
	}
	avg = (float)sum/n;
	printf("Average marks for the given marks is %.2f", avg);
}
