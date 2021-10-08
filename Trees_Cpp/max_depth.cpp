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
int depth_max_rec(node *root) // using recursion, TC - O(height of the tree), SC - O(N)
{
    if (root == NULL)
    {
        return 0;
    }
    int lh = depth_max_rec(root->left);
    int rh = depth_max_rec(root->right);
    return 1 + max(lh, rh);
}

int depth_max_iter(node *root)// using level o traversal method --> TC - O(N) , SC - O(N)
{
    int count = 0;
    if(root == NULL) return 0;
    queue<node*>q;
    q.push(root);
    while(!q.empty())
    {
        int size = q.size();
        for(int i=0;i<size;i++)
        {
            node * nd = q.front();
            q.pop();
            if(nd->left!=NULL)
            {
                q.push(nd->left);
            }
            if(nd->right!=NULL)
            {
                q.push(nd->right);
            }
        }
        count++;
    }
    return count;
}
int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);
    /*
                1
            2       3
        4       5
            6
    */
    // int result = depth_max_rec(root);
    int result = depth_max_iter(root);
    cout << result << endl;
    return 0;
}