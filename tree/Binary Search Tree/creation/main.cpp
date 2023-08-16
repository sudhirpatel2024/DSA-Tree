#include <bits/stdc++.h>
using namespace std;

class node{

  public:
      int data;
      node* left;
      node* right;

      node(int data){
        this->data=data;
        this->left=NULL;
        this->right=NULL;
      }

     
};

node *insertAtBST(node *root, int data)
{

      if (root == NULL)
      {
        node *root = new node(data);
        return root;
      }

      if (data < root->data)
      {
        root->left = insertAtBST(root->left, data);
      }
      else
      {
        root->right = insertAtBST(root->right, data);
      }
      return root;
}

void takeInput(node *&root)
{
      int d;
      cin >> d;

      while (d != -1)
      {
        root = insertAtBST(root, d);
        cin >> d;
      }
}

void levelOrderTraversal(node *root)
{
      queue<node *> q;
      q.push(root);
      q.push(NULL);

      while (!q.empty())
      {
        node *temp = q.front();

        q.pop();

        if (temp == NULL)
        {
            cout << endl;
            if (!q.empty())
            {
                q.push(NULL);
            }
        }
        else
        {
            cout << temp->data << " ";
            if (temp->left)
            {
                q.push(temp->left);
            }
            if (temp->right)
            {
                q.push(temp->right);
            }
        }
      }
}

int main(){


    node* root=NULL;
    cout<<"insert The data"<<endl;
    takeInput(root);
    cout<<"print the BST"<<endl;
    levelOrderTraversal(root);

      return 0;
}