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
int main()
{
    return 0;
}