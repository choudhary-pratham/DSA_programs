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

vector<vector<int>> vertical_t(node *root)
{
    vector<vector<int>> ans;
    map<int, map<int, multiset<int>>> nodes;
    queue<pair<node *, pair<int, int>>> q;
    if (root == NULL)
    {
        return ans;
    }
    q.push({root, {0, 0}});
    while (!q.empty())
    {
        node *nd = q.front().first;
        int x = q.front().second.first;
        int y = q.front().second.second;
        nodes[x][y].insert(nd->data);
        q.pop();
        if (nd->left)
        {
            q.push({nd->left, {x - 1, y + 1}});
        }
        if (nd->right)
        {
            q.push({nd->right, {x + 1, y + 1}});
        }
    }

    for (auto p : nodes)
    {
        vector<int> col;
        for (auto q : p.second)
        {
            col.insert(col.end(), q.second.begin(), q.second.end());
        }
        ans.push_back(col);
    }
    return ans;
}
int main()
{
    node* root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(10);
    root->left->right = new node(10);
    root->right->left = new node(9);
    root->left->left->right = new node(5);
    root->left->left->right->right = new node(6);
    vector<vector<int>>ans = vertical_t(root);
    for(auto i:ans)
    {
        for(auto j : i)
        {
            cout<<j<<" ";
        }
        cout<<endl;
    }
    return 0;
}