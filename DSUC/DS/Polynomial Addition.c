#include <stdio.h>
#include <stdlib.h>

struct term{
	int cof;
	int exp;
	struct term* next;
};

typedef struct term* TERM;

TERM p1 = NULL, p2 = NULL;

TERM createTerm( int cof, int exp ){
	TERM newterm = ( TERM ) malloc( sizeof(struct term) );
	newterm -> next = NULL;
	newterm -> cof = cof;
	newterm -> exp = exp;
	return newterm;
}

void insertTerm(int cof, int exp){
	TERM newnode = createTerm(cof, exp);
	if( p == NULL ) p = newnode;
	else{
		while( p -> next != NULL ) p = p -> next;
		p -> next = newnode; 
	}
}

void displayPoly(TERM p){
	printf("First Polynomial: ");
	while( p != NULL ){
		printf("%dx^%d", p->cof, p->exp);
		if( p->next != NULL ) printf(" + ");
		p = p -> next;
	}
}

void addPoly(){
	TERM p3 = NULL;
}

void createPoly(){
	int i, n, cof, exp ;
	printf("Enter no of terms: ");
	scanf("%d", &n);
	printf("Enter coefficients, exponents for Polynomial 1:\n");
	for( i = 0; i < n; i ++ ){
		printf("Enter coff for term %d: ", i+1);
		scanf("%d", &cof);	
		printf("Enter exp for term %d: ", i+1);
		scanf("%d", &exp);
		insertTerm(p1, cof, exp);
	}
	displayPoly(p1);
}

int main(){
	createPoly();	
	return 0;
}
