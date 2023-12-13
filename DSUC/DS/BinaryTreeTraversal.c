#include <stdio.h>
#include <stdlib.h>
struct Node{
	int data;
	struct Node* left;
	struct Node* right;
};
struct Node* createNode(int data){
	struct Node* newnode = (struct Node*) malloc(sizeof(struct Node));
	newnode->data = data;
	newnode->left = NULL;
	newnode->right = NULL;
	return newnode;
}
void insertLeft(struct Node* currnode, int data){
	struct Node* newnode = createNode(data);
	currnode->left = newnode;	
}
void insertRight(struct Node* currnode, int data){
	struct Node* newnode = createNode(data);
	currnode->right = newnode;
}
void inorder(struct Node* root){
	if( root != NULL ){
		inorder(root->left);
		printf("%d ", root->data);
		inorder(root->right);
	}
}
void preorder(struct Node* root){
	if( root != NULL ){
		printf("%d ", root->data);
		preorder(root->left);
		preorder(root->right);
	}
}
void postorder(struct Node* root){
	if( root != NULL ){
		postorder(root->left);
		postorder(root->right);
		printf("%d ", root->data);
	}
}
void main(){
	struct Node* root = createNode(10);
	printf("\tGiven Binary Tree:\n\n");
	printf("\t\t10\n\t       /  \\\n");
	printf("\t      20  30\n\t     /  \\   \\\n");
	printf("\t    40  50  60\n");
	insertLeft(root, 20);
	insertRight(root, 30);
	insertLeft(root->left, 40);
	insertRight(root->left, 50);
	insertRight(root->right, 60);
	printf("\nInorder Traversal: ");
	inorder(root);
	printf("\nPreorder Traversal: ");
	preorder(root);
	printf("\nPostorder Traversal: ");
	postorder(root);
}

