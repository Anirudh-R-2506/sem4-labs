#include <stdio.h>
#include <stdlib.h>

typedef struct node {
	struct node * right;
	struct node * left;
	int val;
} Node;

Node * createNode(int x) {
	Node * new = (Node *) malloc(sizeof(Node));
	new->val = x;
	new->right = NULL;
	new->left = NULL;
	return new;
}

void insertBST(Node **root,int x) {
    if (*(root) == NULL){
        *(root) = createNode(x);
    }
    else{
        Node *temp = *(root);
        if (x > temp->val){
            insertBST(&(temp->right), x);
        }
        else if(x < temp->val){
            insertBST(&(temp->left), x);
        }
    }
}

int search(Node *root, int x){
    if (x == root->val) return 1;
    if (x < root->val) search(root->left, x);
    if (x > root->val) search(root->right, x);
    return 0;
}

void preOrder(Node * root) {
	printf("%d ",root->val);
	preOrder(root->left);
	preOrder(root->right);
}

void inOrder(Node * root) {
	inOrder(root->left);
	printf("%d ",root->val);
	inOrder(root->right);
}

void postOrder(Node * root) {
	postOrder(root->left);
	postOrder(root->right);
	printf("%d ",root->val);	
}

void main() {
	printf("Enter elements. Type -1 to exit.\n");
	int x;
	Node * root = NULL;
	while(1) {
		printf("Enter element ");
		scanf("%d",&x);
		if (x < 0)
			break;
		insertBST(&root,x);
	}
	printf("\nPreOrder: ");
	preOrder(root);
	printf("\nInOrder: ");
	inOrder(root);
	printf("\nPostOrder: ");
	postOrder(root);
    printf("Enter key ");
    scanf("%d", &x);
    if (search(root, x)) printf("Key found");
    else insertBST(&root, x);
}
