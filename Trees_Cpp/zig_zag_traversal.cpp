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

vector<vector<int>> zztrav(node *root)
{
    vector<vector<int>> ans;
    int flag = 0;
    queue<node *> q;
    if (root == NULL)
        return ans;

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
            {
                q.push(nd->left);
            }
            if (nd->right != NULL)
            {
                q.push(nd->right);
            }
            level.push_back(nd->data);
        }
        if (flag % 2 != 0)
            reverse(level.begin(), level.end());
        flag++;
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->right->right = new node(7);
    vector<vector<int>> ans = zztrav(root);
    for (auto iter : ans)
    {
        for (auto it : iter)
        {
            cout << it << " ";
        }
        cout << endl;
    }
    return 0;
}