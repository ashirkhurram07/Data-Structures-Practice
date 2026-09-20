#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node()
    {
        next=nullptr;
    }
};
class Linkedlist
{
    Node* head;
    public:
    Linkedlist()
    {
        head=nullptr;
    }
    bool isEmpty()
    {
        return head==nullptr;
    }
    Node* createNode(int val)
    {
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=nullptr;
        return newNode;
    }

    void insertAtHead(int val)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            head=nn;
            return;
        }
        else
        {
            nn->next=head;
            head=nn;
        }
    }
    void insertAtEnd(int val)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            head=nn;
            return;
        }
        else
        {
            Node* temp=head;
            while(temp->next!=nullptr)
            {
                temp=temp->next;
            }
            temp->next=nn;
        }
    }
    void insertAtLocation(int val,int loc)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            head=nn;
        }
        else if(loc==1)
        {
            insertAtHead(val);
        }
        else
        {
            Node* temp=head;
            bool flag=false;
            for(int i=1;i<loc-1;i++)
            {
                temp=temp->next;
                if(temp==NULL)
                {
                    flag=true;
                    cout<<"Error Message"<<endl;
                }
            }
            if(flag==false)
            {
                nn->next=temp->next;
                temp->next=nn;
            }
        }
    }
    int get(int index)
    {
        if(isEmpty())
        {
            cout<<"The list is empty."<<endl;
            return -1;
        }
        else if(index==0)
        {
            cout<<"This is one-based indexing."<<endl;
            return -1;
        }
        else if(index<0)
        {
            cout<<"Index cannot be negative."<<endl;
            return -1;
        }
        Node* temp=head;
        for(int i=1;i<index;i++)
        {
            if(temp->next==nullptr)
            {
                cout<<"Index out of list"<<endl;
                return -1;
            }
            temp=temp->next;
        }
        return temp->data;
    }
    void insertBeforeValue(int data,int val)
    {
        Node* nn=createNode(data);
        if(isEmpty())
        {
            head=nn;
        }
        else
        {
            Node* temp=head;
            if(temp->data==val)
            {
                insertAtHead(data);
            }
            else
            {
                while(temp->next!=NULL&&temp->next->data!=val)
                {
                    temp=temp->next;
                }
                if(temp->next!=nullptr)
                {
                    nn->next=temp->next;
                    temp->next=nn;
                }
                else
                {
                    cout<<"Error..."<<endl;
                }
            }
        }
    }
    void insertAfterValue(int data,int val)
    {
        Node* nn=createNode(data);
        if(isEmpty())
        {
            head=nn;
        }
        else
        {
            Node* temp=head;
            if(temp->data==val)
            {
                insertAtEnd(data);
            }
            else
            {
                while(temp!=NULL&&temp->data!=val)
                {
                    temp=temp->next;
                }
                if(temp->next!=nullptr)
                {
                    nn->next=temp->next;
                    temp->next=nn;
                }
                else
                {
                    cout<<"Error..."<<endl;
                }
            }
        }
    }
    void deleteAtHead()
    {
        if(isEmpty())
        {
            cout<<"The list is already empty"<<endl;
            return;
        }
        Node* temp=head;
        head=head->next;
        temp->next=NULL;
        delete temp;
    }
    void deleteAtEnd()
    {
        if(isEmpty())
        {
            cout<<"The list is already empty"<<endl;
            return;
        }
        if(head->next==NULL)
        {
            delete head;
            head=NULL;
            return;
        }
        Node* temp=head;
        while(temp->next->next!=NULL)
        {
            temp=temp->next;
        }
        delete temp->next;
        temp->next=NULL;
    }
    void deleteLocation(int loc)
    {
        if(isEmpty())
        {
            cout<<"The list is already empty."<<endl;
            return;
        }
        else if(loc==1)
        {
            deleteAtHead();
        }
        else
        {
            Node* temp=head;
            for(int i=1;i<loc-1&&temp->next!=NULL;i++)
            {
                temp=temp->next;
            }
            if(temp->next!=NULL)
            {
                Node* temp2=temp->next;
                temp->next=temp->next->next;
                delete temp2;
            }
            else
            {
                cout<<"Error."<<endl;
            }
        }
    }
    void deleteAtValue(int val)
    {
        if(isEmpty())
        {
            cout<<"List is already empty"<<endl;
            return;
        }
        else
        {
            Node* temp=head;
            if(temp->data==val)
            {
                deleteAtHead();
                return;
            }
            else
            {
                while(temp->next!=NULL&&temp->next->data!=val)
                {
                    temp=temp->next;
                }
                if(temp->next!=NULL)
                {
                    Node* temp2=temp->next;
                    temp->next=temp->next->next;
                    delete temp2;
                }
                else
                {
                    cout<<"Value not found..."<<endl;
                    return;
                }
            }
        }
    }
    void sortList()
    {
        if(isEmpty())
        {
            cout<<"List is empty"<<endl;
            return;
        }
        else
        {
            Node* temp=head;
            while(temp->next!=NULL)
            {
                Node* temp2=temp;
                while(temp2->next!=NULL)
                {
                    if(temp->data>temp2->data)
                    {
                        int var;
                        var=temp->data;
                        temp->data=temp2->data;
                        temp2->data=var;
                    }
                    temp2=temp2->next;
                }
                temp=temp->next;
            }
        }
    }
    void display()
    {
        Node* temp=head;
        while(temp!=NULL)
        {
            cout<<temp->data<<" ";
            temp=temp->next;
        }

    }
    void removeNthNode(int n)
    {
        if(isEmpty())
        {
            cout<<"List is empty."<<endl;
            return;
        }
        Node* fast=head;
        for(int i=0;i<n;i++)
        {
            if(fast==nullptr)
            {
                cout<<"n is greater than list."<<endl;
                return;
            }
            fast=fast->next;
        }
        if(fast==nullptr)
        {
            Node* nodeToDelete=head;
            head=head->next;
            delete nodeToDelete;
            return;
        }
        Node* slow=head;
        while(fast->next!=nullptr)
        {
            fast=fast->next;
            slow=slow->next;
        }
        Node* temp=slow->next;
        slow->next=slow->next->next;
        delete temp;
    }
};
int main()
{
    Linkedlist ll;

    ll.insertAtHead(15);
    ll.insertAtHead(12);
    ll.insertAtHead(13);
    ll.insertAtHead(19);
    ll.insertAtHead(20);
    ll.insertAtHead(45);
    ll.display();
    cout<<endl;
    ll.removeNthNode(3);
    ll.display();
}

    