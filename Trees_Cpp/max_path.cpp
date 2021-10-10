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
int max_path_down(node *root, int &maxi);
int max_path_sum(node *root) // using recursion, TC - O(height of the tree), SC - O(N)
{
    int maxi = INT_MIN;
    max_path_down(root, maxi);
    return maxi;
}

int max_path_down(node *root, int &maxi)
{
    if (root == NULL)
        return 0;
    int lh = max(0, max_path_down(root->left, maxi));
    int rh = max(0, max_path_down(root->right, maxi));
    maxi = max(maxi, lh + rh + root->data);
    return root->data + max(lh, rh);
}

int main()
{
    struct node *root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    // root->left->right->left = new node(6);

    // int result = depth_max_rec(root);
    int result = max_path_sum(root);
    cout << result << endl;
    return 0;
}