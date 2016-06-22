#include <stdio.h>
#include <stdlib.h>
#include <time.h>

/* Preorder traversal - root node printed first, then left subtree, then right */
/* Post order - root node is visited last*/

struct treeNode {
	struct treeNode* leftPtr; /* pointer to left subtree */
	int data; /* node value */
	struct treeNode* rightPtr; /* pointer to right subtree */
};

typedef struct treeNode* TreeNodePtr;

/* function prototypes */
void insertNode(TreeNodePtr* treePtr, int data);
void inOrder(TreeNodePtr treePtr);
void preOrder(TreeNodePtr treePtr);
void postOrder(TreeNodePtr treePtr);

int main(void) {

	int data;
	int i;

	TreeNodePtr rootPtr = NULL; /* tree initially empty */
	srand( time( NULL ) );
	printf( "The numbers being placed in the tree are:\n" );
	
	/* insert 10 random numbers into tree */
	for (i = 1; i <= 10; i++) {
		data = rand() % 15;	
		printf("%3d", data);
		insertNode(&rootPtr, data);
	}

	/* traverse the tree preOrder */
	printf( "\n\nThe preOrder traversal is:\n" );
	preOrder(rootPtr);

	/* traverse the tree inOrder */
	printf( "\n\nThe inOrder traversal is:\n" );
	inOrder(rootPtr);

	/* traverse the tree postOrder */
	printf( "\n\nThe postOrder traversal is:\n" );
	postOrder(rootPtr);

	return 0;
}

/* insert node into tree */
void insertNode(TreeNodePtr* treePtr, int data) {
	if (*treePtr == NULL) {
		*treePtr = (TreeNodePtr) malloc(sizeof(struct treeNode));
		if (*treePtr != NULL) {
			(*treePtr)->data = data;
			(*treePtr)->leftPtr = NULL;
			(*treePtr)->rightPtr = NULL;
		} else {
			printf("%d could not be inserted. No memory availbale", data);
		}
	} else {
		/* the data to insert is less than the current node */
		if (data < (*treePtr)->data) {
			insertNode(&((*treePtr)->leftPtr), data);	
		}
		/* the data to insert is greater than the current node */
		else if (data > (*treePtr)->data) {
			insertNode(&((*treePtr)->rightPtr), data);	
		}
		/* duplicate */
		else { printf("dup"); }
	}
}

/* Inorder traversal - the items are printed out in ascending order */
void inOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		inOrder(treePtr->leftPtr);
		printf("%3d", treePtr->data);	
		inOrder(treePtr->rightPtr);
	}
}

/* 
 * The value in each node is processed as the node is visited. 
 * The values in its left subtree are processed, then the values 
 * in the right subtree. */
void preOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		printf("%3d", treePtr->data);	
		preOrder(treePtr->leftPtr);
		preOrder(treePtr->rightPtr);
	}
}

/* The value in each node is not printed until the values of its children are printed */
void postOrder(TreeNodePtr treePtr) {
	if (treePtr != NULL) {
		postOrder(treePtr->leftPtr);
		postOrder(treePtr->rightPtr);
		printf("%3d", treePtr->data);	
	}
}

