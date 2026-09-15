#include<iostream>
using namespace std;
class Node{
    public:
    int data;
    Node* next;

};
class CircularLinkedList
{
    public:
    Node* tail;

    CircularLinkedList()
    {
        tail=NULL;
    }
    Node* createNode(int val)
    {
        Node* newNode=new Node();
        newNode->data=val;
        newNode->next=newNode;
        return newNode;
    }
    bool isEmpty()
    {
        return tail==NULL;
    }
    void insertAtHead(int val)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            tail=nn;
        }
        else
        {
            nn->next=tail->next;
            tail->next=nn;
        }
    }
    void insertAtEnd(int val)
    {
        Node* nn=createNode(val);
        if(isEmpty())
        {
            tail=nn;
        }
        else
        {
            nn->next=tail->next;
            tail->next=nn;
            tail=nn;
        }
    }
    void insertAtLocation(int val,int loc)
    {
        if(isEmpty())
        {
            if(loc!=1)
            {
                cout<<"Invalid index."<<endl;
                return;
            }
            Node* nn=createNode(val);
            tail=nn;
        }
        else
        {
            if(loc==1)
            {
                insertAtHead(val);
                return;
            }
            else if(loc<1)
            {
                cout<<"Invalid index..."<<endl;
                
            }
            else 
            {
                Node* nn=createNode(val);
                Node* temp=tail->next;
                for(int i=1;i<loc-1&&temp!=tail;i++)
                {
                    temp=temp->next;

                }
                if(temp!=tail)
                {
                    nn->next=temp->next;
                    temp->next=nn;
                }
                else if(temp==tail)
                {
                    insertAtEnd(val);
                }
                else
                {
                    cout<<"Invaid index"<<endl;
                    delete nn;
                }
                return;
            }
        }
    }
    void insertBeforeValue(int data,int val)
    {
        Node* nn=createNode(data);
        if(isEmpty())
        {
            tail=nn;
        }
        else
        {
            Node* temp=tail->next;
            if(temp->data==val)
            {
                nn->next=tail->next;
                tail->next=nn;
            }
            else
            {
                while(temp!=tail&&temp->next->data!=val)
                {
                    temp=temp->next;
                }
                if(temp==tail)
                {
                    cout<<"Value not found.."<<endl;
                    delete nn;
                    return;
                }
                nn->next=temp->next;
                temp->next=nn; 
            }
        }
    }
    void insertAfterValue(int data,int val)
    {
        if(isEmpty())
        {
            cout<<"The list is empty..."<<endl;
            return;
        }
        Node* temp=tail;
        Node* nn=createNode(data);
        if(tail->data==val)
        {
            nn->next=temp->next;
            temp->next=nn;
            tail=nn;
        }
        else
        {
            temp=temp->next;
            while(temp!=tail&&temp->data!=val)
            {
                temp=temp->next;
            }
            if(temp==tail)
            {
                cout<<"Value not found"<<endl;
                delete nn;
                return;
            }
            nn->next=temp->next;
            temp->next=nn;
        }
    }
    void deleteAtHead()
    {
        if(isEmpty())
        {
            cout<<"List is already empty..."<<endl;
            return;
        }
        else if(tail->next==tail)
        {
            delete tail;
            tail=nullptr;
            return;
        }
        else
        {
            Node* temp=tail->next;
            tail->next=temp->next;
            delete temp;
        }
    }
    void deleteAtEnd()
    {
        if(isEmpty())
        {
            cout<<"List is already empty..."<<endl;
            return;
        }
        else if(tail->next==tail)
        {
            delete tail;
            tail=nullptr;
            return;
        }
        else
        {
            Node* temp=tail->next;
            while(temp->next!=tail)
            {
                temp=temp->next;
            }
            Node* temp2=temp->next;
            temp->next=temp2->next;
            delete temp2;
            tail=temp;
            return;

        }
    }
    void deleteAtLoc(int loc)
    {
        if(isEmpty())
        {
            cout<<"The list is already empty..."<<endl;
            return;
        }
        else if(loc==1)
        {
            deleteAtHead();
        }
        else if(loc<1)
        {
            cout<<"Invalid index"<<endl;
            return;
        }
        else
        {
            Node* temp=tail->next;
            for(int i=1;i<loc-1&&temp!=tail;i++)
            {
                temp=temp->next;
            }
            if(temp->next==tail)
            {
                deleteAtEnd();
                return;
            }
            else 
            {
                Node* temp2=temp->next;
                temp->next=temp2->next;
                delete temp2;
                return;
            }
            cout<<"Invalid index..."<<endl;
        }
    }
    void display()
    {
        if(isEmpty())
        {
            cout<<"List is already empty."<<endl;
            return;
        }
        else
        {
            Node* temp=tail->next;
            do
            {
                cout<<temp->data<<"->";
                temp=temp->next;
            } while (temp!=tail->next);
            cout<<"end reached"<<endl;
            return;
        }
    }
};
int main()
{
    CircularLinkedList cll;
    cll.display();
    cll.insertAtHead(10);
    cll.insertAtHead(20);
    cll.insertAtHead(30);
    cll.insertAtHead(40);
    cll.display();
    return 0;
}