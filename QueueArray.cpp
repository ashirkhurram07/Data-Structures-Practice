//Implementing queue using array keeping it circular
#include<iostream>
using namespace std;
class Queue
{
    private:
    int size;
    int* array;
    int front;
    int rear;
    int count;

    public:
    Queue(int s)
    {
        size=s;
        array=new int[s];
        front=rear=-1;
        count=0;
    }
    int getSize()
    {
        return size;
    }
    void resize(int s)
    {
        int *newArray=new int[s];
        for(int i=0;i<size;i++)
        {
            newArray[i]=array[i];
        }
        delete array;
        array=newArray;
        size=s;
    }
    bool isEmpty()
    {
        return count==0;
    }
    bool isFull()
    {
        return count==size;
    }
    void enqueue(int val)
    {
        if(isFull())
        {
            char ch;
            cout<<"Queue is full. Do you want to resize "<<endl;
            cin>>ch;
            if(ch=='y'||ch=='Y')
            {
                resize(size*2);
            }
            else
            return;
        }
        if(isEmpty())
        {
            front=0;
            rear=0;
            array[rear]=val;
        }
        else
        {
            rear=(rear+1)%size;
        }
        array[rear]=val;
        count++;
    }
    int dequeue()
    {
        if(isEmpty())
        {
            cout<<"Queue is empty, nothing to dequeue.";
            return -1;
        }
        int val=array[front];
        front=(front+1)%size;
        count--;
        if(count==0)
        {
            front=rear=-1;
        }
        return val;
    }
    void display()
    {
        int j=1;
        int i=front;
        for(int k=0;k<count;k++)
        {
            cout<<"Element "<<j<<": "<<array[k]<<endl;
            j++;
            i=(i+1)%size;
        }
        cout<<endl;
    }
};
int main()
{
    int choice=-1;
    Queue q1(5);
    while(choice)
    {
        cout<<"\nEnter: "<<endl;
        cout<<"1. Add "<<endl;
        cout<<"2. Delete"<<endl;
        cout<<"3. Print"<<endl;
        cout<<"4. Resize"<<endl;
        cout<<"0. Exit"<<endl;
        cin>>choice;
        switch(choice)
        {
            case 0:
            break;
            
            case 1:
            int val;
            cout<<"Enter value: ";
            cin>>val;
            q1.enqueue(val);
            break;

            case 2:
            cout<<q1.dequeue();
            break;

            case 3:
            cout<<"The Queue is: "<<endl;
            q1.display();
            break;

            case 4:
            q1.resize(q1.getSize()*2);
            break;

            default:
            cout<<"Invalid..."<<endl;
            break;
        }
    }
    return 0;
}