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
        if (flag == 0)
        {
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
            flag = 1;
        }
        else if(flag == 1)
        {
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
            reverse(level.begin(),level.end());
            flag = 0;
        }
        ans.push_back(level);
    }
    return ans;
}

int main()
{
    struct node *root = new node(-10);
    root->left = new node(9);
    root->right = new node(20);
    root->right->left = new node(15);
    root->right->right = new node(7);
    root->right->left->left = new node(22);
    root->right->right->right = new node(-6);
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