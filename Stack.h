#ifndef STACK_H
#define STACK_H

struct Node
{
    char data;
    Node* next;
    Node(int val);
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