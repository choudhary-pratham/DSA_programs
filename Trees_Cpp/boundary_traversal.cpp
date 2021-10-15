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
bool isLeaf(struct node *root)
{
    if (root->left == NULL && root->right == NULL)
    {
        return true;
    }
    else
    {
        return false;
    }
}
void left_boundary(node *root, vector<int> &ans)
{
    node *cur = root->left;
    while (cur)
    {
        if (!isLeaf(cur))
            ans.push_back(cur->data);
        if (cur->left)
        {
            cur = cur->left;
        }
        else
            cur = cur->right;
    }
}
void leaf_node(node *root, vector<int> &ans)
{
    if (isLeaf(root))
    {
        ans.push_back(root->data);
        return;
    }
    if (root->left)
        leaf_node(root->left, ans);
    if (root->right)
        leaf_node(root->right, ans);
}
void right_boundary(node *root, vector<int> &ans)
{
    node *cur = root->right;
    vector<int> temp;
    while (cur)
    {
        if (!isLeaf(cur))
            temp.push_back(cur->data);
        if (cur->right)
            cur = cur->right;
        else
            cur = cur->left;
    }
    for (int i = temp.size() - 1; i >= 0; i--)
    {
        ans.push_back(temp[i]);
    }
}
vector<int> boundary_traversal(node *root)
{
    vector<int> ans;
    if (root == NULL)
        return ans;
    if (!isLeaf(root))
        ans.push_back(root->data);
    left_boundary(root, ans);
    leaf_node(root, ans);
    right_boundary(root, ans);
    return ans;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(7);
    root->left->left = new node(3);
    root->left->left->right = new node(4);
    root->left->left->right->left = new node(5);
    root->left->left->right->right = new node(6);
    root->right->right = new node(8);
    root->right->right->left = new node(9);
    root->right->right->left->left = new node(10);
    root->right->right->left->right = new node(11);


    vector<int> ans = boundary_traversal(root);
    for (auto it : ans)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}