#include <bits/stdc++.h>
using namespace std;
struct node
{
    int data;
    struct node *left;
    struct node *right;
    node(int val)
    {
        data = val;
        left = right = NULL;
    }
    node()
    {
        data = 0;
        left = right = NULL;
    }
    node(int val, struct node *left, struct node *right)
    {
        data = val;
        left = left;
        right = right;
    }
};
int dfsHeight(node* root);

bool balanced_tree(node *root)
{
    return (dfsHeight(root)) != -1;
}
// For a balanced binary tree the height difference between left tree and right tree should be <=1.
int dfsHeight(node *root)// TC - O(N), SC - O(N)
{
    if (root == NULL)
        return 0;
    int lh = dfsHeight(root->left);
    if (lh == -1)
        return -1;
    int rh = dfsHeight(root->right);
    if (rh == -1)
        return -1;
    if (abs(lh - rh) > 1)
        return -1;
    return 1 + max(lh, rh);
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    if (balanced_tree(root))
    {
        cout << "Balanced binary tree" << endl;
    }
    else
    {
        cout << "Not a balanced binary tree" << endl;
    }
    return 0;
}