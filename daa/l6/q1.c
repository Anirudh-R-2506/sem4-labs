
#include <stdio.h>
#include <stdlib.h>

typedef struct Node
{
    int data;
    struct Node* left;
    struct Node* right;
}Node;

Node* generateNode(int data)
{
    Node* t = (Node*)malloc(sizeof(Node));
    t->data = data;
    t->left = t->right = NULL;
    return t;
}
int getNoOfNodes(Node* t)
{
    if(t == NULL)
        return 0;
    else
        return 1 + getNoOfNodes(t->left) + getNoOfNodes(t->right);
}
void main()
{
    Node* root = generateNode(3);
    root->right = generateNode(1);
    root->left = generateNode(2);
    root->right->left = generateNode(9);
    root->right->right = generateNode(12);
    root->left->right = generateNode(56);
    root->left->left = generateNode(2);
    printf("The Number of Nodes of the Binary Tree is : %d\n", getNoOfNodes(root));
}