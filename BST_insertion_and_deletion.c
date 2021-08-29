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

void insert(struct Node *root, int key)
{
    struct Node *prev = NULL;
    while (root != NULL)
    {
        prev = root;
        if (root->data == key)
        {
            printf("Element %d cannot be inserted", key);
            return;
        }
        else if (root->data < key)
        {
            root = root->right;
        }
        else
        {
            root = root->left;
        }
    }
    struct Node *new = createNode(key);
    if (key < prev->data)
    {
        prev->left = new;
    }
    else
    {
        prev->right = new;
    }
}

struct Node *inOrderPredecessor(struct Node *root)
{
    root = root->left;
    while (root->right != NULL)
    {
        root = root->right;
    }
    return root;
}

struct Node *delete_node(struct Node *root, int value)
{
    struct Node *iPre;
    if (root == NULL)
    {
        return NULL;
    }
    if ((root->data == value) && (root->left == NULL) && (root->right == NULL))
    {
        free(root);
        return NULL;
    }
    if (value < root->data)
    {
        root->left = delete_node(root->left, value);
    }

    else if (value > root->data)
    {
        root->right = delete_node(root->right, value);
    }

    else
    {
        iPre = inOrderPredecessor(root);
        root->data = iPre->data;
        root->left = delete_node(root->left, iPre->data);
    }
    return root;
}

int main()
{
    int val;
    struct Node *p = createNode(5);
    struct Node *p1 = createNode(3);
    struct Node *p2 = createNode(6);
    struct Node *p3 = createNode(1);
    struct Node *p4 = createNode(4);

    p->left = p1;
    p->right = p2;

    p1->left = p3;
    p1->right = p4;

    insert(p, 8);
    // printf("%d\n",p->right->right->data);

    printf("The inorder traversal of a Binary tree are as follows:\n");
    inOrder(p);

    delete_node(p, 5);

    printf("\nThe inorder traversal of a Binary tree are as follows:\n");
    inOrder(p);
    return 0;
}