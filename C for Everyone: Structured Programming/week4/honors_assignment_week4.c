/*
Open and read a file of integer pairs into an array that is created with the first integer telling you how many to read.  

So  4 9  11  4  5    would mean create an integer array size 4 and read into data[].  

Write a routine that places these values into a binary tree structure. Then walk the tree “inorder” and print these values to the screen.
*/

#include <stdio.h>
#include <stdlib.h>

// creating a node
typedef struct node {
	int val;
	struct node *left;
	struct node *right;
	} node;

	typedef node *tree; //tree is pointer to node
	tree create_tree(int val){
	tree t = malloc(sizeof(node));
	t -> val = val;
	t -> left = t -> right = NULL;
	return t;
}

// insert node function
void insert_node(tree root, int val){
	if (val < root -> val) {
		if (root -> left == NULL) {
			root -> left = create_tree(val);
	} else {
		insert_node(root -> left, val);
	}
	} else {
	if (root -> right == NULL) {
		root -> right = create_tree(val);
	} else {
		insert_node(root -> right, val);
	}
	}
}

// creating tree from array
tree tree_from_array(int arr[], int n){
	if (n < 1) return NULL;
	tree root = create_tree(arr[0]);
	for (int i = 1; i < n; i ++) {
	insert_node(root, arr[i]);
	}
	return root;
}

// print the inorder form
void print_inorder(tree t){
	if (t == NULL) {
	return;
	}
	print_inorder(t -> left);
	printf("%d, ", t -> val);
	print_inorder(t -> right);
	}

// main function, takes the input file name as command line argument
int main(int argc, char *argv[]){
	FILE *ifp;
	ifp = fopen(argv[1], "r");
	if (ifp == NULL){
	printf("File is not found.\n");
	exit(1);
	}
	int count;
	//read values count
	fscanf(ifp, "%d", &count);
	int data[count];
	// read values
	for (int i = 0; i < count; i ++) {
	fscanf(ifp, "%d", &data[i]);
	}
	tree t = tree_from_array(data, count);
	printf("Print tree inorder: \n");
	print_inorder(t);
	fclose(ifp);
	return 0;
}
