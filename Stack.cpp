#include <iostream>
#include "Stack.h"

using namespace std;

// Constructor
Node::Node(int val)
{
    data = val;
    next = nullptr;
}
Stack::Stack()
{
    top = nullptr;
}

bool Stack::isEmpty()
{
    return top == nullptr;
}

void Stack::push(int ID)
{
    Node* newNode = new Node(ID);
    Node* temp = top;
    newNode->next = top;
    top = newNode;
}

int Stack::pop()
{
    if (isEmpty())
    {
        cout << "No more actions" << endl;
        return -1;
    }
    Node* temp = top;
    int value = temp->data;

    top = top->next;
    delete temp;

    return value;
}

int Stack::peek()
{
    if (top != nullptr)
        return top->data;
    else
        return -1;
}

// Display undo history
void Stack::display()
{
    if (isEmpty())
    {
        cout << "Stack: Empty" << endl;
        return;
    }

    cout << "Stack: ";

    Node* current = top;

    while (current != nullptr)
    {
        cout << current->data;

        if (current->next != nullptr)
        {
            cout << " -> ";
        }

        current = current->next;
    }

    cout << endl;
}

// Destructor
Stack::~Stack()
{
    while (top != nullptr)
    {
        Node* temp = top;
        top = top->next;
        delete temp;
    }
}