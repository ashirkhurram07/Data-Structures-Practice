#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node* prev;

    Node(int data)
    {
        this->data=data;
        next=this;
        prev=this;
    }
};
class DCLL
{
    public:
    Node* tail;
    DCLL()
    {
        tail=nullptr;
    }
    bool isEmpty()
    {
        return tail==nullptr;
    }
    Node* createNode(int data)
    {
        Node* newNode=new Node(data);
        return newNode;
    }
    void insertAtHead(int data)
    {
        Node * nn=createNode(data);
        if(isEmpty())
        {
            tail=nn;
        }
        else
        {
            nn->next=tail->next;
            nn->prev=tail;
            tail->next->prev=nn;
            tail->next=nn;
        }
    }
    void insertAtTail(int data)
    {
        Node* nn=createNode(data);
        if(isEmpty())
        {
            tail=nn;
            return;
        }
        else
        {
            nn->next=tail->next;
            nn->prev=tail;
            tail->next->prev=nn;
            tail->next=nn;
            tail=nn;
            return;
        }
    }
    void insertAtLoc(int data,int loc)
    {
        if(isEmpty())
        {
            cout<<"List is Empty"<<endl;
            return;
        }
        if(loc==1)
        {
            insertAtHead(data);
        }
        else
        {
            Node* nn=createNode(data);
            Node* temp=tail->next;
            for(int i=1;i<loc&&temp!=tail;i++)
            temp=temp->next;
            if(temp!=tail)
            {
                nn->next=temp;
                nn->prev=temp->prev;
                nn->prev->next=nn;
                temp->prev= nn;
                return;
            }
        }
    }
    void insertBeforeValue(int data,int val)
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        Node* temp=tail->next;
        Node* nn=createNode(data);
        if(temp->data==val)
        {
            insertAtHead(data);
        }
        else
        {
            temp=temp->next;
            while(temp!=tail&&temp->data!=val)
            temp=temp->next;
        }
        if(temp!=tail)
        {
            nn->next=temp;
            nn->prev=temp->prev;
            nn->prev->next=nn;
            temp->prev=nn;
            return;
        }
    }
    
};
int main()
{
    return 0;
}