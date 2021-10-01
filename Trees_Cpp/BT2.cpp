/*
                1
            2       3
        4       5
            6
    */
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

vector<int> iter_preorder(struct node *root) // TC - O(N) | SC - O(N)
{
    vector<int> preorder;
    if (root == NULL)
    {
        return preorder;
    }
    stack<node *> st;
    st.push(root);
    while (!st.empty())
    {
        node *nd = st.top();
        st.pop();
        preorder.push_back(nd->data);
        if (nd->right != NULL)
        {
            st.push(nd->right);
        }
        if (nd->left != NULL)
        {
            st.push(nd->left);
        }
    }
    return preorder;
}

vector<int> iter_inorder(struct node *root) // TC - O(N) | SC - O(N)
{
    stack<node *> st;
    vector<int> inorder;
    struct node *nd = root;
    while (true)
    {
        if (nd != NULL)
        {
            st.push(nd);
            nd = nd->left;
        }
        else
        {
            if (st.empty())
                break;
            nd = st.top();
            st.pop();
            inorder.push_back(nd->data);
            nd = nd->right;
        }
    }
    return inorder;
}

stack<node *> iter_postorder_2_stack(struct node *root) // TC - O(N) | SC - O(N)
{
    stack<node *> first;
    stack<node *> second;
    first.push(root);
    while (!first.empty())
    {
        node *nd = first.top();
        first.pop();
        second.push(nd);
        if (nd->left != NULL)
        {
            first.push(nd->left);
        }
        if (nd->right != NULL)
        {
            first.push(nd->right);
        }
    }
    return second;
}

vector<int> iter_postorder_1_stack(struct node *root) // TC - O(N) | SC - O(N)
{
    stack<node *> st;
    node *cur = root;
    vector<int> postorder;
    while (cur != NULL || !st.empty())
    {
        if (cur != NULL)
        {
            st.push(cur);
            cur = cur->left;
        }
        else
        {
            node *temp = st.top()->right;
            if (temp == NULL)
            {
                temp = st.top();
                st.pop();
                postorder.push_back(temp->data);
                while (!st.empty() && temp == st.top()->right)
                {
                    temp = st.top();
                    st.pop();
                    postorder.push_back(temp->data);
                }
            }
            else
            {
                cur = temp;
            }
        }
    }
    return postorder;
}

int main()
{
    struct node *root = new node(1);
    root->left = new node(2);
    root->right = new node(3);
    root->left->left = new node(4);
    root->left->right = new node(5);
    root->left->right->left = new node(6);

    // vector<int> arr = iter_preorder(root);
    // for (auto iter : arr)
    // {
    //     cout << iter << " ";
    // }
    // cout << endl;

    // vector<int> arr = iter_inorder(root);
    // for (auto iter : arr)
    // {
    //     cout << iter << " ";
    // }
    // cout << endl;

    // stack<node *> st = iter_postorder_2_stack(root);
    // while (!st.empty())
    // {
    //     cout << (st.top())->data << " ";
    //     st.pop();
    // }
    // cout << endl;

    // vector<int> arr = iter_postorder_1_stack(root);
    // for (auto it : arr)
    // {
    //     cout << it << " ";
    // }
    // cout << endl;
    return 0;
}