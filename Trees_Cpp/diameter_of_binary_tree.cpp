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
int dfsHeight(node *root, int &diameter);

int diameter_of_binary_tree(node *root)
{
    int diameter = 0;
    dfsHeight(root, diameter);
    return diameter;
}
// diameter of the tree is the maximum distance between any two nodes of the tree
int dfsHeight(node *root, int &diameter) // TC - O(N), SC - O(N)
{
    if (root == NULL)
        return 0;
    int lh = dfsHeight(root->left, diameter);
    int rh = dfsHeight(root->right, diameter);
    diameter = max(diameter, lh + rh);
    return 1 + max(lh, rh);
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    // root->left->right->left = new node(6);
    cout << diameter_of_binary_tree(root) << endl;
    return 0;
}