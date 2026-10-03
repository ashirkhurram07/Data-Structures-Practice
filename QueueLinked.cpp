#include<iostream>
using namespace std;
class Node
{
    public:
    int data;
    Node* next;
    Node(int val)
    {
        data=val;
        next=this;
    }
};
class Queue
{
    Node* rear;
    public:
    Queue()
    {
        rear=nullptr;
    }
    bool isEmpty()
    {
        return rear==nullptr;
    }
    void enqueue(int val)
    {
        Node* newNode=new Node(val);
        if(isEmpty())
        {
            rear=newNode;
            rear->next=newNode;
        }
        else
        {
            newNode->next=rear->next;
            rear->next=newNode;
            rear=newNode;
        }

    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout<<"Nothing to dequeue, queue is empty."<<endl;
            return -1;
        }
        Node* temp=rear->next;
        int val=temp->data;
        if(temp==rear)
        {
            rear=nullptr;
        }
        else
        {
            rear->next=temp->next;
        }
        delete temp;
        return val; 
    }
    void display()
    {
        Node* temp=rear->next;
        do
        {
            cout<<temp->data<<"->";
            temp=temp->next;
        } while (temp!=rear->next);
        cout<<"end"<<endl;
    }
    ~Queue()
    {
        while(!isEmpty())
        {
            Node* temp=rear->next;   // front node
            if(temp==rear)           // only one node
            {
                rear=nullptr;
            }
            else
            {
                rear->next=temp->next;
            }
            delete temp;
        }
    }
};
int main()
{
    Queue q1;
    q1.enqueue(10);
    q1.enqueue(20);
    q1.enqueue(30);
    q1.display();
    q1.dequeue();
    q1.display();
    q1.dequeue();
    q1.display();
    q1.enqueue(40);
    q1.display();
    return 0;
}