#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node()
    {
        data = 0;
        left = right = NULL;
    }
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
    node(int val, node *left, node *right)
    {
        data = val;
        this->left = left;
        this->right = right;
    }
};
bool is_identical(node *p, node *q)
{
    if (p == NULL || q == NULL)
    {
        return (p == q);
    }
    return (p->data == q->data) && (is_identical(p->left, q->left)) && (is_identical(p->right, q->right));
}

int main()
{
    struct node *p = new node(-10);
    p->left = new node(9);
    p->right = new node(20);
    p->right->left = new node(15);
    p->right->right = new node(7);
    
    struct node *q = new node(-10);
    q->left = new node(9);
    q->right = new node(20);
    q->right->left = new node(15);
    q->right->right = new node(7);

    cout << is_identical(p, q);
    return 0;
}