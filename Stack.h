#ifndef STACK_H
#define STACK_H

struct Node
{
    int data;
    Node* next;
};

class Stack
{
private:
    Node* top;

public:
    Stack();

    void push(int actionID);
    int pop();
    int peek();

    bool isEmpty();

    void display();

    ~Stack();
};

#endif