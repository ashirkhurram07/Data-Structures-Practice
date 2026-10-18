#include<iostream>
using namespace std;
class node
{
    int data;
    node* left;
    node* right;

    node(int val)
    {
        data=val;
        left=right=nullptr;
    }
    
    node* insert(node* root,int val)
    {
        if(root==nullptr)
        {
            node* nn=new node(val);
            return nn;
        }
        else if(val>root->data)
        {
            root->right=insert(root->right,val);
        }
        else if(val<root->data)
        root->left=insert(root->left,val);

        else return root;
    }
    node* deleteNode(node* root,int val)
    {
        if(root==nullptr)
        {
            return nullptr;
        }
        else if(val>root->data)
        {
            root->right=deleteNode(root->right,val);
        }
        else if(val<root->data)
        {
            root->left=deleteNode(root->left,val);
        }
        else
        {
            if(root->left==nullptr)
            {
                node* temp=root->right;
                delete root;
                return temp;
            }
            else if(root->right==nullptr)
            {
                node* temp=root->left;
                delete root;
                return temp;
            }
            else
            {
                node* temp=root->right;
                while(temp->left!=nullptr)
                temp=temp->left;
                root->data=temp->data;
                root->right=deleteNode(root->right,temp->data);
            }
        }
    }
    bool search(node* root,int val)
    {
        if(root==nullptr)
        {
            return false;
        }
        if(root->data==val)
        {
            return true;
        }
        else if(root->data<val)
        {
            search(root->right,val);
        }
        else
        search(root->left,val);


    }
};
int main()
{
    return 0;
}