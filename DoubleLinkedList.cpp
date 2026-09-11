#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* prev;
    Node* next;

    Node()
    {
        prev=next=NULL;
    }
};
class DLL
{
    public:
    Node* head;
    Node* tail;

    DLL()
    {
        head=tail=nullptr;
    }
    bool isEmpty()
    {
        return head==nullptr&&tail==nullptr;
    }
    Node *createNode(int val)
    {
        Node* newNode=new Node();
        newNode->data=val;
        return newNode;
    }
    void insertAtHead(int val)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            head=nn;
            tail=nn;
        }
        else
        {
            nn->next=head;
            head->prev=nn;
            head=nn;
        }
    }
    void insertAtTail(int val)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            head=nn;
            tail=nn;
        }
    }
};
int main()
{

}