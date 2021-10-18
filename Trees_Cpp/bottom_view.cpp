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

vector<int> bottom_view(node *root)
{
    vector<int> ans;
    map<int,int>mpp;
    queue<pair<node*,int>>q;
    if(root == NULL) return ans;
    q.push({root,0});
    while(!q.empty())
    {
        node * nd = q.front().first;
        int v = q.front().second;
        
        q.pop();

        mpp[v] = nd->data;// for bottom view we directly overwrite the value to reach the end of each line.

        if(nd->left)
        {
            q.push({nd->left,v-1});
            
        }

        if(nd->right)
        {
            q.push({nd->right,v+1});
            
        }
    }

    for(auto it:mpp)
    {
        ans.push_back(it.second);
    }
    return ans;
}
int main()
{
    node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->right->right = new node(7);
    root->left->right = new node(5);
    root->right->left = new node(6);
    root->left->right->left = new node(8);
    root->left->right->right = new node(9);
    vector<int> ans = bottom_view(root);
    for (auto i : ans)
    {
        cout << i << " ";
    }
    return 0;
}