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


void createfromlevelOrder(node* & root){
  queue<node*>q;
  cout << "Enter data for root" << endl;
  int data;
  cin >> data;
  root = new node(data);
  q.push(root);
 

  while(!q.empty()){
    node* temp=q.front();
    q.pop();

    cout<<"enter left node for "<<temp->data<<"  ";
    int ldata;
    cin>>ldata;

    if(ldata!=-1){
        temp->left=new node(ldata);
        q.push(temp->left); 
    }

    cout << "enter right node for " << temp->data<<"  ";
    int rdata;
    cin >> rdata;

    if (rdata != -1)
    {
        temp->right = new node(rdata);
        q.push(temp->right);
    }
  }
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
    createfromlevelOrder(root);  

    cout << "print lot: ";
    postorder(root);
  

   return 0;
}