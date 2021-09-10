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

void preOrder(struct Node *n) // Root->left->right
{
    if(n!=NULL)
    {
        printf("%d ",n->data);
        preOrder(n->left);
        preOrder(n->right);
    }
}

void postOrder(struct Node *n)// left->right->root
{
    if(n!=NULL)
    {
        postOrder(n->left);
        postOrder(n->right);
        printf("%d ",n->data);
    }
}

void inOrder(struct Node *n)// left->root->right
{
    if(n!=NULL)
    {
        inOrder(n->left);
        printf("%d ",n->data);
        inOrder(n->right);
    }
}
int main()
{
    struct Node *p = createNode(4);
    struct Node *p1 = createNode(1);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(5);
    struct Node *p4 = createNode(2);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    printf("\npostorder traversal : \n");
    postOrder(p);
    
    printf("\npreorder traversal : \n");
    preOrder(p);
    
    printf("\ninorder traversal : \n");
    inOrder(p);
    
    return 0;
}