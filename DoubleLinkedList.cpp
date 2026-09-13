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
        else
        {
            nn->prev=tail;
            tail->next=nn;
            tail=nn;
        }
    }
    void insertAtLoc(int data,int loc)
    {
		Node* newNode=createNode(data);
        if(loc==1)
        {
          insertAtHead(data);
        }
        else
        {
			Node* temp=head;
            for(int i=1;i<loc&&temp!=tail;i++)
			temp=temp->next;
			if(temp!=tail)
			{
				newNode->next=temp;
				newNode->prev=temp->prev;
				newNode->prev->next=newNode;
				newNode->next->prev=newNode;
			}
			if(temp==tail)
			{
				delete newNode;
				insertAtTail(data);
			}
			else cout<<"Location doesn't exist"<<endl;
        }
    }
};
int main()
{

}
