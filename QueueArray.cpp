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
    bool isEmpty()
    {
        return count==0;
    }
    bool isFull()
    {
        return count==size;
    }
    void push(int val)
    {
        if(isFull())
        {
            cout<<"Queue is full."<<endl;
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
    Queue q1(5);
    q1.push(1);
    q1.display();
    q1.push(2);
    q1.display();
    q1.push(3);
    q1.display();
    q1.push(4);
    q1.display();
    q1.push(5);
    q1.display();
    cout<<q1.dequeue()<<endl;
    q1.display();
    return 0;
}