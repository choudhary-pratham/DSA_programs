#include <bits/stdc++.h>
using namespace std;
// TC - O(N)
// SC - O(H)
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

bool check_symmetric(node *p, node *q)
{
    if (p == NULL || q == NULL)
    {
        return (p == q);
    }
    return (p->data == q->data) && (check_symmetric(p->left, q->right)) && (check_symmetric(p->right, q->left));
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(2);
    root->left->left = new node(3);
    root->right->right = new node(3);
    root->left->right = new node(4);
    root->right->left = new node(4);
    if (check_symmetric(root->left, root->right))
    {
        cout << "Symmetric" << endl;
    }

    else
    {
        cout << "Not symmetric" << endl;
    }
    return 0;
}