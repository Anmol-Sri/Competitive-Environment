#include <stdio.h>
#include<stdlib.h>
struct Tnode{
	char data;
	struct Tnode *left;
	struct Tnode *right;
};
struct Tnode *newNode(char data);
struct Tnode *arrayToTree(char arr[], int start, int end){
	if(start > end){
		return NULL;
	}
	int mid = (start + end) / 2;
	struct Tnode *root = newNode(arr[mid]);
	root->left = arrayToTree(arr, start, mid - 1);
	root->right = arrayToTree(arr, mid + 1, end);
	return root;
}
struct Tnode *newNode(char data){
	struct Tnode *node = (struct Tnode *)malloc(sizeof(struct Tnode));
	node -> data = data;
	node -> left = NULL;
	node -> right = NULL;
	return node;
}
void preOrder(struct Tnode *node){
	if(node == NULL) return ;
	printf("%c", node->data);
	preOrder(node->left);
	preOrder(node->right);
}
void reverseArray(char *arr, int start, int end){
	while(start < end){
		char x = arr[start];
		arr[start++] = arr[end];
		arr[end--] = x;
	}
}
void updateArray(char *arr, int n){
	int size;
	for(size = 0; arr[size] != '\0'; size++);
	reverseArray(arr, 0, size-1);
	reverseArray(arr, 0, n-1);
	reverseArray(arr, n, size-1);
}
int main(){
	char *arr;
	printf("Enter your full name in the format <FirstName>*<LastName>: \n");
	scanf("%[^/n]s", arr);
	printf("Name : %s\n", arr);
	int n;
	for(n = 0; arr[n]!= '\0'; ++n){
		struct Tnode *root = arrayToTree(arr, 0, n - 1);
		preOrder(root);
		printf("\n");
		updateArray(arr, 2);
		root - arrayToTree(arr, 0, n - 1);
		preOrder(root);
		printf("\n");
		updateArray(arr, 1);
		root = arrayToTree(arr, 0, n - 1);
		preOrder(root);
		printf("\n");
		updateArray(arr, 3);
		root = arrayToTree(arr, 0, n - 1);
		preOrder(root);
		printf("\n");
	}
	return 0;
}