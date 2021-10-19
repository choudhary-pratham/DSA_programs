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

vector<int> right_ans;
void right_view(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (right_ans.size() == level)
    {
        right_ans.push_back(root->data);
    }
    right_view(root->right, level + 1);
    right_view(root->left, level + 1);
}

vector<int> left_ans;
void left_view(node *root, int level)
{
    if (root == NULL)
    {
        return;
    }
    if (left_ans.size() == level)
    {
        left_ans.push_back(root->data);
    }
    left_view(root->left, level + 1);
    left_view(root->right, level + 1);
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(7);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    right_view(root, 0);
    for (auto it : right_ans)
    {
        cout << it << " ";
    }
    cout << endl;
    left_view(root, 0);

    for (auto it : left_ans)
    {
        cout << it << " ";
    }
    return 0;
}