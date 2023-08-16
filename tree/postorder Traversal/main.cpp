#include <bits/stdc++.h>
using namespace std;

class node
{
public:
    int data;
    node *left;
    node *right;

    node(int d)
    {
        this->data = d;
        this->left = NULL;
        this->right = NULL;
    }
};

node *buildTree(node *root)
{

    cout << "enter the data : " << endl;
    int data;
    cin >> data;

    root = new node(data);

    if (data == -1)
    {
        return NULL;
    }

    cout << "enter the data for inserting data in left  node : " << data << endl;
    root->left = buildTree(root->left);
    cout << "enter the data for inserting data in right  node : " << data << endl;
    root->right = buildTree(root->right);
    return root;
}

void postorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    
    postorder(root->left);
    postorder(root->right);
    cout << root->data << " ";
}

int main()
{

    node *root = NULL;

    root = buildTree(root);
    cout << "print postorder traversal: ";
    postorder(root);

    return 0;
}