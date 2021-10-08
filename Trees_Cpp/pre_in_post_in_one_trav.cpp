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
        left = left;
        right = right;
    }
};
vector<int> one_traversal(node *root)// TC- O(N) , SC - O(N)
{
    vector<int> pre, in, post;
    stack<pair<node *, int>> st;
    if (root == NULL)
        return pre;
    st.push({root, 1});
    while (!st.empty())
    {
        auto it = st.top();
        st.pop();
        if (it.second == 1)
        {
            pre.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->left != NULL)
            {
                st.push({it.first->left, 1});
            }
        }
        else if (it.second == 2)
        {
            in.push_back(it.first->data);
            it.second++;
            st.push(it);
            if (it.first->right != NULL)
            {
                st.push({it.first->right, 1});
            }
        }
        else
        {
            post.push_back(it.first->data);
        }
    }
    // return pre;
    // return in;
    return post;
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
    vector<int> arr = one_traversal(root);
    for (auto it : arr)
    {
        cout << it << " ";
    }
    cout << endl;
    return 0;
}