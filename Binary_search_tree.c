#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *left;
    struct Node *right;
};

struct Node *createNode(int data)
{
    struct Node *n = (struct Node *)malloc(sizeof(struct Node));
    n->data = data;
    n->left = NULL;
    n->right = NULL;
    return n;
}

void inOrder(struct Node *n)
{
    if (n != NULL)
    {
        inOrder(n->left);
        printf("%d ", n->data);
        inOrder(n->right);
    }
}
// For a BT to be a BST the left node value must be less than the root value and the right node value must be
//greater than the root node value.

int isBST(struct Node *root) // For a BT to be a BST the inorder traversal must be in ascending order
{
    if (root == NULL)
    {
        return 1;
    }
    if (root->left != NULL && root->left->data > root->data)
    {
        return 0;
    }
    if (root->right != NULL && root->right->data <= root->data)
    {
        return 0;
    }
    if (!isBST(root->left) || !isBST(root->right))
    {
        return 0;
    }
    return 1;
}

int main()
{
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    printf("The inorder traversal of a Binary tree are as follows:\n");
    inOrder(p);
    printf("\n");

    if (isBST(p))
    {
        printf("It is a binary search tree\n");
    }
    else
    {
        printf("It is not a binary search tree");
    }
    return 0;
}