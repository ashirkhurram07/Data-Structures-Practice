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
            if(loc==1){ insertAtHead(data);return;}
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
            for(int i=1;i<loc&&(i==1||temp!=tail->next);i++)
            temp=temp->next;
            if(temp!=tail->next)
            {
                nn->next=temp;
                nn->prev=temp->prev;
                nn->prev->next=nn;
                temp->prev= nn;
                return;
            }
            else
            {
                cout<<"Value not found."<<endl;
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
            while(temp!=tail->next&&temp->data!=val)
            temp=temp->next;
        
            if(temp!=tail->next)
            {
                nn->next=temp;
                nn->prev=temp->prev;
                nn->prev->next=nn;
                temp->prev=nn;
                return;
            }
            else
                {
                    cout<<"Value not found."<<endl;
                    return;
                }
        }
    }
    void insertAfterValue(int data, int val)
    {
        if(isEmpty())
        {
            cout<<"The list is empty"<<endl;
            return;
        }
        Node* temp=tail;
        Node* nn=createNode(data);
        if(temp->data==val)
        {
            insertAtTail(data);
        }
        else
        {
            temp=temp->next;
            while(temp!=tail&&temp->data!=val)
            temp=temp->next;
            if(temp!=tail)
            {
                nn->next=temp->next;
                nn->prev=temp;
                nn->next->prev=nn;
                temp->next=nn;
            }
            else
            {
                cout<<"Value not found."<<endl;
                return;
            }
        }
    }
    void deleteAtHead()
    {
        if(isEmpty())
        {
            cout<<"List is already empty."<<endl;
            return;
        }
        else
        {
            tail->next=tail->next->next;
            delete tail->next->prev;
            tail->next->prev=tail;
        }
    }
    void deleteAtTail()
    {
        if(isEmpty())
        {
            cout<<"List is already empty."<<endl;
            return;
        }
        else
        {
            tail=tail->prev;
            deleteAtHead();
        }
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"The list is empty"<<endl;
            return;
        }
        Node* temp=tail->next;
        do
        {
            cout<<temp->data<<"<-->";
            temp=temp->next;
        } while (temp!=tail->next);
        
    }
};
int main()
{
    DCLL ll;
    ll.insertAtHead(10);
    ll.insertAtTail(20);
    ll.display();
    return 0;
}