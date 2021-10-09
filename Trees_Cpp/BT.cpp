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

void rec_preorder(struct node *root) // TC - O(N) | SC - O(N)
{
    if (root == NULL)
    {
        return;
    }
    cout << root->data << " ";
    rec_preorder(root->left);
    rec_preorder(root->right);
}

void rec_inorder(struct node *root) // TC - O(N) | SC - O(N)
{
    if (root == NULL)
    {
        return;
    }
    rec_inorder(root->left);
    cout << root->data << " ";
    rec_inorder(root->right);
}

void rec_postorder(struct node *root) // TC - O(N) | SC - O(N)
{
    if (root == NULL)
    {
        return;
    }
    rec_postorder(root->left);
    rec_postorder(root->right);
    cout << root->data << " ";
}

vector<vector<int>> levelOrder(struct node *root) // TC - O(N) | SC - O(N)
{
    vector<vector<int>> ans;
    if (root == NULL)
        return ans;
    queue<node *> q;
    q.push(root);
    while (!q.empty())
    {
        int size = q.size();
        vector<int> level;
        for (int i = 0; i < size; i++)
        {
            node *nd = q.front();
            q.pop();
            if (nd->left != NULL)
                q.push(nd->left);
            if (nd->right != NULL)
                q.push(nd->right);
            level.push_back(nd->data);
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);

    rec_preorder(root);
    cout << endl;
    rec_inorder(root);
    cout << endl;
    rec_postorder(root);
    cout << endl;

    vector<vector<int>> arr = levelOrder(root);
    for (int i = 0; i < arr.size(); i++)
    {
        for (int j = 0; j < arr[i].size(); j++)
        {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    // or
    for (auto iter : arr)
    {
        for (auto it : iter)
        {
            cout << it << " ";
        }
        cout << endl;
    }

    return 0;
}
/*
                1
            2       3
        4       5
            6
*/